#pragma once
#include <iostream>
#include <iomanip>
#include "clsUtil.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsTotalBalanceScreen.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferListScreen.h"

using namespace std;
class clsTransactionScreen  : protected clsScreen
{
private:
    enum enTransactionsOptions {
        eDeposit = 1, eWithdraw = 2, eShowTotalBalance = 3,
        eTransfare=4,eTransferList =5, eMainMenue = 6
    };
    static short _ReadTransactionsOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidate::ReadIntNumberBetween(1,6, "Enter Number between 1 to 6 ? ");
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

    static void _ShowTransfareScreen()
    {
       // cout << "\n Transfare Screen Will be here...\n";
        clsTransferScreen::ShowTransferScreen();
    }
    static void _ShowTransfareListScreen()
    {
        // cout << "\n Transfare Screen Will be here...\n";
        clsTransferListScreen::ShowTransferLogScreen();
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

        case enTransactionsOptions::eTransfare:
            system("cls");
            _ShowTransfareScreen();
            _GoBackToTransactionScreen();
            break;


        case enTransactionsOptions::eTransferList:
            system("cls");
            _ShowTransfareListScreen();
            _GoBackToTransactionScreen();
            break;

        case enTransactionsOptions::eMainMenue:
        {
            _GoBackToTransactionScreen();
        }
        }
    }


     
  public:

    static void ShowTransactionsMenue()
    {
        if (!CheckAccessRights(clsUser::enPermisstion::pTransaction)) {
            return;
        }

        system("cls");
        _DrawScreenHeader("\t\tTransactions Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tTransactions Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit Screen.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw Screen.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balance Screen.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer Screen.\n";
        cout << setw(37) << left << "" << "\t[5] Transfer List Screen.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue Screen.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromMainMenueOption((enTransactionsOptions)_ReadTransactionsOption());
    }


};

