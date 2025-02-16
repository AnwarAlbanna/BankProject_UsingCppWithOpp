#pragma once
#include <iostream>
using namespace std;
class clsPerson
{
private:
	string _FirstName = "";
	string _LastName = "";
	string _Email = "";
	string _Phone = "";
public:
	clsPerson(string FirstName, string LastName, string Email, string Phone) {
		_FirstName = FirstName;
		_LastName = LastName;
		_Email = Email;
		_Phone = Phone;
	}
	// FirstName
	void SetFirstName(string FirstName) {
		this->_FirstName = FirstName;
	}
	string GetFirstName() {
		return _FirstName;
	}
	__declspec(property(get = GetFirstName, put = SetFirstName)) string FirstName;
	// LastName
	void SetLastName(string LastName) {
		this->_LastName = LastName;
	}
	string GetLastName() {
		return _LastName;
	}
	__declspec(property(get = GetLastName, put = SetLastName)) string LastName;
	// Email
	void SetEmail(string Email) {
		this->_Email = Email;
	}
	string GetEmail() {
		return _Email;
	}
	__declspec(property(get = GetEmail, put = SetEmail)) string Email;
	// Phone
	void SetPhone(string Phone) {
		this->_Phone = Phone;
	}
	string GetPhone() {
		return _Phone;
	}
	__declspec(property(get = GetPhone, put = SetPhone)) string Phone;

	 void Print() {
		cout << "_________________________________" << endl;

		cout << "FirstName is:" << FirstName << "\n";
		cout << "LastName  is:" << LastName << "\n";
		cout << "Email     is:" << Email << "\n";
		cout << "Phone     is:" << Phone << "\n";

		cout << "_________________________________" << endl;
	}

};


