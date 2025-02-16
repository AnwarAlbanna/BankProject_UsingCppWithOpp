#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsUtil.h"

using namespace std;
class clsUpdateClientScreen : protected clsScreen
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
    static void Print(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }

public:
   static void ShowUpdateClientScreen() {

        system("cls");
        string Title = "\t  Update Client Screen ";
        _DrawScreenHeader(Title);
        string AccountNumber = "";
        cout << "Please Enter Account to Clinet : ";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber)) {
            cout << "the AccountNubmer is not found, Choose anther one: ";
            AccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient Client = clsBankClient::Find(AccountNumber);
        Print(Client);
        cout << "\n___ Update Clietn ___\n";
        cout << "_____________________\n";
        ReadClientInfo(Client);
        cout << "_____________________\n";
        clsBankClient::enSaveResults SaveResult;
        SaveResult = Client.Save();
        if (SaveResult == clsBankClient::enSaveResults::svSucceeded) {
            cout << "the AccountNumber Updated Succefuly ";
          Print(Client);
        }
        else {
            cout << "the AccountNumber Can't Updated -:) ";
        }
    }

};

