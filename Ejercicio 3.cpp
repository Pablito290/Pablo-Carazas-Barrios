#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
int main ()
{
  int i;
  char cadena [100];
	cout<<"Pon un numero: ");
  cin>>i;
  itoa (i,cadena,10);
  
  cout<<cadena;
}
