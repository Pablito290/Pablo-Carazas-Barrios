#include <iostream>
#include <string>
#include <math.h>
using namespace std;

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
    return ultiy;//inversa
}

int fun_inversa(int a,int z){
		int inversa=euclidesextendido(a,z);
		if(inversa<0){
			inversa=modulo(inversa,z);
		}
		return inversa;
	}
	
int expo_mod(int m, int num, int z){
	//int m;	//MENSAJE
	//int num;		//ELEVADO
	//int z;		//MODULO
	int x=1;
	int elevado=m;
	int modu;
	int resultado=1;
	int mitad=num;
	while(num>0){
	modu=num%2;
	mitad=mitad/2;
	
	
	if(modu==1){
		
		resultado=resultado*elevado;
		resultado=modulo(resultado,z);
		//cout<<"RESultadooooo= "<<resultado<<endl;
	}
	
	elevado=pow(elevado,2);
	elevado=modulo(elevado,z);	
	num=num/2;
	x=x*2;
	

	}	
	return resultado;
}
