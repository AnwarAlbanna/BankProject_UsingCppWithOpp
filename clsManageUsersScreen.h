#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUsersListScreen.h"
#include "clsAddNewUser.h"
#include "clsUpdateUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsFindUserScreen.h"


using namespace std;
class clsManageUsersScreen : protected clsScreen
{
private:
	enum enManageUsersOptions{eShowUser=1,eAddUser=2,eUpdateUser=3,
							  eDeleteUser=4,eFindUser=5,eMainMenue=6};

	static short _ReadManageUserOptions() {
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
		short Choice = clsInputValidate::ReadIntNumberBetween(1, 6, "Enter Number between 1 to 6? ");
		return Choice;
	}

	static void _GoBackToManageUsers() {
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Manage Users...\n";
		system("pause>0");
		ManageUsers();
	}

	static void _ShowListUsersScreen() {
		/*cout << "List Users Screen will be here .....";*/
		clsUsersListScreen::ShowUsersList();
	}

	static void _ShowAddUsersScreen() {
		clsAddNewUser::ShowAddNewUser();
		
	}

	static void _ShowUpdateUsersScreen() {
		//cout << "Update Users Screen will be here .....";
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}

	static void _ShowDeleteUsersScreen() {
		//cout << "Delete Users Screen will be here .....";
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}

	static void _ShowFindUsersScreen() {
		//cout << "Find Users Screen will be here .....";
		clsFindUserScreen::ShowFindUserScreen();
	}

	static void _PerfromManageUsersScreen(enManageUsersOptions ManageUsersOption) {
		switch (ManageUsersOption) {

		case enManageUsersOptions::eShowUser:
		{
			system("cls");
			_ShowListUsersScreen();
			_GoBackToManageUsers();
			break;
		}
		case enManageUsersOptions::eAddUser:
		{
			system("cls");
			_ShowAddUsersScreen();
			_GoBackToManageUsers();
			break;
		}
		case enManageUsersOptions::eUpdateUser:
		{
			system("cls");
			_ShowUpdateUsersScreen();
			_GoBackToManageUsers();
			break;
		}
		case enManageUsersOptions::eDeleteUser:
		{
			system("cls");
			_ShowDeleteUsersScreen();
			_GoBackToManageUsers();
			break;
		}
		case enManageUsersOptions::eFindUser:
		{
			system("cls");
			_ShowFindUsersScreen();
			_GoBackToManageUsers();
			break;
		}
		case enManageUsersOptions::eMainMenue:
		{
			// will be go back Main Menue .....
		}
		}
	}

public:
	static void ManageUsers() {
		if (!CheckAccessRights(clsUser::enPermisstion::pManagUsers)) {
			return;
		}
		system("cls");
		_DrawScreenHeader("\tManage User Screen ");
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tManage User Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Show Users List.\n";
		cout << setw(37) << left << "" << "\t[2] Add New User.\n";
		cout << setw(37) << left << "" << "\t[3] Update User.\n";
		cout << setw(37) << left << "" << "\t[4] Delete User .\n";
		cout << setw(37) << left << "" << "\t[5] Find User.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		_PerfromManageUsersScreen((enManageUsersOptions)_ReadManageUserOptions());

	}


};

