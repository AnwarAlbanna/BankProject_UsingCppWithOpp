#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"

using namespace std;
class clsFindCurrencyScreen : protected clsScreen
{
private:
	static void _PrintCurrency(clsCurrency Currency) {
		cout << "\n--------------------------------------------------------";
		cout << "\n Country      :" << Currency.Country();
		cout << "\n CurrencyCode :" << Currency.CurrencyCode();
		cout << "\n CurrencyName :" << Currency.CurrencyName();
		cout << "\n Rate         :" << Currency.Rate();
		cout << "\n--------------------------------------------------------";

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
			while (!clsCurrency::IsCurrencyExist(Currency)) {
				cout << "\nThe Currency Name is Not Found ,choos anther one :";
				Currency = clsInputValidate::ReadString();

			}
			clsCurrency C = clsCurrency::FindByCode(Currency);
			_PrintCurrency(C);
		}
		else if (choos == 2) {
			cout << "Please Enter the Country :";
			Currency = clsInputValidate::ReadString();
			while (!clsCurrency::IsCurrencyExist(Currency)) {
				cout << "\nThe Currency Name is Not Found ,choos anther one :";
				Currency = clsInputValidate::ReadString();

			}
			clsCurrency C = clsCurrency::FindByCountry(Currency);
			_PrintCurrency(C);
		}

	}


};

