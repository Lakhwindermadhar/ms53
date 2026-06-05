/* Citation and Sources...
Final Project Milestone m53:
Module: Food
Filename:   Food.h
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

#ifndef SENECA_FOOD_H
#define SENECA_FOOD_H

#include "Billable.h"
#include <iostream>
#include <fstream>

namespace seneca {

    class Food : public Billable {
        bool m_ordered{};
        bool m_child{};
        char* m_customize{};

    public:
        Food();
        Food(const Food& F);
        Food& operator=(const Food& F);
        ~Food();

        std::ostream& print(std::ostream& ostr = std::cout) const;
        bool order();
        bool ordered() const;
        std::ifstream& read(std::ifstream& file);
        double price() const;
    };

}

#endif