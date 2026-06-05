/* Citation and Sources...
Final Project Milestone m53:
Module: main
Filename:   main.cpp
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
#include "Ordering.h"
#include "Menu.h"

using namespace std;
using namespace seneca;

int main() {
    Ordering app("drinks.csv", "foods.csv");

    if (!app) {
        cout << "Failed to open data files or the data files are corrupted!" << endl;
        return 1;
    }

    Menu mainMenu("Seneca Restaurant ", "End Program");
    mainMenu << "Order"
        << "Print Bill"
        << "Start a New Bill"
        << "List Foods"
        << "List Drinks";

    Menu orderMenu("Order Menu", "Back to main menu", 1, 3);
    orderMenu << "Food" << "Drink";

    Menu exitMenu("You have bills that are not saved, are you sue you want to exit?", "No");
    exitMenu << "Yes";

    bool done = false;

    while (!done) {
        switch (mainMenu.select()) {
        case 1: {
            bool back = false;
            while (!back) {
                switch (orderMenu.select()) {
                case 1:
                    app.orderFood();
                    break;
                case 2:
                    app.orderDrink();
                    break;
                case 0:
                    back = true;
                    break;
                }
            }
            break;
        }
        case 2:
            break;
        case 3:
            break;
        case 4:
            app.listFoods();
            break;
        case 5:
            app.listDrinks();
            break;
        case 0:
            if (app.hasUnsavedBill()) {
                if (exitMenu.select() == 1) {
                    done = true;
                }
            }
            else {
                done = true;
            }
            break;
        }
    }

    return 0;
}