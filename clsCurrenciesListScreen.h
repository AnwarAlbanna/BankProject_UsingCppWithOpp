#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include "clsCurrency.h"
#include "clsScreen.h"

using namespace std;
class clsCurrenciesListScreen :protected clsScreen
{
private:
	static void _PrintCurrencies(clsCurrency Currency) {
        cout << setw(8) << left << "";
        cout << "| " << left << setw(30) << Currency.Country()     ;
        cout << "| " << left << setw(15) << Currency.CurrencyCode();
        cout << "| " << left << setw(45) << Currency.CurrencyName();
        cout << "| " << left << setw(10) << Currency.Rate()        ;
	}


public :

	static void ShowCurrenciesListScreen() {
		system("cls");
		vector<clsCurrency> vCurrency = clsCurrency::GetCurrenciesList();
        string Title = "\t  Currencies List Screen";
        string SubTitle = "\t    (" + to_string(vCurrency.size()) + ") Currecny (s).";

        _DrawScreenHeader(Title, SubTitle);


        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" ;
        cout << "| " << left << setw(30) << "Currencies Country";
        cout << "| " << left << setw(15) << "Currencies Code";
        cout << "| " << left << setw(45) << "Currencies Name";
        cout << "| " << left << setw(10) << "Rate(s)/$";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vCurrency.size() == 0)
            cout << "\t\t\t\tNo Currencies Available In the System!";
        else

            for (clsCurrency C : vCurrency)
            {

                _PrintCurrencies(C);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
	}
};

