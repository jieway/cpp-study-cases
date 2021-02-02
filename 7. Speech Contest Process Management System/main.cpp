#include <iostream>
#include "speechManager.h"
#include "speechManager.cpp"

using namespace std;

int main(){
    SpeechManager sm;
    int selected = 0;

    while(true){
        sm.Show_Menu();
        cout << "ÇëÊäÈëÑ¡Ôñ£¡" << endl;
        cin >> selected;
        switch(selected){
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 0:
                sm.exitSystem();
                break;
            default:
                system("cls");
                break;
        }
        system("pause");
        system("cls");
    }

    return 0;
}