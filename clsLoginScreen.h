#pragma once
#include <iostream>
#include "clsUser.h"
#include "clsInputValidate.h"
#include  "Global.h"
#include "clsScreen.h"
#include "clsMainScreen.h"
using namespace std;
class clsLoginScreen :protected clsScreen
{
private:
	static void _Login() {
		bool LoginFiled = false;
		do {
			if (LoginFiled) {
				cout << "\nUserName & Password is Not Corect, try anther one :";
			}
			string UserName = "";
			string Password = "";

			cout << "\nPleas Enter UserName:";
			UserName = clsInputValidate::ReadString();

			cout << "\nPleas Enter Password:";
			Password = clsInputValidate::ReadString();

			CurrentUser = clsUser::Find(UserName, Password);
			LoginFiled = CurrentUser.IsEmpty();


		} while (LoginFiled);
		clsMainScreen::ShowMainMenue();

	}

public:

	static void ShowLoginScreen() {
		system("cls");
		_DrawScreenHeader("\tLogin Screen ");
		_Login();
	}
};