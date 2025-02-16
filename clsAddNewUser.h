#pragma once
#include <iostream >
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsUser.h"

using namespace std;
class clsAddNewUser : protected clsScreen
{
private:
	static void ReadUsersInfo(clsUser &User) {
		cout << "\n Enter FirstName: " ;
		User.FirstName = clsInputValidate::ReadString();

		cout << "\n Enter LastName: ";
		User.LastName = clsInputValidate::ReadString();

		cout << "\n Enter Email: ";
		User.Email = clsInputValidate::ReadString();

		cout << "\n Enter Phone: ";
		User.Phone = clsInputValidate::ReadString();


		cout << "\n Enter Password: ";
		User.Password = clsInputValidate::ReadString();

		cout << "\n Enter Permission : ";
		User.Permeations = _GetPermission();
	}
	static short _GetPermission() {
		short Permission = 0;
		char Answer = 'n';
		cout << "Do you want gave all permission [y/n] :";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y') {
			return clsUser::enPermisstion::pAll;
		}

		else {
			cout << "Do you want gave AddNewClient permission [y/n] :";
			cin >> Answer;
			if (Answer == 'Y' || Answer == 'y') {
				Permission+=(short) clsUser::enPermisstion::pAddNewClient;
			}
			cout << "Do you want gave Delete permission [y/n] :";
			cin >> Answer;
			if (Answer == 'Y' || Answer == 'y') {
				Permission += (short)clsUser::enPermisstion::pDeleteClient;
			}
			cout << "Do you want gave Update permission [y/n] :";
			cin >> Answer;
			if (Answer == 'Y' || Answer == 'y') {
				Permission += (short)clsUser::enPermisstion::pUpdateClient;
			}
			cout << "Do you want gave Find  permission [y/n] :";
			cin >> Answer;
			if (Answer == 'Y' || Answer == 'y') {
				Permission += (short)clsUser::enPermisstion::pFindClinet;
			}
			cout << "Do you want gave Transaction permission [y/n] :";
			cin >> Answer;
			if (Answer == 'Y' || Answer == 'y') {
				Permission += (short)clsUser::enPermisstion::pTransaction;
			}
			cout << "Do you want gave Manage Users permission [y/n] :";
			cin >> Answer;
			if (Answer == 'Y' || Answer == 'y') {
				Permission += (short)clsUser::enPermisstion::pManagUsers;
			}

			cout << "Do you want gave Logout permission [y/n] :";
			cin >> Answer;
			if (Answer == 'Y' || Answer == 'y') {
				Permission += (short)clsUser::enPermisstion::pLogout;
			}

			return Permission;
		}

		
	}
public :

	static void ShowAddNewUser() {
		system("cls");
		_DrawScreenHeader("\t\t Add New User ");
		string UserName = "";
		cout << " Please Added UserName ?";
		UserName = clsInputValidate::ReadString();
		while (clsUser::IsUserExist(UserName)) {
			cout << "the UserName is Alredy Use ,choose anther one :";
			UserName = clsInputValidate::ReadString();
		}
		clsUser NewUser = clsUser::GetAddNewUserObject(UserName);
		ReadUsersInfo(NewUser);
		clsUser::enSaveResults SaveResult;
		SaveResult = NewUser.Save();
		switch (SaveResult) {
		case clsUser::enSaveResults::svSucceeded:
		{
			cout << "the User Added is Succeeded ";
			break;
		}
		case clsUser::enSaveResults::svFaildUserNameExists:
		{
			cout << "the User Can't Added try anther time Because UserName is Exist. ";
			break;
		}
		case clsUser::enSaveResults::svFaildEmptyObject:
		{
			cout << "the User Can't Added try anther time Because EmptyObject. ";
			break;
		}
		}
	}

};

