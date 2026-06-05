/* Citation and Sources...
Final Project Milestone m53:
Module: Utils
Filename:   Utils.cpp
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

#include <iostream>
#include "Utils.h"
using namespace std;

namespace seneca {
    Utils ut;

    char* Utils::alocpy(const char* src) const {
        char* des{};
        return alocpy(des, src);
    }

    char* Utils::alocpy(char*& des, const char* src) const {
        delete[] des;
        des = nullptr;
        if (src) {
            des = new char[strlen(src) + 1];
            strcpy(des, src);
        }
        return des;
    }

    char* Utils::strcpy(char* des, const char* src) const {
        int i;
        for (i = 0; src[i]; i++) des[i] = src[i];
        des[i] = char(0);
        return des;
    }

    int Utils::strlen(const char* str) const {
        int len;
        for (len = 0; str[len]; len++);
        return len;
    }

    bool Utils::isspace(char ch) const {
        return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\v' || ch == '\f' || ch == '\r';
    }

    bool Utils::isspace(const char* cstring) const {
        while (cstring && isspace(*cstring)) {
            cstring++;
        }
        return cstring && *cstring == 0;
    }

    int Utils::getInt() const {
        int value{};
        bool done = false;

        while (!done) {
            char ch = cin.peek();

            if (ch == '\n') {
                cout << "You must enter a value: ";
                cin.get();
            }
            else {
                cin >> value;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Invalid integer: ";
                }
                else if (cin.get() != '\n') {
                    cin.ignore(10000, '\n');
                    cout << "Only an integer please: ";
                }
                else {
                    done = true;
                }
            }
        }

        return value;
    }

    int Utils::getInt(int min, int max) const {
        int value{};

        do {
            value = getInt();
            if (value < min || value > max) {
                cout << "Invalid value: [" << min << "<= value <=" << max << "], try again: ";
            }
        } while (value < min || value > max);

        return value;
    }

    char* Utils::makeBillFileName(char* filename, size_t billNo) const {
        char billFileName[21] = "bill_";
        size_t temp = billNo;
        int cnt = 5;
        int length;

        do {
            cnt++;
            temp /= 10;
        } while (temp > 0);

        length = cnt;

        while (billNo > 0) {
            billFileName[--cnt] = (billNo % 10) + '0';
            billNo /= 10;
        }

        if (billFileName[cnt - 1] == '\0') {
            billFileName[--cnt] = '0';
        }

        for (int i = 0; ".txt"[i]; i++) {
            billFileName[length++] = ".txt"[i];
        }

        billFileName[length] = '\0';

        strcpy(filename, billFileName);
        return filename;
    }

}