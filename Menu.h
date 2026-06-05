/* Citation and Sources...
Final Project Milestone m53:
Module: Menu
Filename:   Menu.h
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

#ifndef SENECA_MENU_H
#define SENECA_MENU_H

#include <iostream>
#include "Utils.h"
#include "constants.h"

namespace seneca {

    class Menu;

    class MenuItem {
        friend class Menu;

        char* m_content{};
        unsigned m_indentation{};
        unsigned m_indentationSize{};
        int m_row{};

        MenuItem(const char* content = nullptr, unsigned indentation = 0, unsigned indentationSize = 0, int row = -1);
        ~MenuItem();
        MenuItem(const MenuItem&) = delete;
        MenuItem& operator=(const MenuItem&) = delete;
        operator bool() const;
        std::ostream& display(std::ostream& os = std::cout) const;
    };

    class Menu {
        unsigned m_indentation{};
        unsigned m_indentationSize{};
        unsigned m_numberOfItems{};

        MenuItem m_title;
        MenuItem m_exitOption;
        MenuItem m_prompt;
        MenuItem* m_items[MaximumNumberOfMenuItems]{};

        Menu(const Menu&) = delete;
        Menu& operator=(const Menu&) = delete;

    public:
        Menu(const char* title, const char* exitOption = "Exit", unsigned indentation = 0, unsigned indentationSize = 3);
        ~Menu();

        Menu& operator<<(const char* menuItemContent);
        size_t select() const;
        operator bool() const;
    };

    size_t operator<<(std::ostream& ostr, const Menu& m);
}

#endif