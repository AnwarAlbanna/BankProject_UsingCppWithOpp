#pragma once

#include <iostream>
#include <iomanip>
#include "clsUtil.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"

using namespace std;
class clsCurrencisScreen :protected clsScreen
{

    private:
        enum enCurrenciesOptions {
            eShowList = 1, eFind = 2, eUpdate = 3,
            eCalculate = 4, eMainMenue = 5
        };
        static short _ReadCurrenciesOption()
        {
            cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
            short Choice = clsInputValidate::ReadIntNumberBetween(1, 5, "Enter Number between 1 to 5 ? ");
            return Choice;
        }

        static  void _GoBackToCurrenciesScreen()
        {
            cout << setw(37) << left << "" << "\n\tPress any key to go back to Currencies Screen ...\n";

            system("pause>0");
            ShowCurrenciesMenue();
        }

        static void _ShowListCurrencies()
        {
            //cout << "\n List Currencies Screen Will be here...\n";
            clsCurrenciesListScreen::ShowCurrenciesListScreen();
        }
        static void _ShowFindCurrencies()
        {
           // cout << "\n Find Currencies Screen Will be here...\n";
            clsFindCurrencyScreen::ShowFindCurrencyScreen();
        }
        static void _ShowUpdateCurrencies()
        {
            cout << "\n Update Currencies Screen Will be here...\n";

        }

        static void _ShowCalculateCurrencies()
        {
            cout << "\n Calculate Currencies Screen Will be here...\n";

        }
       
        static void _PerfromMainMenueOption(enCurrenciesOptions CurrenciesOptions)
        {
            switch (CurrenciesOptions)
            {

            case enCurrenciesOptions::eShowList:
            {
                system("cls");
                _ShowListCurrencies();
                _GoBackToCurrenciesScreen();
                break;
            }
            case enCurrenciesOptions::eFind:
                system("cls");
                _ShowFindCurrencies();
                _GoBackToCurrenciesScreen();
                break;

            case enCurrenciesOptions::eUpdate:
                system("cls");
                _ShowUpdateCurrencies();
                _GoBackToCurrenciesScreen();
                break;

            case enCurrenciesOptions::eCalculate:
                system("cls");
                _ShowCalculateCurrencies();
                _GoBackToCurrenciesScreen();
                break;
            case enCurrenciesOptions::eMainMenue:
            {

            }
            }
        }



    public:

        static void ShowCurrenciesMenue()
        {
            /*if (!CheckAccessRights(clsUser::enPermisstion::pTransaction)) {
                return;
            }*/

            system("cls");
            _DrawScreenHeader("\tCurrencies Screen");

            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t\t\tTransactions Menue\n";
            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t[1] Show Currencies Screen.\n";
            cout << setw(37) << left << "" << "\t[2] Find Currencies Screen.\n";
            cout << setw(37) << left << "" << "\t[3] Update Currencies Screen.\n";
            cout << setw(37) << left << "" << "\t[4] Calculate Currencies Screen.\n";
            cout << setw(37) << left << "" << "\t[6] Main Menue Screen.\n";
            cout << setw(37) << left << "" << "===========================================\n";

            _PerfromMainMenueOption((enCurrenciesOptions)_ReadCurrenciesOption());
        }





};

