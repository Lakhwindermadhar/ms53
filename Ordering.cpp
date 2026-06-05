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

#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include "Ordering.h"
#include "Menu.h"
#include "Utils.h"

using namespace std;

namespace seneca {

    size_t Ordering::countRecords(const char* file) const {
        ifstream f(file);
        size_t count = 0;
        char line[1024];

        while (f.getline(line, 1024)) {
            count++;
        }

        return count;
    }

    Ordering::Ordering(const char* drinkFile, const char* foodFile) {
        size_t dCount = countRecords(drinkFile);
        size_t fCount = countRecords(foodFile);

        ifstream dFile(drinkFile);
        ifstream fFile(foodFile);

        if (dFile && fFile) {
            m_drinks = new Drink[dCount];
            m_foods = new Food[fCount];

            size_t i = 0;
            while (i < dCount && m_drinks[i].read(dFile)) {
                i++;
            }
            m_noOfDrinks = (unsigned)i;

            i = 0;
            while (i < fCount && m_foods[i].read(fFile)) {
                i++;
            }
            m_noOfFood = (unsigned)i;
        }
    }

    Ordering::~Ordering() {
        delete[] m_foods;
        delete[] m_drinks;

        for (unsigned i = 0; i < m_noOfBillItems; i++) {
            delete m_billItems[i];
            m_billItems[i] = nullptr;
        }
    }

    Ordering::operator bool() const {
        return m_foods != nullptr && m_drinks != nullptr;
    }

    unsigned Ordering::noOfBillItems() const {
        return m_noOfBillItems;
    }

    bool Ordering::hasUnsavedBill() const {
        return m_noOfBillItems > 0;
    }

    void Ordering::listFoods() const {
        cout << "List Of Avaiable Meals" << endl;
        cout << "========================================" << endl;
        for (unsigned i = 0; i < m_noOfFood; i++) {
            m_foods[i].print() << endl;
        }
        cout << "========================================" << endl;
    }

    void Ordering::listDrinks() const {
        cout << "List Of Avaiable Drinks" << endl;
        cout << "========================================" << endl;
        for (unsigned i = 0; i < m_noOfDrinks; i++) {
            m_drinks[i].print() << endl;
        }
        cout << "========================================" << endl;
    }

    void Ordering::orderFood() {
        Menu m("Food Menu", "Back to Order", 2);

        for (unsigned i = 0; i < m_noOfFood; i++) {
            m << (const char*)m_foods[i];
        }

        size_t sel = m.select();

        if (sel != 0) {
            Food* item = new Food(m_foods[sel - 1]);
            if (item->order()) {
                m_billItems[m_noOfBillItems++] = item;
            }
            else {
                delete item;
            }
        }
    }

    void Ordering::orderDrink() {
        Menu m("Drink Menu", "Back to Order", 2);

        for (unsigned i = 0; i < m_noOfDrinks; i++) {
            m << (const char*)m_drinks[i];
        }

        size_t sel = m.select();

        if (sel != 0) {
            Drink* item = new Drink(m_drinks[sel - 1]);
            if (item->order()) {
                m_billItems[m_noOfBillItems++] = item;
            }
            else {
                delete item;
            }
        }
    }

    void Ordering::billTitle(ostream& ostr) const {
        ostr << "Bill # ";
        ostr.fill('0');
        ostr.width(3);
        ostr << m_billNo;
        ostr.fill(' ');
        ostr << " =============================" << endl;
    }

    void Ordering::printTotals(ostream& ostr, double total) const {
        double tax = total * Tax;

        ostr.setf(ios::fixed);
        ostr.precision(2);

        ostr << "                     Total:        " << total << endl;
        ostr << "                     Tax:           " << tax << endl;
        ostr << "                     Total+Tax:    " << total + tax << endl;
        ostr << "========================================" << endl;
    }

    void Ordering::printBill(ostream& ostr) const {
        double total = 0.0;

        billTitle(ostr);

        for (unsigned i = 0; i < m_noOfBillItems; i++) {
            m_billItems[i]->print(ostr) << endl;
            total += *m_billItems[i];
        }

        printTotals(ostr, total);
    }

    void Ordering::resetBill() {
        char filename[21]{};
        ut.makeBillFileName(filename, m_billNo);

        ofstream fout(filename);
        printBill(fout);

        cout << "Saved bill number " << m_billNo << endl;
        cout << "Starting bill number " << (m_billNo + 1) << endl;

        for (unsigned i = 0; i < m_noOfBillItems; i++) {
            delete m_billItems[i];
            m_billItems[i] = nullptr;
        }

        m_noOfBillItems = 0;
        m_billNo++;
    }

}