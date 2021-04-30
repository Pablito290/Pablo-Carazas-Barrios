#include <iostream>
#include <time.h>
#include <stdlib.h>
//#include "funciones.h"
using namespace std;
const string abecedario="abcdefghijklmnopqrstuvwxyz";

int modulo(int a, int n){
	int q=a/n;
	int r=a-(n*q);
	if(r<0){
		q--;
		r=a-(n*q);
	}
	return r;

}

int euclides(int r1,int r2){
	int aux;
	while(r2>0){
		aux=r2;

		r2=modulo(r1,r2);
		r1=aux;
		//cout<<r1<<endl;
	}
	return r1;
}


int euclidesextendido(int a, int b){
	int q,x,ultix,y,ultiy,aux,aux1,aux2,aux3;  
  
  
    if (b>a) { 
     aux=a; a=b; b=aux; 
    } 
    x=0; 
    y=1; 
    ultix=1; 
    ultiy=0; 
    while (b!=0) { 
     q= a/b; 
     aux1= modulo(a,b); 
     a=b; 
     b=aux1; 

	aux2 = x; 
    x=ultix-q*x; 
    ultix = aux2; 

    aux3 = y; 
    y = ultiy-q*y; 
    ultiy=aux3;  
    } 
    return ultiy;
}

class algoritmoX{
	public:
		int clave_a;//miss presento un problema a la hora de  usar el random, una vez sale un numero aleatorio no cambia y es el mismo siempre, no se como solucionar eso asi que para la clave a siempre usare 5
		int clave_b;
		int inversa;
		int crear_clave_a(){
		    clave_a=0+rand()%(abecedario.size());
    		//cout<<"rarnd="<<clave_a<<endl;
    		if(euclides(clave_a,abecedario.size())!=1){
    			//cout<<"rarnd="<<a<<endl;
    			//cout<<"modulo="<<euclides(a,26)<<endl;	
				clave_a=0+rand()%(27);	}
			return clave_a;
		}
		int crear_clave_b(){
			 return clave_b=0+rand()%(27);
		}
		
		string cifrado(string mensaje,int clave_a=5,int clave_b=8){
			string cifrado;
			for(int i=0;i<mensaje.length();i++){
			int aux=0;
			aux=abecedario.find(mensaje[i]);
			//cout<<"aux="<<aux*clave_a+clave_b<<endl;
			aux=modulo(clave_a*aux+clave_b,abecedario.size());
			
				cifrado.append(1,abecedario[aux]);
			
			//cout<<aux<<" "<<abecedario[aux]<<endl;		 //este cout lo uso para verificar el buen funcionamiento del codigo
		}
		return cifrado;	
	}
	
	int fun_inversa(int a){
		inversa=euclidesextendido(a,26);
		if(inversa<0){
			inversa=modulo(inversa,26);
		}
		return inversa;
	}
	
		string descifrado(string mensaje,int inversa=5,int clave_b=8){
		string cifrado;
		for(int i=0;i<mensaje.length();i++){
			int aux=1;
			aux=abecedario.find(mensaje[i]);
			aux=modulo(inversa*(aux-clave_b),abecedario.size());
				cifrado.append(1,abecedario[aux]);
				
		}
		return cifrado;	
	}
	
		
};

main() 
{ 
	algoritmoX emisor;
	algoritmoX receptor;
	//miss presento un problema a la hora de  usar el random, una vez sale un numero aleatorio no cambia y es el mismo siempre, no se como solucionar eso asi que para la clave a siempre usare 5
	int clavea=5;//emisor.crear_clave_a();
	int claveb=emisor.clave_b;
	
	cout<<"clavea="<<clavea<<endl;
	cout<<"claveb="<<claveb<<endl;
	
	string msj_cifrado=emisor.cifrado("itscool",clavea,claveb);
	cout<<"msj_cifrado="<<msj_cifrado<<endl;
	int recepinver=receptor.fun_inversa(clavea);
	string msj_des=receptor.descifrado(msj_cifrado,recepinver,claveb);
	cout<<msj_des;
	
	
	
	
} 
