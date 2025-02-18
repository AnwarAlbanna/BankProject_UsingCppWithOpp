//Anwar Albnna 
// From Programming Advices
#include <iostream>
#include "clsMainScreen.h"
#include "clsLoginScreen.h"
using namespace std;
int main()
{
    
    //clsMainScreen::ShowMainMenue();
    while (true) {

        clsLoginScreen::ShowLoginScreen();
    }
   
    return 0;
}
