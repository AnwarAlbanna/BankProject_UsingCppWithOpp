#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "clsString.h"
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
using namespace std;
class clsUser : public clsPerson
{
private:
	enum enMode {
		EmptyMode = 0, UpdateMode = 1, AddNewMode = 2
	};
	enMode _Mode;
	string _UserName = "";
	string _Password = "";
	short  _Permeations = 0;

	bool _MarkedForDelete = false;

	
	static clsUser _ConvertLineToUserObject(string Line,string Seperator="#//#") {
		vector<string> vUser;
		vUser = clsString::Split(Line, Seperator);
		return clsUser(enMode::UpdateMode,vUser[0],vUser[1], vUser[2], vUser[3], vUser[4], vUser[5],stoi(vUser[6]));
	}
	struct stLoginRegisterRecord;
	static stLoginRegisterRecord _ConvertLoginRegisterLineToRecord(string Line, string Seperator = "#//#")
	{
		stLoginRegisterRecord LoginRegisterRecord;


		vector <string> LoginRegisterDataLine = clsString::Split(Line, Seperator);
		LoginRegisterRecord.DateTime = LoginRegisterDataLine[0];
		LoginRegisterRecord.UserName = LoginRegisterDataLine[1];
		LoginRegisterRecord.Password = LoginRegisterDataLine[2];
		LoginRegisterRecord.Permission = stoi(LoginRegisterDataLine[3]);

		return LoginRegisterRecord;

	}

	static vector<stLoginRegisterRecord> _LoadLoginRegisterDataFromFile() {
		vector <stLoginRegisterRecord> vLogRegister;
		fstream MyFile;
		MyFile.open("RegisterLog.txt", ios::in);
		if (MyFile.is_open()) {
			string Line;
			while (getline(MyFile, Line)) {
				stLoginRegisterRecord LogReg = _ConvertLoginRegisterLineToRecord(Line);
				vLogRegister.push_back(LogReg);
			}
			MyFile.close();
		}

		return vLogRegister;
	}

	static vector<clsUser> _LoadUsersDataFromFile() {
		vector <clsUser> vUser;
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);
		if (MyFile.is_open()) {
			string Line;
			while (getline(MyFile, Line)) {
				clsUser User = _ConvertLineToUserObject(Line);
				vUser.push_back(User);
			}
			MyFile.close();
		  }

		return vUser;
	}

	static string _ConvertUserObjectToLine(clsUser User, string Seperator = "#//#") {
		string sUserObjectToLine = "";
		sUserObjectToLine += User.FirstName + Seperator;
		sUserObjectToLine += User.LastName + Seperator;
		sUserObjectToLine += User.Email + Seperator;
		sUserObjectToLine += User.Phone + Seperator;
		sUserObjectToLine += User.UserName + Seperator;
		sUserObjectToLine += User.Password + Seperator;
		sUserObjectToLine += to_string(User.Permeations);

		return sUserObjectToLine;
	}

	static void _SaveUsersDataToFile(vector <clsUser> vUser) {
		fstream MyFile;
		MyFile.open("Users.txt", ios::out);
		string DataUser;
		if (MyFile.is_open()) {
			for (clsUser U : vUser) {

				if (U._MarkedForDelete == false)
				{
					DataUser = _ConvertUserObjectToLine(U);
					MyFile << DataUser << endl;
				}
			}
			MyFile.close();
		}
		
	}

	void _AddDataLineToFile(string  stDataLine)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;

			MyFile.close();
		}

	}

	void _AddNew() {
		_AddDataLineToFile(_ConvertUserObjectToLine(*this));
	}

	 string  _PreperLoginRegisterToLine()
	{
		string sDataRegisterLine = "";
		sDataRegisterLine += clsDate::GetSystemDateAndTime() + "#//#";
		sDataRegisterLine += UserName + "#//#";
		sDataRegisterLine += Password + "#//#";
		sDataRegisterLine += to_string(Permeations);
		return sDataRegisterLine;
	 }

	void _Update() {
		vector<clsUser> vUser;
		vUser = _LoadUsersDataFromFile();
		for (clsUser& U : vUser) {
			if (U.UserName == UserName) {
				U = *this;
				break;
			}
		}
		_SaveUsersDataToFile(vUser);
	}
	
	static clsUser _GetEmptyObject() {
		return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}



	public:
		 struct stLoginRegisterRecord {
			string DateTime;
			string UserName;
			string Password;
			short Permission;
		};
		 static vector<stLoginRegisterRecord> GetLogRegister() {
			 return _LoadLoginRegisterDataFromFile();
		 }

		clsUser(enMode Mode, string FirstName, string LastName, string Email, string Phone,
			string UserName, string Password, short Permeations) :clsPerson(FirstName, LastName, Email, Phone) {
			this->_UserName = UserName;
			this->_Password = Password;
			this->_Permeations = Permeations;
			this->_Mode = Mode;
		}
		enum enPermisstion { pAll = -1, pShowClients = 1, pAddNewClient=2, pDeleteClient = 4, pUpdateClient=8,
							pFindClinet=16, pTransaction=32,pManagUsers=64,pLogout=128};
		void SetUserName(string UserName) {
			this->_UserName = UserName;
		}
		string GetUserName() {
			return _UserName;
		}
		__declspec(property(get = GetUserName, put = SetUserName)) string UserName;
		void SetPassword(string Password) {
			this->_Password = Password;
		}
		string GetPassword() {
			return _Password;
		}
		__declspec(property(get = GetPassword, put = SetPassword)) string Password;
		void SetPermeations(short Permeations) {
			this->_Permeations = Permeations;
		}
		short GetPermeations() {
			return _Permeations;
		}
		__declspec(property(get = GetPermeations, put = SetPermeations)) short Permeations;

		bool IsEmpty() {
			return (_Mode == enMode::EmptyMode);
		}
		string FullName() {
			return FirstName + " " + LastName;
		}
		static clsUser Find(string UserName) {
			
			fstream MyFile;
			MyFile.open("Users.txt", ios::in);
			if (MyFile.is_open()) {
				string Line;
				while (getline(MyFile, Line)) {
					clsUser User = _ConvertLineToUserObject(Line);
					if (User.UserName == UserName) {
						MyFile.close();
						return User;
					}
				}
				MyFile.close();
			}
			return _GetEmptyObject();
		}

		static clsUser Find(string UserName , string Password) {

			fstream MyFile;
			MyFile.open("Users.txt", ios::in);
			if (MyFile.is_open()) {
				string Line;
				while (getline(MyFile, Line)) {
					clsUser User = _ConvertLineToUserObject(Line);
					if (User.UserName == UserName && User.Password == Password) {
						MyFile.close();
						return User;
					}
				}
				MyFile.close();
			}
			return _GetEmptyObject();
		}

		static bool IsUserExist(string UserName) {
			clsUser User = clsUser::Find(UserName);
			return (!User.IsEmpty());
		}


		bool Delete()
		{
			vector <clsUser> vUsers;
			vUsers = _LoadUsersDataFromFile();

			for (clsUser & U : vUsers)
			{
				if (U.UserName == UserName)
				{
					U._MarkedForDelete = true;
					break;
				}

			}

			_SaveUsersDataToFile(vUsers);

			*this = _GetEmptyObject();

			return true;

		}

		static clsUser GetAddNewUserObject(string UserName)
		{
			return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
		}

		static vector <clsUser> GetUsersList()
		{
			return _LoadUsersDataFromFile();
		}

		enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildUserNameExists = 2 };
		enSaveResults Save()
		{

			switch (_Mode)
			{
			case enMode::EmptyMode:
			{
				if (IsEmpty())
				{
					return enSaveResults::svFaildEmptyObject;
				}
			}

			case enMode::UpdateMode:
			{
				_Update();
				return enSaveResults::svSucceeded;
				break;
			}

			case enMode::AddNewMode:
			{
				//This will add new record to file or database
				if (clsUser::IsUserExist(UserName))
				{
					return enSaveResults::svFaildUserNameExists;
				}
				else
				{
					_AddNew();
					//We need to set the mode to update after add new
					_Mode = enMode::UpdateMode;
					return enSaveResults::svSucceeded;
				}
				break;
			}
			}

		}
		
		void Print()
		{
			cout << "\nUser Card:";
			cout << "\n___________________";
			cout << "\nFirstName   : " << FirstName;
			cout << "\nLastName    : " << LastName;
			cout << "\nFull Name   : " << FullName();
			cout << "\nEmail       : " << Email;
			cout << "\nPhone       : " << Phone;
			cout << "\nUser Name   : " << UserName;
			cout << "\nPassword    : " << Password;
			cout << "\nPermeation  : " << Permeations;
			cout << "\n___________________\n";

		}


		bool CheckAccessPermission(enPermisstion Permisstion) {
			if (this->_Permeations == enPermisstion::pAll)
				return true;
			if ((this->Permeations & Permisstion) == Permisstion)
				return true;
			else {
				return false;
			}
		}

		 void RegisterInLog() {
			string sDataLineRegister = _PreperLoginRegisterToLine();
			fstream MyFile;
			MyFile.open("RegisterLog.txt", ios::out | ios::app);

			if (MyFile.is_open())
			{

				MyFile << sDataLineRegister << endl;

				MyFile.close();
			}
		}


};

