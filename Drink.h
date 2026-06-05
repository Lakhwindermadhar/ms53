/* Citation and Sources...
Final Project Milestone m53:
Module: Drink
Filename:   Drink.h
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

#ifndef SENECA_DRINK_H
#define SENECA_DRINK_H

#include "Billable.h"

namespace seneca {

    class Drink : public Billable {
        char m_size{};

    public:
        std::ostream& print(std::ostream& ostr = std::cout) const;
        bool order();
        bool ordered() const;
        std::ifstream& read(std::ifstream& file);
        double price() const;
    };

}

#endif