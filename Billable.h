/* Citation and Sources...
Final Project Milestone m53:
Module: Billable
Filename:   Billable.h
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

#ifndef SENECA_BILLABLE_H
#define SENECA_BILLABLE_H

#include <iostream>
#include <fstream>

namespace seneca {

    class Billable {
        char* m_name{};
        double m_price{};

    protected:
        void price(double value);
        void name(const char* name);

    public:
        Billable();
        Billable(const Billable& B);
        Billable& operator=(const Billable& B);
        virtual ~Billable();

        virtual double price() const;

        virtual std::ostream& print(std::ostream& ostr = std::cout) const = 0;
        virtual bool order() = 0;
        virtual bool ordered() const = 0;
        virtual std::ifstream& read(std::ifstream& file) = 0;

        operator const char* () const;
    };

    double operator+(double money, const Billable& B);
    double& operator+=(double& money, const Billable& B);

}

#endif