#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;
class clsTransferScreen : protected clsScreen
{
	static void _PrintClient(clsBankClient& Client) {
		cout << "\n-------------------------------------------";
		cout << "\n FullName is      : " << Client.FullName();
		cout << "\n AccountNumber is : " << Client.AccountNumber();
		cout << "\n AccountBalance is: " << Client.AccountBalance;
		cout << "\n-------------------------------------------";

	}
	static string _ReadAccountNumber(string Message) {
		cout << Message;
		return clsInputValidate::ReadString();
	}


public:
	static void ShowTransferScreen() {
		_DrawScreenHeader("\t Transfer Screen ");
		// this a Client one
		string AccountNumber = "";
		AccountNumber = _ReadAccountNumber("Please Enter Account Number Transfer From:");

		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "the AccountNumber is Not Exists, ";
			AccountNumber = _ReadAccountNumber("Please choos anther one :");
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		cout << "Card Client\n";
		_PrintClient(Client);

		// this a Client tow
		string AccountNumber2 = "";
		AccountNumber2 = _ReadAccountNumber("\nPlease Enter Account Number Transfer To:");

		while (!clsBankClient::IsClientExist(AccountNumber2) || AccountNumber2 == AccountNumber) {
			if (AccountNumber == AccountNumber2) {
				cout << "\nPlease Choos AccountNumber Different,";
				AccountNumber2 = _ReadAccountNumber("Please Enter Account Number Transfer From:");
			}
			else {
				cout << "the AccountNumber is Not Exists,";
				AccountNumber2 = _ReadAccountNumber("Please choos anther one :");
			}
			
		}
		clsBankClient Client2 = clsBankClient::Find(AccountNumber2);
		cout << "Card Client\n";
		_PrintClient(Client2);



		double Amount = 0;
		cout << "\nEnter the amount to Transfer:";
		Amount = clsInputValidate::ReadDblNumber();
		char Anwser = 'n';
		cout << "\nAre you Sure Withdraw to the Account [Y/N]: ";
		cin >> Anwser;
		if (Anwser == 'Y' || Anwser == 'y') {

			if (Client.Withdraw(Amount)) {
				cout << "\n The Transfer is Successfuly ";
				cout << "\n Card to AccountNumber" << AccountNumber;
				_PrintClient(Client);
				cout << "\n====================================================\n";
				Client2.Deposit(Amount);
				cout << "\n Card to AccountNumber" << AccountNumber2;
				_PrintClient(Client2);
			}
			else {
				cout << "can't Transfer because the Account Balance less than Amount" << endl;
				cout << "The Accout Balance is : " << Client.AccountBalance;
				cout << "\n The Amount is " << Amount;
			}
		}
		else {
			cout << "\nCan't Transfer !";
		}
	}



};

