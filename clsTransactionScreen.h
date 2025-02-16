#pragma once
#include <iostream>
#include <iomanip>
#include "clsUtil.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsTotalBalanceScreen.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"

using namespace std;
class clsTransactionScreen  : protected clsScreen
{
private:
    enum enTransactionsOptions {
        eDeposit = 1, eWithdraw = 2, eShowTotalBalance = 3,
        eMainMenue = 4
    };
    static short _ReadTransactionsOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 4]? ";
        short Choice = clsInputValidate::ReadIntNumberBetween(1, 8, "Enter Number between 1 to 4? ");
        return Choice;
    }

    static  void _GoBackToTransactionScreen()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Transaction Screen ...\n";

        system("pause>0");
        ShowTransactionsMenue();
    }

    static void _ShowDepositScreen()
    {
        //cout << "\nDeposit Screen Will be here...\n";
        clsDepositScreen::ShowDepositScreen();
    }
    static void _ShowWithdrawScreen()
    {
        //cout << "\nWithdraw Screen Will be here...\n";
        clsWithdrawScreen::ShowWithdrawScreen();
    }
    static void _ShowTotalBalanceScreen()
    {
       // cout << "\nTotalBalance Screen Will be here...\n";
        clsTotalBalanceScreen::ShowTotalBalanceScreen();
    }
    static void _PerfromMainMenueOption(enTransactionsOptions TransactionsOptions)
    {
        switch (TransactionsOptions)
        {

        case enTransactionsOptions::eDeposit:
        {
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionScreen();
            break;
        }
        case enTransactionsOptions::eWithdraw:
            system("cls");
            _ShowWithdrawScreen();
            _GoBackToTransactionScreen();
            break;

        case enTransactionsOptions::eShowTotalBalance:
            system("cls");
            _ShowTotalBalanceScreen();
            _GoBackToTransactionScreen();
            break;
        case enTransactionsOptions::eMainMenue:
        {
        }
        }

    }


     
  public:

    static void ShowTransactionsMenue()
    {

        system("cls");
        _DrawScreenHeader("\t\tTransactions Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tTransactions Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit Screen.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw Screen.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balance Screen.\n";
        cout << setw(37) << left << "" << "\t[4] Main Menue Screen.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromMainMenueOption((enTransactionsOptions)_ReadTransactionsOption());
    }


};

