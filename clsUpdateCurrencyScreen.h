#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"

using namespace std;
class clsUpdateCurrencyScreen : protected clsScreen
{
private:
	static void _PrintCurrency(clsCurrency Currency) {
		cout << "\n Currency Card ";
		cout << "\n-------------------------------------------------";
		cout << "\n Country      :" << Currency.Country();
		cout << "\n CurrencyCode :" << Currency.CurrencyCode();
		cout << "\n CurrencyName :" << Currency.CurrencyName();
		cout << "\n Rate         :" << Currency.Rate();
		cout << "\n-------------------------------------------------";

	}



public :
	static void ShowUpdateCurrencyScreen() {
		system("cls");
		string Title = "Update Currency Screen";
		_DrawScreenHeader(Title);
		cout << "\nPlease Enter CurrencyCode :";
		string CurrencyCode =clsInputValidate::ReadString();
		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		_PrintCurrency(Currency);
		char Answer = 'n';
		cout << "\nAre you sure to Update this Rate : y/n ";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y') {
			cout << "\n----------------------";
			cout << "\n Enter NewRate here to Update :";
			float NewRate = clsInputValidate::ReadFloatNumber();
			Currency.UpdateRate(NewRate);
			_PrintCurrency(Currency);
			cout << "\nUpdated is Succssfully !";
		}
		else {
			_PrintCurrency(Currency);
			cout << "\nUpdated is Faild !";
		}

	}
};

