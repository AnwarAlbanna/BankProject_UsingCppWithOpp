#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"


using namespace std;
class clsUpdateUserScreen
{
private:

	static void _ReadUserInfo(clsUser& User) {
		cout << "\n FirstName is :";
		User.FirstName = clsInputValidate::ReadString();

		cout << "\n LastName is :";
		User.LastName = clsInputValidate::ReadString();

		cout << "\n Email is :";
		User.Email = clsInputValidate::ReadString();

		cout << "\n Phone is :";
		User.Phone = clsInputValidate::ReadString();

		cout << "\n Password is :";
		User.Password = clsInputValidate::ReadString();

		cout << "\n Permission is :";
		User.Permeations = _ReadPermissionUserToSet();
	}
	static int _ReadPermissionUserToSet() {
		int Permission = 0;
		char Answer = 'n';

		cout << "\n Do you want to gave all Permissions :";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y') {
			return -1;
		}
		cout << "\nDo you want to gave some Permissions :";

		cout << "\n Do you Acceess to show List Client ? y/n :";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y') {
			Permission += clsUser::enPermisstion::pShowClients;
		}

		cout << "\n Do you Acceess to Add New Client ? y/n :";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y') {
			Permission += clsUser::enPermisstion::pAddNewClient;
		}

		cout << "\n Do you Acceess to Delete Client ? y/n :";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y') {
			Permission += clsUser::enPermisstion::pDeleteClient;
		}

		cout << "\n Do you Acceess to Update Client ? y/n :";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y') {
			Permission += clsUser::enPermisstion::pUpdateClient;
		}

		cout << "\n Do you Acceess to Find Client ? y/n :";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y') {
			Permission += clsUser::enPermisstion::pFindClinet;
		}

		cout << "\n Do you Acceess to Transactions  ? y/n :";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y') {
			Permission += clsUser::enPermisstion::pTransaction;
		}

		cout << "\n Do you Acceess to Manage User  ? y/n :";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y') {
			Permission += clsUser::enPermisstion::pManagUsers;
		}

		return Permission;
	}
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
	static void ShowUpdateUserScreen() {
		cout << "\n Enter the User that want to Update :";
		string UserName = clsInputValidate::ReadString();
		while (!clsUser::IsUserExist(UserName)) {
			cout << "\nThe UserName is Not Found ,choos anther one :";
			UserName = clsInputValidate::ReadString();
		}
		clsUser User = clsUser::Find(UserName);
		_ReadUserInfo(User);
		clsUser::enSaveResults SaveResults;
		SaveResults = User.Save();
		switch (SaveResults) {
		case clsUser::enSaveResults::svSucceeded:
		{
			cout << "\n---------- Updated Successfuly----------- ";
			break;
		}
		case clsUser::enSaveResults::svFaildUserNameExists:
		{
			cout << "\nNot show here ";
			break;

		}
		case clsUser::enSaveResults::svFaildEmptyObject:
		{
			cout << "\nThe Object is Empty , can't Update ";
			break;

		}
		}
	}

};