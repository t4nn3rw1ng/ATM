/// @author Tanner Wing
/// @file ATM.cpp
/// @version 2019-05-30
/// @brief This program simulates a user's interaction with an ATM.


#include <iostream>
#include <cstdlib>

using namespace std;

void printHeader();
bool checkPIN(int, const int&);
void printExitMessage();


int main()
{
    // Variables
    const unsigned short ACCOUNT_PIN = 1204,
                         CHECKING = 1,
                         SAVINGS = 2;

    unsigned short option, withdraw, account, pin, attempts = 2, count = 0;
    double checkingBalance, savingsBalance;
    bool retry = false, exit = false, success = false;

    // Generate Account Balances
    srand(time(nullptr));
    checkingBalance = rand() % 5000;
    savingsBalance = rand() % 10000;

    // Data Manipulation
    printHeader();

    // Check PIN
    do
    {
        cout << "Enter PIN:  ";
        cin >> pin;

        if (checkPIN(pin, ACCOUNT_PIN))
        {
            success = true;
            cout << endl;
        }
        else if (!cin || (!checkPIN(pin, ACCOUNT_PIN) && attempts > 0))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid PIN, try again." << endl
                 << "You have " << attempts << " remaining." << endl << endl;
        }
        else if (!cin || (!checkPIN(pin, ACCOUNT_PIN) && attempts == 0))
            cout << "Maximum attempts reached." << endl << endl;

        attempts--;
        count++;
    }
    while (count < 3 && !success);

    // If valid pin, proceed
    while (!exit && success)
    {
        cout << "====== MAIN MENU ======" << endl
             << "1) Withdraw Cash" << endl
             << "2) Deposit Cash" << endl
             << "3) View Account Balances" << endl
             << "4) Cancel Transaction" << endl << endl;

        cout << "Option:  ";
        cin >> option;
        if (!cin)
        {
            cin.clear();
            cin.ignore(1000, '\n');
        }
        cout << endl;

        switch (option)
        {
            case 1:
                cout << "Which account do you want to withdraw from?" << endl
                     << "1. Checking" << endl
                     << "2. Savings" << endl << endl;

                do
                {
                    cout << "Option:  ";
                    cin >> account;
                    cout << endl;

                    switch (account) {
                        case CHECKING:
                            cout << "Checking balance: $" << checkingBalance
                                 << endl << endl;
                            retry = false;
                            break;

                        case SAVINGS:
                            cout << "Savings balance: $" << savingsBalance
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

                cout << "How much do you want to withdraw? "
                     << "(Enter multiples of $20, up to $1000)" << endl;

                // Enter withdraw amount
                do
                {
                    cout << "$";
                    cin >> withdraw;
                    cout << endl;

                    if (withdraw % 20 == 0 && withdraw <= 1000)
                    {
                        retry = false;
                    }
                    else if (withdraw % 20 != 0 || withdraw > 1000)
                    {
                        cout << "Invalid entry, enter an "
                             << "amount in multiples of $20, up to $1000." << endl;
                        retry = true;
                    }

                    cin.clear();
                    cin.ignore(1000, '\n');
                }
                while (retry);

                // If withdraw amount is valid, deduct amount from balance
                if (account == CHECKING)
                {
                    if (withdraw > checkingBalance)
                    {
                        cout << "Overdraft protection: Not enough funds in account."
                             << endl << endl;
                    }
                    else if (withdraw < checkingBalance)
                    {
                        checkingBalance -= withdraw;
                        cout << "Cash dispensing... Please take cash." << endl << endl
                             << "Updated checking account balance: $"
                             << checkingBalance << endl << endl;
                    }
                }

                // If withdraw amount is valid, deduct amount from balance
                if (account == SAVINGS)
                {
                    if (withdraw > savingsBalance)
                    {
                        cout << "Overdraft protection: Not enough funds in account."
                             << endl << endl;
                    }
                    else if (withdraw < savingsBalance)
                    {
                        savingsBalance -= withdraw;
                        cout << "Cash dispensing... Please take cash." << endl << endl
                             << "Updated savings account balance: $"
                             << savingsBalance << endl << endl;
                    }
                }

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
                        case CHECKING:
                            cout << "Checking account balance: $" << checkingBalance
                                 << endl << endl;
                            retry = false;
                            break;

                        case SAVINGS:
                            cout << "Savings account balance: $" << savingsBalance
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
                printExitMessage();
                exit = true;
                break;

            default:
                cout << "Invalid entry, try again." << endl << endl;
                retry = true;
                break;
        }

        if (option != 4 && !retry)
        {
            cout << "Do you want to make another transaction?" << endl
                 << "1. Yes" << endl
                 << "2. No" << endl << endl;

            do
            {
                cout << "Option:  ";
                cin >> option;
                if (!cin)
                {
                    cin.clear();
                    cin.ignore(1000, '\n');
                }
                cout << endl;

                if (option == 1)
                {
                    retry = false;
                }
                else if (option == 2)
                {
                    printExitMessage();
                    retry = false;
                    exit = true;
                }
                else
                {
                    cout << "Invalid entry." << endl;
                    retry = true;
                }
            }
            while (retry);
        }
    }

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

bool checkPIN( int inputPIN, const int &ACCOUNT_PIN )
{
    bool retVal= false;

    if (inputPIN == ACCOUNT_PIN)
        retVal = true;

    return retVal;
}

void printExitMessage()
{
    cout << " _____________________________" << endl
         << "|                             |" << endl
         << "| Thank you, have a nice day! |" << endl
         << "|_____________________________|" << endl << endl;
}
