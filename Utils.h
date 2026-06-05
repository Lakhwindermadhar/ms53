/* Citation and Sources...
Final Project Milestone m53:
Module:     Utils
Filename:   Utils.h
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

#ifndef SENECA_UTILS_H
#define SENECA_UTILS_H

namespace seneca {
    class Utils {
    public:
        char* alocpy(const char* src) const;
        char* alocpy(char*& des, const char* src) const;
        char* strcpy(char* des, const char* src) const;
        int strlen(const char* str) const;
        bool isspace(char ch) const;
        bool isspace(const char* cstring) const;
        int getInt() const;
        int getInt(int min, int max) const;

        char* makeBillFileName(char* filename, size_t billNo) const;
    };

    extern Utils ut;
}

#endif