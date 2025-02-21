#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include "clsUser.h"
#include "clsDate.h"
#include "clsScreen.h"


using namespace std;
class clsLoginRegisterScreen : protected clsScreen
{
private:
    static void PrintLogRegisterRecordLine(clsUser::stLoginRegisterRecord LogReg)
    {

        cout << setw(8) << left << "" << "| " << setw(20) << left << LogReg.DateTime;
        cout << "| " << setw(20) << left << LogReg.UserName;
        cout << "| " << setw(10) << left << LogReg.Password;
        cout << "| " << setw(10) << left << LogReg.Permission;
    }
public:
    static void ShowLoginRegisterScreen() {
        if (!CheckAccessRights(clsUser::enPermisstion::pLoginRegister)) {
            return;
        }

        vector <clsUser::stLoginRegisterRecord> vLogRegister = clsUser::GetLogRegister();
        string Title = "\t  Login Register Screen";
        string SubTitle = "\t    (" + to_string(vLogRegister.size()) + ") Register(s).";

        _DrawScreenHeader(Title, SubTitle);


        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(20) << "Date/Time";
        cout << "| " << left << setw(20) << "UserName";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(10) << "Permeation";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vLogRegister.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsUser::stLoginRegisterRecord& LogReg : vLogRegister)
            {

                PrintLogRegisterRecordLine(LogReg);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
    }


};

