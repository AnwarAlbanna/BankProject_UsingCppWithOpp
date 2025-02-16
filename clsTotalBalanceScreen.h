#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"

class clsTotalBalanceScreen:protected clsScreen
{
private :

   static void PrintListToTotalBalance(clsBankClient Client) {
        cout << "|" << left << setw(15) << Client.AccountNumber();
        cout << "|" << left << setw(30) << Client.FullName();
        cout << "|" << left << setw(15) << Client.AccountBalance;
    }


public :



  

  static  void ShowTotalBalanceScreen() {
      system("cls");
      _DrawScreenHeader("\tTotle Balance Screen");

        vector<clsBankClient> vClient = clsBankClient::GetClientsList();
        cout << "\n-------------------------------------------------------------------------------------\n";
        cout << "\n\t\t\t\Total Balance List (" << vClient.size() << ") Client(s)\n";
        cout << "-------------------------------------------------------------------------------------\n";
        cout << "|" << left << setw(15) << "Account Number";
        cout << "|" << left << setw(30) << " Full Name ";
        cout << "|" << left << setw(15) << "Account Balance";
        cout << "\n-------------------------------------------------------------------------------------\n";
        if (vClient.size() == 0)
        {
            cout << "The Data is Not avalible Sorry!";
        }
        else {

            for (clsBankClient& C : vClient) {
                PrintListToTotalBalance(C);
                cout << endl;
            }
        }


        cout << "\n-------------------------------------------------------------------------------------\n";
        double TotalBalance = clsBankClient::GetTotalBalances();
        cout << "\n\t\t\t\tTotal Balance is (" << TotalBalance << ")" << endl;
        cout << "\n\t\t" << clsUtil::NumberToText(TotalBalance) << endl;
    }
};

