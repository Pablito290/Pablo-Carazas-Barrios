#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;


int main ()
{
    string str;
    cout << "¿Que numero convertimos?" << endl;
    cin >> str;
	int num=atoi(str.c_str());
    cout << "Tu numero pero ahora en int es: " <<num;	//el numero que usted pone de ejemplo es: 548365842358.pero no se puede por que excede el numero total permitido que es: 2147483647
    return 0;
}
