#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;
class clsWithdrawScreen : protected clsScreen
{


	
	
	private:
		static void _PrintClient(clsBankClient& Client) {
			cout << "\n FirstName is     : " << Client.FirstName;
			cout << "\n LastName is      : " << Client.LastName;
			cout << "\n FullName is      : " << Client.FullName();
			cout << "\n Email is         : " << Client.Email;
			cout << "\n Phone is         : " << Client.Phone;
			cout << "\n AccountNumber is : " << Client.AccountNumber();
			cout << "\n PinCode is       : " << Client.PinCode;
			cout << "\n AccountBalance is: " << Client.AccountBalance;
		}
		static string _ReadAccountNumber() {
			cout << "Please Enter Account Number to Withdraw:";
			return clsInputValidate::ReadString();
		}


	public:
		static void ShowWithdrawScreen() {
			_DrawScreenHeader("\t Withdraw Screen ");
			string AccountNumber = "";
			AccountNumber = _ReadAccountNumber();

			while (!clsBankClient::IsClientExist(AccountNumber)) {
				cout << "the AccountNumber is Not Exists Please choos anther one :";
				AccountNumber = _ReadAccountNumber();
			}
			clsBankClient Client = clsBankClient::Find(AccountNumber);
			_PrintClient(Client);
			double Amount = 0;
			cout << "\nEnter the amount to Withdraw:";
			Amount = clsInputValidate::ReadDblNumber();
			char Anwser = 'n';
			cout << "\nAre you Sure Withdraw to the Account [Y/N]: ";
			cin >> Anwser;
			if (Anwser == 'Y' || Anwser == 'y') {
				
				if (Client.Withdraw(Amount)) {
					cout << "\n The Withdraw is Successfuly ";
					cout << "\n The New Balance is " << Client.AccountBalance;
				}
				else {
					cout << "can't Withdraw because the Account Balance less than Amount" << endl;
					cout << "The Accout Balance is : " << Client.AccountBalance;
					cout << "\n The Amount is " << Amount;
				}
				

			}
			else {
				cout << "\nCan't Withdraw !";
			}
		}



};

