#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include "clsCurrency.h"
#include "clsScreen.h"
#include "clsInputValidate.h"

using namespace std;
class clsCalculatorCurrencyScreen :protected clsScreen
{
private:
	static clsCurrency _GetCurrency(string Message ) {
		cout << Message;
		string CurrencyCod = clsInputValidate::ReadString();
		while (!clsCurrency::IsCurrencyExist(CurrencyCod)) {
			cout << "\nNot Found, Choos anther one:";
			CurrencyCod = clsInputValidate::ReadString();
		}
		clsCurrency Currency= clsCurrency::FindByCode(CurrencyCod);
		return Currency;
	}

	static float _RateAmount() {
		cout << "\n Please Enter Amount to Convert :";
		float Amount = clsInputValidate::ReadFloatNumber();
		return Amount;

	}

	static void _PrintCardCurrency(clsCurrency Currency,string Message="Info Card:") {
		cout << "\n" << Message;
		cout << "\n--------------------------------------------------------";
		cout << "\n Country      :" << Currency.Country();
		cout << "\n CurrencyCode :" << Currency.CurrencyCode();
		cout << "\n CurrencyName :" << Currency.CurrencyName();
		cout << "\n Rate         :" << Currency.Rate();
		cout << "\n--------------------------------------------------------";
	}

	static void _PrintCalculatorResultCurrency(float Amount, clsCurrency CurrencyFrom, clsCurrency CurrencyTo) {
		_PrintCardCurrency(CurrencyFrom, "Card Currency From:");

		float AmountInUSD = CurrencyFrom.ConvertToUSD(Amount);
		cout << "\n Amount " << Amount<<" " << CurrencyFrom.CurrencyCode() << " = " << AmountInUSD << " USD";
		if (CurrencyTo.CurrencyCode() == "USD") {
			return;
		}
		float AmountInOtherCurrency = CurrencyFrom.ConvertToOtherCurrency(Amount, CurrencyTo);
		cout << "\n Amount " << Amount << " " << CurrencyFrom.CurrencyCode() << " = " << AmountInOtherCurrency << " " << CurrencyTo.CurrencyCode();

	}


public:

	static void ShowCalculatorCurrencyScreen() {
		char Choos = 'y';
		while (Choos=='Y' || Choos=='y') {
			system("cls");
			_DrawScreenHeader("Calculate Currency Exchange");
			clsCurrency CurrencyFrom = _GetCurrency("Please Enter The Currency Cod From:");
			clsCurrency CurrencyTo = _GetCurrency("Please Enter The Currency Cod To:");
			float RateAmount = _RateAmount();
			_PrintCalculatorResultCurrency(RateAmount, CurrencyFrom, CurrencyTo);
			cout << "\n Do you want do that anther time :y/n ";
			cin >> Choos;
		}
	}


};

