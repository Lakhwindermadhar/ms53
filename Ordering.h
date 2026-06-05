/* Citation and Sources...
Final Project Milestone m53:
Module: Ordering
Filename:   Ordering.cpp
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

#ifndef SENECA_ORDERING_H
#define SENECA_ORDERING_H

#include "Food.h"
#include "Drink.h"
#include "Billable.h"
#include "constants.h"

namespace seneca {

    class Ordering {

        unsigned m_noOfFood{};
        unsigned m_noOfDrinks{};
        unsigned m_noOfBillItems{};
        unsigned m_billNo{ 1 };

        Food* m_foods{};
        Drink* m_drinks{};
        Billable* m_billItems[MaximumNumberOfBillItems]{};

        size_t countRecords(const char* file) const;
        void billTitle(std::ostream& ostr) const;
        void printTotals(std::ostream& ostr, double total) const;

    public:
        Ordering(const char* drinkFile, const char* foodFile);
        ~Ordering();

        operator bool() const;

        unsigned noOfBillItems() const;
        bool hasUnsavedBill() const;

        void listFoods() const;
        void listDrinks() const;

        void orderFood();
        void orderDrink();

        void printBill(std::ostream& ostr) const;
        void resetBill();
    };

}

#endif