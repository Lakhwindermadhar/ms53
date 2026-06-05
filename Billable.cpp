/* Citation and Sources...
Final Project Milestone m53:
Module: Billable
Filename:   Billable.cpp
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

#include "Billable.h"
#include "Utils.h"
using namespace std;

namespace seneca {

    Billable::Billable() {
        m_name = nullptr;
        m_price = 0;
    }

    Billable::Billable(const Billable& B) {
        m_name = nullptr;
        *this = B;
    }

    Billable& Billable::operator=(const Billable& B) {
        if (this != &B) {
            ut.alocpy(m_name, B.m_name);
            m_price = B.m_price;
        }
        return *this;
    }

    Billable::~Billable() {
        delete[] m_name;
    }

    void Billable::price(double value) {
        m_price = value;
    }

    void Billable::name(const char* nm) {
        ut.alocpy(m_name, nm);
    }

    double Billable::price() const {
        return m_price;
    }

    Billable::operator const char* () const {
        return m_name;
    }

    double operator+(double money, const Billable& B) {
        return money + B.price();
    }

    double& operator+=(double& money, const Billable& B) {
        money += B.price();
        return money;
    }

}