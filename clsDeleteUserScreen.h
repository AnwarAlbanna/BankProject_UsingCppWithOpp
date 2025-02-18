#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"

using namespace std;
class clsDeleteUserScreen : protected clsScreen
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
	static void ShowDeleteUserScreen() {
		system("cls");
		_DrawScreenHeader("Delete User Screen ");
		cout << "\n Enter the UserName that You want Deleted :";
		string UserName;
		UserName = clsInputValidate::ReadString();
		while (!clsUser::IsUserExist(UserName)) {
			cout << "\n The UserName is Not Found ,Choos anther one to Deleted :";
			UserName = clsInputValidate::ReadString();
		}
		clsUser User = clsUser::Find(UserName);
		_PrintUser(User);
		cout << "\nDo You Want Delete this User [Y\N]:";
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y') {
			User.Delete();
			_PrintUser(User);
			cout << "\nthe User Deleted is Successfuly ";;
		}
		else {
			_PrintUser(User);
		}
	}

};