#pragma once
#include <iostream>
#include "clsUser.h"
#include "clsInputValidate.h"
#include  "Global.h"
#include "clsScreen.h"
#include "clsMainScreen.h"
#include "clsDate.h"
using namespace std;
class clsLoginScreen :protected clsScreen
{
 private:
	static bool _Login() {
		bool LoginFiled = false; 
		short Trail = 0;
		do {
			
			if (LoginFiled) {
				Trail++;
				cout << "\nUserName & Password is Not Correct, try anther one :";
				cout << "\nYou have " <<(3-Trail) << " Trail to Login ";
				if (Trail == 3) {
					cout << "the system is locked after login 3 trails Faild " << endl;
					return false;
				}
			}
			string UserName = "";
			string Password = "";

			cout << "\nPleas Enter UserName:";
			UserName = clsInputValidate::ReadString();

			cout << "\nPleas Enter Password:";
			Password = clsInputValidate::ReadString();

			CurrentUser = clsUser::Find(UserName, Password);
			LoginFiled = CurrentUser.IsEmpty();
			SaveRegisterLog();

		} while (LoginFiled);
		clsMainScreen::ShowMainMenue();

	}
	static void _AddDataLineToRegisterLog(string  stDataLine)
	{
		fstream MyFile;
		MyFile.open("RegisterLog.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;

			MyFile.close();
		}

	}

 public:

	static bool ShowLoginScreen() {
		system("cls");
		_DrawScreenHeader("\tLogin Screen ");
		return _Login();
	}
	static void SaveRegisterLog() {
		string S = "";
		S += clsDate::DateToString(clsDate()) + "#//#";
		S += CurrentUser.UserName + "#//#";
		S += CurrentUser.Password + "#//#";
		S +=to_string( CurrentUser.Permeations ) ;
		_AddDataLineToRegisterLog(S);
	}



};