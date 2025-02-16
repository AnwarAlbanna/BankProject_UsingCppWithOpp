#pragma once
#include "clsBankClient.h"
#include "clsUtil.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iostream>
#include <iomanip>
using namespace std;
class clsAddNewClient :protected clsScreen
{
private:
   static void ReadClientInfo(clsBankClient& Client) {
        cout << "\nFirstName is :";
        Client.FirstName = clsInputValidate::ReadString();

        cout << "\nLastName is :";
        Client.LastName = clsInputValidate::ReadString();

        cout << "\nPhone is :";
        Client.Phone = clsInputValidate::ReadString();

        cout << "\nEmail is :";
        Client.Email = clsInputValidate::ReadString();

        cout << "\nPinCode is :";
        Client.PinCode = clsInputValidate::ReadString();

        cout << "\nAccount Balance is :";
        Client.AccountBalance = clsInputValidate::ReadDblNumber();
    }

public :

   static void ShowAddNewClient() {
       system("cls");
       string Title = "\t  Add Client Screen ";
       _DrawScreenHeader(Title);

        string AccountNumber = "";
        cout << " Please Added AccountNumber ?";
        AccountNumber = clsInputValidate::ReadString();
        while (clsBankClient::IsClientExist(AccountNumber)) {
            cout << "the AccountNumber is Alredy Use ,choose anther one :";
            AccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);
        ReadClientInfo(NewClient);
        clsBankClient::enSaveResults SaveResult;
        SaveResult = NewClient.Save();
        switch (SaveResult) {
        case clsBankClient::enSaveResults::svSucceeded:
        {
            cout << "the Client Added is Succeeded ";
            break;
        }
        case clsBankClient::enSaveResults::svFaildAccountNumberExists:
        {
            cout << "the Client Can't Added try anther time Because AccountNumber is Exist. ";
            break;
        }
        case clsBankClient::enSaveResults::svFaildEmptyObject:
        {
            cout << "the Client Can't Added try anther time Because EmptyObject. ";
            break;
        }
        }

    }





};

