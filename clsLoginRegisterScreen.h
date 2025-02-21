#pragma once
#include <iostream>
#include <iomanip>
#include "clsUser.h"
#include "clsDate.h"
#include "clsScreen.h"

using namespace std;
class clsLoginRegisterScreen : clsScreen
{
private:
    static void PrintRegisterLogRecordLine(clsUser UserLog)
    {

        cout << setw(8) << left << "" << "| " << setw(30) << left << clsDate::GetSystemDateAndTime();
        cout << "| " << setw(12) << left << UserLog.UserName;
        cout << "| " << setw(12) << left << UserLog.Password;
        cout << "| " << setw(12) << left << UserLog.Permeations;

    }
public:
    static void ShowRegisterLoginList() {
       /* if (!CheckAccessRights(clsUser::enPermisstion::pShowClients)) {
            return;
        }*/
        vector <clsUser> vRegisterLog = clsUser::GetRegisterLogList();
        string Title = "\t  RegisterLogin List Screen";
        string SubTitle = "\t    (" + to_string(vRegisterLog.size()) + ") Login Number(s).";

        _DrawScreenHeader(Title, SubTitle);


        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(30) << "Date/Time"; 
        cout << "| " << left << setw(12) << "UserName";
        cout << "| " << left << setw(12) << "Password";
        cout << "| " << left << setw(12) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vRegisterLog.size() == 0)
            cout << "\t\t\t\tNo Register Login Available In the System!";
        else

            for (clsUser Reg : vRegisterLog)
            {

                PrintRegisterLogRecordLine(Reg);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
    }
};

