
#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

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

            cout << "\n_____________________________\n";

	}

        static void _ShowResults(clsCurrency Currency)
        {
            if (!Currency.IsEmpty())
            {
                cout << "\nCurrency Found :-)\n";
                _PrintCurrency(Currency);
            }
            else
            {
                cout << "\nCurrency Was not Found :-(\n";
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
			while (!clsCurrency::IsCurrencyExist(Currency)) {
				cout << "\nThe Currency Name is Not Found ,choos anther one :";
				Currency = clsInputValidate::ReadString();

            if (Answer == 1)
            {
                string CurrencyCode;
                cout << "\nPlease Enter CurrencyCode: ";
                CurrencyCode = clsInputValidate::ReadString();
                clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
                _ShowResults(Currency);
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

