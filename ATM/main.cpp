/// @author Tanner Wing
/// @file ATM.cpp
/// @version 2019-05-29
/// @brief This program simulates a user's interaction with an ATM.


#include <iostream>
#include <cstdlib>

using namespace std;

void printHeader();

int main()
{
    // Variables
    unsigned short option, withdraw, account;
    double checkingBalance, savingsBalance;
    bool retry = false, exit = false;

    // Generate Account Balances
    srand(time(nullptr));
    checkingBalance = rand() % 25000;
    savingsBalance = rand() % 50000;

    // Data Manipulation
    printHeader();

    while (!exit)
    {
        cout << "====MAIN MENU====" << endl
             << "1) Withdraw Cash" << endl
             << "2) Deposit Cash" << endl
             << "3) View Account Balances" << endl
             << "4) Cancel Transaction" << endl << endl;

        cout << "Option:  ";
        cin >> option;
        cout << endl;

        switch (option) {
            case 1:
                cout << "How much do you want to withdraw? "
                     << "(Enter multiples of $20)" << endl;

                do
                {
                    cout << "$";
                    cin >> withdraw;
                    cout << endl;
                    if (withdraw % 20 != 0) {
                        cout << "Invalid entry, enter an "
                             << "amount in multiples of $20." << endl;
                        retry = true;
                    } else if (withdraw % 20 == 0)
                        retry = false;
                }
                while (retry);

                break;

            case 2:
                cout << "Please enter cash and/or checks all facing up."
                     << endl << endl;
                break;

            case 3:
                cout << "Which account do you want to view?" << endl
                     << "1. Checking" << endl
                     << "2. Savings" << endl << endl;

                do
                {
                    cout << "Option:  ";
                    cin >> account;
                    cout << endl;

                    switch (account) {
                        case 1:
                            cout << "Balance: $" << checkingBalance
                                 << endl << endl;
                            retry = false;
                            break;

                        case 2:
                            cout << "Balance: $" << savingsBalance
                                 << endl << endl;
                            retry = false;
                            break;

                        default:
                            cout << "Invalid entry." << endl << endl;
                            retry = true;
                            break;
                    }
                }
                while (retry);

                break;

            case 4:
                exit = true;
                break;

            default:
                cout << "Invalid entry, try again." << endl << endl;
                break;
        }

        if (option != 4)
        {
            cout << "Do you want to make another transaction?" << endl
                 << "1. Yes" << endl
                 << "2. No" << endl << endl;

            do
                {
                cout << "Option:  ";
                cin >> option;
                cout << endl;

                if (option == 1) {
                    retry = false;
                } else if (option == 2) {
                    retry = false;
                    exit = true;
                } else {
                    cout << "Invalid entry." << endl;
                    retry = true;
                }
            }
            while (retry);
        }
    }

    cout << "Thank you! Have a nice day!" << endl << endl;

    return 0;
}


void printHeader()
{
    cout << "\n\n         Hello! Welcome to the..." << endl
         << "   ______      ___________     ____  ___" << endl
         << "  /      \\    |           |   /    \\/   \\" << endl
         << " /    _   \\   |___     ___|  |           |" << endl
         << " |   |_|   |      |   |      |   \\   /   |" << endl
         << " |    _    |      |   |      |   |\\_/|   |" << endl
         << " |   | |   |      |   |      |   |   |   |" << endl
         << " |   | |   |      |   |      |   |   |   |" << endl
         << " |___| |___|      |___|      |___|   |___|" << endl << endl << endl;
}