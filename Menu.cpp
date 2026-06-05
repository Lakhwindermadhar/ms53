/* Citation and Sources...
Final Project Milestone m53:
Module: Menu
Filename:   Menu.cpp
Version 1.0
Author: Lakhwinder Madhar, StNo: 123024259, Email: lmadhar@myseneca.ca
Revision History
-----------------------------------------------------------
Date           Reason
2026/03/30    Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Clearly indicate which part of the code was provided as help,
by whom, or from what source it was obtained.
-----------------------------------------------------------*/

#include "Menu.h"
using namespace std;

namespace seneca {

    MenuItem::MenuItem(const char* content, unsigned indentation, unsigned indentationSize, int row) {
        m_content = nullptr;
        m_indentation = 0;
        m_indentationSize = 0;
        m_row = -1;

        if (content && !ut.isspace(content) && indentation <= 4 && indentationSize <= 4 && row <= 99) {
            while (ut.isspace(*content)) {
                content++;
            }

            if (*content) {
                ut.alocpy(m_content, content);
                m_indentation = indentation;
                m_indentationSize = indentationSize;
                m_row = row;
            }
        }
    }

    MenuItem::~MenuItem() {
        delete[] m_content;
    }

    MenuItem::operator bool() const {
        return m_content != nullptr;
    }

    ostream& MenuItem::display(ostream& os) const {
        if (!*this) {
            os << "??????????";
        }
        else {
            for (unsigned i = 0; i < m_indentation * m_indentationSize; i++) {
                os << ' ';
            }

            if (m_row >= 0) {
                if (m_row < 10) {
                    os << ' ';
                }
                os << m_row << "- ";
            }

            os << m_content;
        }
        return os;
    }

    Menu::Menu(const char* title, const char* exitOption, unsigned indentation, unsigned indentationSize)
        : m_indentation(indentation)
        , m_indentationSize(indentationSize)
        , m_numberOfItems(0)
        , m_title(title, indentation, indentationSize)
        , m_exitOption(exitOption, indentation, indentationSize, 0)
        , m_prompt("> ", indentation, indentationSize) {
        for (unsigned i = 0; i < MaximumNumberOfMenuItems; i++) {
            m_items[i] = nullptr;
        }
    }

    Menu::~Menu() {
        for (unsigned i = 0; i < MaximumNumberOfMenuItems; i++) {
            delete m_items[i];
            m_items[i] = nullptr;
        }
    }

    Menu& Menu::operator<<(const char* menuItemContent) {
        if (m_numberOfItems < MaximumNumberOfMenuItems) {
            m_items[m_numberOfItems] = new MenuItem(menuItemContent, m_indentation, m_indentationSize, m_numberOfItems + 1);
            if (*m_items[m_numberOfItems]) {
                m_numberOfItems++;
            }
            else {
                delete m_items[m_numberOfItems];
                m_items[m_numberOfItems] = nullptr;
            }
        }
        return *this;
    }

    Menu::operator bool() const {
        return bool(m_title);
    }

    size_t Menu::select() const {
        if (m_title) {
            m_title.display() << endl;
        }

        for (unsigned i = 0; i < m_numberOfItems; i++) {
            m_items[i]->display() << endl;
        }

        m_exitOption.display() << endl;
        m_prompt.display();

        return ut.getInt(0, (int)m_numberOfItems);
    }

    size_t operator<<(ostream& ostr, const Menu& m) {
        size_t selection = 0;
        if (&ostr == &cout) {
            selection = m.select();
        }
        return selection;
    }
}