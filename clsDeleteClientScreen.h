#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;

class clsDeleteClientScreen : protected clsScreen
{
private :
   static void Print(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " <<Client.FirstName;
        cout << "\nLastName    : " <<Client.LastName;
        cout << "\nFull Name   : " <<Client.FullName();
        cout << "\nEmail       : " <<Client.Email;
        cout << "\nPhone       : " <<Client.Phone;
        cout << "\nAcc. Number : " <<Client.AccountNumber();
        cout << "\nPassword    : " <<Client.PinCode;
        cout << "\nBalance     : " <<Client.AccountBalance;
        cout << "\n___________________\n";

    }


public:

  static void ShowDeleteClientScreen() {

      system("cls");
      string Title = "\t  Delete Client Screen ";
      _DrawScreenHeader(Title);
        string AccountNumber = "";
        cout << "Please Enter AccountNumber to Deleted :";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber)) {
            cout << "The Account Number is Not Exist ,Choos anthe one:";
            AccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient Client = clsBankClient::Find(AccountNumber);
        Print(Client);
        cout << "Are You Sure Deleted the Account Number :(Y/N) :";
        char Anwser = 'n';
        cin >> Anwser;
        if (Anwser == 'Y' || Anwser == 'y') {
            if (Client.Delete())
            {
                cout << "the Deleted is Succeded ";
                Print(Client);
            }

        }
        else {
            cout << " U Can't Deleted";
        }
    }

};

