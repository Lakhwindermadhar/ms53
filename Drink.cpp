/* Citation and Sources...
Final Project Milestone m53:
Module: Drink
Filename:   Drink.cpp
Version 1.0
Author: Lakhwinder Madhar, StNo: 123024259, Email: lmadhar@myseneca.ca
Revision History
-----------------------------------------------------------
Date           Reason
2026/03/30     Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Clearly indicate which part of the code was provided as help,
by whom, or from what source it was obtained.
-----------------------------------------------------------*/

#include "Drink.h"
#include "Menu.h"
#include <cstring>
#include <cstdlib>
using namespace std;

namespace seneca {

    ostream& Drink::print(ostream& ostr) const {
        ostr.fill('.');
        ostr.setf(ios::left, ios::adjustfield);
        ostr.width(28);
        ostr << (const char*)(*this);

        if (!ordered()) ostr << ".....";
        else if (m_size == 'S') ostr << "SML..";
        else if (m_size == 'M') ostr << "MID..";
        else if (m_size == 'L') ostr << "LRG..";
        else if (m_size == 'X') ostr << "XLR..";

        ostr.fill(' ');
        ostr.setf(ios::right, ios::adjustfield);
        ostr << fixed;
        ostr.precision(2);
        ostr.width(7);
        ostr << price();

        return ostr;
    }

    bool Drink::order() {
        Menu m("Drink Size Selection", "Back", 3);
        m << "Small" << "Medium" << "Larg" << "Extra Large";

        size_t sel = m.select();

        if (sel == 1) m_size = 'S';
        else if (sel == 2) m_size = 'M';
        else if (sel == 3) m_size = 'L';
        else if (sel == 4) m_size = 'X';
        else m_size = 0;

        return m_size != 0;
    }

    bool Drink::ordered() const {
        return m_size != 0;
    }

    ifstream& Drink::read(ifstream& file) {
        char line[256]{};

        if (file.getline(line, 256)) {
            char* comma = strchr(line, ',');
            if (comma) {
                *comma = '\0';
                Billable::name(line);
                Billable::price(atof(comma + 1));
                m_size = 0;
            }
        }

        return file;
    }

    double Drink::price() const {
        double base = Billable::price();

        if (!ordered() || m_size == 'L') return base;
        if (m_size == 'S') return base * 0.5;
        if (m_size == 'M') return base * 0.75;
        if (m_size == 'X') return base * 1.5;

        return base;
    }

}