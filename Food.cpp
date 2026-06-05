/* Citation and Sources...
Final Project Milestone m53:
Module: Food
Filename:   Food.cpp
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
#include "Food.h"
#include "Menu.h"
#include "Utils.h"
#include <cstring>
#include <cstdlib>
using namespace std;

namespace seneca {

    Food::Food() {
        m_ordered = false;
        m_child = false;
        m_customize = nullptr;
    }

    Food::Food(const Food& F) {
        m_customize = nullptr;
        *this = F;
    }

    Food& Food::operator=(const Food& F) {
        if (this != &F) {
            Billable::operator=(F);
            m_ordered = F.m_ordered;
            m_child = F.m_child;
            ut.alocpy(m_customize, F.m_customize);
        }
        return *this;
    }

    Food::~Food() {
        delete[] m_customize;
    }

    ostream& Food::print(ostream& ostr) const {
        ostr.fill('.');
        ostr.setf(ios::left, ios::adjustfield);
        ostr.width(28);
        ostr << (const char*)(*this);

        if (!ordered()) ostr << ".....";
        else if (m_child) ostr << "Child";
        else ostr << "Adult";

        ostr.fill(' ');
        ostr.setf(ios::right, ios::adjustfield);
        ostr << fixed;
        ostr.precision(2);
        ostr.width(7);
        ostr << price();

        if (&ostr == &cout && m_customize) {
            ostr << " >> " << m_customize;
        }

        return ostr;
    }

    bool Food::order() {
        Menu m("Food Size Selection", "Back", 3);
        m << "Adult" << "Child";

        size_t sel = m.select();

        delete[] m_customize;
        m_customize = nullptr;

        if (sel == 1) {
            m_ordered = true;
            m_child = false;
        }
        else if (sel == 2) {
            m_ordered = true;
            m_child = true;
        }
        else {
            m_ordered = false;
            return false;
        }

        cout << "Special instructions\n> ";
        char temp[1000];
        cin.getline(temp, 1000);

        if (temp[0] != '\0') {
            ut.alocpy(m_customize, temp);
        }

        return true;
    }

    bool Food::ordered() const {
        return m_ordered;
    }

    ifstream& Food::read(ifstream& file) {
        char line[256]{};

        if (file.getline(line, 256)) {
            char* comma = strchr(line, ',');
            if (comma) {
                *comma = '\0';
                Billable::name(line);
                Billable::price(atof(comma + 1));
                m_ordered = false;
                m_child = false;
                delete[] m_customize;
                m_customize = nullptr;
            }
        }

        return file;
    }

    double Food::price() const {
        if (ordered() && m_child) {
            return Billable::price() / 2;
        }
        return Billable::price();
    }

}