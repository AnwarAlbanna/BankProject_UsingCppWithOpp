#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"

using namespace std;
class clsFindUserScreen :protected clsScreen
{
private:

	static void _PrintUser(clsUser User) {
		cout << "\n--------------------------------------------------------";
		cout << "\n FirstName    :" << User.FirstName;
		cout << "\n LastName     :" << User.LastName;
		cout << "\n Email        :" << User.Email;
		cout << "\n Phone        :" << User.Phone;
		cout << "\n UserName     :" << User.UserName;
		cout << "\n Password     :" << User.Password;
		cout << "\n Permeations  :" << User.Permeations;
		cout << "\n--------------------------------------------------------";

	}
public:
	static void ShowFindUserScreen() {
		string UserName = "";
		system("cls");
		_DrawScreenHeader("Find User Screen");
		cout << "Please Enter UserName to Find:";
		UserName = clsInputValidate::ReadString();
		while (!clsUser::IsUserExist(UserName)) {
			cout << "\nThe User Name is Not Found ,choos anther one :";
			UserName = clsInputValidate::ReadString();

		}
		clsUser User = clsUser::Find(UserName);
		_PrintUser(User);
	}
};