#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"

using namespace std;
class clsFindCurrencyScreen : protected clsScreen
{
private:
	static void _PrintCurrency(clsCurrency Currency) {
		cout << "\n Currency Card :";
		cout << "\n----------------------------------------";
		cout << "\n Country      :" << Currency.Country();
		cout << "\n CurrencyCode :" << Currency.CurrencyCode();
		cout << "\n CurrencyName :" << Currency.CurrencyName();
		cout << "\n Rate         :" << Currency.Rate();
		cout << "\n-----------------------------------------";

	}
	static void _ShowResult(clsCurrency Currency) {
		if (!Currency.IsEmpty()) {
			cout << "\nCurrency Found :-)";
			_PrintCurrency(Currency);
		}
		else {
			cout << "\nCurrency Not Found :-(";
			_PrintCurrency(Currency);

		}
	}
public:
	static void ShowFindCurrencyScreen() {
		string Currency = "";
		system("cls");
		_DrawScreenHeader("Find Currency Screen");

		short choos = 0;
		cout << "Please, Enter (1) to Find by CountryCode  (Or) Enter (2) to Find By Country:";
		cin >> choos;
		if (choos == 1) {
			cout << "Please Enter the CountryCode :";
			Currency = clsInputValidate::ReadString();
			clsCurrency C = clsCurrency::FindByCode(Currency);
			_ShowResult(C);
		}
		else if (choos == 2) {
			cout << "Please Enter the Country :";
			Currency = clsInputValidate::ReadString();
			clsCurrency C = clsCurrency::FindByCountry(Currency);
			_ShowResult(C);
		}

	}


};

