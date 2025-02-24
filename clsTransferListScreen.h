#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include "clsBankClient.h"
#include "clsDate.h"
#include "clsScreen.h"

using namespace std;
class clsTransferListScreen :protected clsScreen
{
private:
    static void PrintTransferLogRecordLine(clsBankClient::stTransferLog LogTransfer)
    {

        cout << setw(8) << left << "" << "| " << setw(20) << left << LogTransfer.DateTime;
        cout << "| " << setw(10) << left << LogTransfer.UserNameSource;
        cout << "| " << setw(10) << left << LogTransfer.UserNameDestination;
        cout << "| " << setw(10) << left << LogTransfer.Amount;
        cout << "| " << setw(10) << left << LogTransfer.BalanceSource;
        cout << "| " << setw(10) << left << LogTransfer.BalanceDestination;
        cout << "| " << setw(10) << left << LogTransfer.User;
    }
public:
    static void ShowTransferLogScreen() {
        if (!CheckAccessRights(clsUser::enPermisstion::pLoginRegister)) {
            return;
        }

        vector <clsBankClient::stTransferLog> vLogTransfer = clsBankClient::GetTransferData();
        string Title = "\t  Transfer Register Screen";
        string SubTitle = "\t    (" + to_string(vLogTransfer.size()) + ") Register(s).";

        _DrawScreenHeader(Title, SubTitle);


        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(20) << "Date/Time";
        cout << "| " << left << setw(10) << "s.UserName";
        cout << "| " << left << setw(10) << "d.UserName";
        cout << "| " << left << setw(10) << "Amount";
        cout << "| " << left << setw(10) << "s.Balans";
        cout << "| " << left << setw(10) << "d.Balans";
        cout << "| " << left << setw(10) << "User";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vLogTransfer.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsBankClient::stTransferLog& LogTransfer : vLogTransfer)
            {

                PrintTransferLogRecordLine(LogTransfer);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
    }


};

