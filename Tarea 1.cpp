#include <iostream>
#include <string.h>
using namespace std;

const int c=6,f=3;	//c equivale a las columnas de la "matriz" en la cual se codifica aunque en realidad no se usa matriz
					//			|h|o|l|a|-|c|
					//			|o|m|o|-|e|s|		c= columna
					//			|t|a|n|-|-|-|		f= a las filas 
					// esta fue la logica inicial		

class Algorito{
	public:
		
	   string Codificador(string mensaje){ 
	    	string Auxiliar=mensaje;
	    	mensaje="";
			for (int i=0; i< c; i++){
	    		for (int j=0; j< f; j++){
	        		mensaje= mensaje+Auxiliar[j*c+i]; 
	    }
	    }    
	    	return mensaje;
		}
		
	   string Decodificador(string mensaje){ 
	    	string Auxiliar="";
	      	for (int i=0; i<f; i++){
	        	for (int j=0; j< c; j++){
	        	Auxiliar= Auxiliar + mensaje[j*f+i]; 
	    }
	    }
	    	return Auxiliar;
	   }
	};
	
int main() {
		
	Algorito Emisor; 
	Algorito Receptor;
	string mensaje_Original = "Hola como estan";
	
	string mensaje_Codificado= Emisor.Codificador(mensaje_Original); 
	string mensaje_Decodificado= Receptor.Decodificador(mensaje_Codificado);
	
	cout<<"\t Tarea 1"<<endl;
	cout<<"Mensaje original\t= "<<mensaje_Original<<endl;
	cout<<"Mensaje Codificado\t= "<<mensaje_Codificado <<endl;
	cout<<"Mensaje Decodificado\t= "<<mensaje_Decodificado<<endl;
}
