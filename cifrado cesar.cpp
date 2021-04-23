#include <iostream>
#include <string>
using namespace std;
const int clave=3;	   
const string abecedario="abcdefghijklmnopqrstuvwxyz";


class AlgoritmoX{/*
	private:
		int clave=3;	   //no estoy seguro si el lugar correcto donde poner esto es acá o en una variable global asi que lo dejo como comentario en un caso esta sea el lugar
		string abecedario="abcdefghijklmnopqrstuvwxyz";
*/
	public:	
	string cifrado(string mensaje,int clave=3){
		string cifrado;
		for(int i=0;i<mensaje.length();i++){
			int aux=0;
			aux=abecedario.find(mensaje[i]);
			aux=aux+clave;
			if(aux==clave-1){
				cifrado.append(1,' ');
			}
			else if(aux>25){
				//aux=aux-26;
				aux=aux%(26);
				cifrado.append(1,abecedario[aux]);
			}
			else{
				cifrado.append(1,abecedario[aux]);
			}
			//cout<<aux<<" "<<abecedario[aux]<<endl;		 //este cout lo uso para verificar el buen funcionamiento del codigo
		}
		
		return cifrado;	
	}
	
	string descifrado(string mensaje,int clave=3){
		string cifrado;
		for(int i=0;i<mensaje.length();i++){
			int aux=1;
			aux=abecedario.find(mensaje[i]);
			aux=aux-clave;
	
			if(aux==0-(clave+1)){
				cifrado.append(1,' ');
			}
			else if(aux<0){
				aux=aux+26;
				cifrado.append(1,abecedario[aux]);
			}
			else{
				cifrado.append(1,abecedario[aux]);
			}		
		}
		return cifrado;	
	}
	/*
	string cifrado(string mensaje,int clave=4){
		string cifrado;
		for(int i=0;i<mensaje.length();i++){
			int aux=0;
			aux=abecedario.find(mensaje[i]);		//Esta funcion es una alternativa de cifrado pero  presenta algunos problemas los cuales se me hace confuso, mas facil se me hace de la manera de la funcoin no comentada
			aux=aux+clave%26;
			if(aux==clave-1){
				cifrado.append(1,' ');}
			else{
			cifrado.append(1,abecedario[aux]);
		}
}
		return cifrado;	
	}*/
	
};

string cifradoopcional(string mensaje,int clave=3){	//esta funcion la hago para hacer una funcion fuerza bruta y averiguar la clave
		string cifrado;
		for(int i=0;i<mensaje.length();i++){
			int aux=0;
			aux=abecedario.find(mensaje[i]);
			aux=aux+clave;
			if(aux==clave-1){
				cifrado.append(1,' ');
			}
			else if(aux>25){
				aux=aux%(26);
				cifrado.append(1,abecedario[aux]);
			}
			else{
				cifrado.append(1,abecedario[aux]);
			}
		}
		
		return cifrado;	
	}
	
int Fuerza_Bruta(string mensaje,string pista){ //lo que hace esta funcion es pedir el mensaje original y el mensaje final
	if(mensaje.size()==pista.size()){
	int posible=0;
	string aux;
	bool confirmacion=false;
	while(confirmacion==false){
		aux=cifradoopcional(mensaje,posible);
		if(aux[0]==pista[0]){
			confirmacion=true; 
		}
		else{
		posible++;
		} }
	return posible;
}
	else{
		cout<<endl<<"Los valores ingresados no coinciden por lo cual revise su codigo"<<endl;
		return -1;
	}
}

int main(){
	string mensaje="awita de coco";
	cout<<"Mensaje Original:"<<mensaje<<endl;
	AlgoritmoX Emisor;
	AlgoritmoX Receptor;
	string msj_cifrado=Emisor.cifrado(mensaje);
	string msj_descifrado=Receptor.descifrado(msj_cifrado);
	cout<<"Cifrado:"<<msj_cifrado;
	cout<<endl<<"Descifrado:"<<msj_descifrado;
	int la_clave=Fuerza_Bruta("awita de coco","dzlwd gh frfr");
	cout<<endl<<"La clave es:"<<la_clave;

}
