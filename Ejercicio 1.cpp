#include <iostream>
#include <iostream>
using namespace std;


int main ()
{
	string mensaje="intente analizar mas profundamente los mensajes recibidos";
	int bloque;//al tratar de hacer tal cual el enunciado no me compilaba el programa y me generaba bastantes inconvenientes
	int largo=mensaje.size();
	cout<<"\nIngrese el tamano de los bloques que desea: ";
	cin>>bloque;
	string nuevo;
	for(int i=0;i<largo;i=i+(bloque)){
		for(int j=0;j<=bloque-1;j++){
			cout<<mensaje[j+i];
			nuevo.append(1,mensaje[j+i]);
		}	
	cout<<endl;
	nuevo.append(1,'*');
	}
	cout<<nuevo;
}
