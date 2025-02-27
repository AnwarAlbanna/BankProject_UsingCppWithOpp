#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsCurrency.h"

using namespace std;
class clsCalculatorCurrencyScreen : protected clsScreen
{
private:


public :
	static void ShowCalculatorCurrencyScreen() {
		system("cls");
		_DrawScreenHeader("\t Calculator Currency Screen");
		string CurrencyCode1, CurrencyCode2;

		// Currency Code 2
		cout << "\n Please Enter Currency1 Code:";
		CurrencyCode1 = clsInputValidate::ReadString();
		if (!clsCurrency::IsCurrencyExist(CurrencyCode1)) {
			cout << "\nThe Currency is not Found, choos anther one:";
			CurrencyCode1 = clsInputValidate::ReadString();
		}
		clsCurrency Currency1 = clsCurrency::FindByCode(CurrencyCode1);

		// Currency Code 2
		cout << "\n Please Enter Currency2 Code:";
		CurrencyCode2 = clsInputValidate::ReadString();
		if (!clsCurrency::IsCurrencyExist(CurrencyCode2)) {
			cout << "\nThe Currency is not Found, choos anther one:";
			CurrencyCode2 = clsInputValidate::ReadString();
		}
		clsCurrency Currency1 = clsCurrency::FindByCode(CurrencyCode2);
		float Amount = 0;
		cout << "\nEnter Amount to ExChange:";
		Amount = clsInputValidate::ReadFloatNumber();
	}

};

