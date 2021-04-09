#include <iostream>
using namespace std;
const int clave=3;


class Algoritmo{
	public:
		string cifrado(string mensajeC){
		    string salida=mensajeC;
		    int f1=(clave*2)-2;
			int indice=0;
			int f2=0;
		    for(int i=0;i<clave;f1-=2,f2+=2,i++){ //f1 y f2 son variables auxiliares al igual que a
		        int a=i;		//a  al inicio de cada for tomara el valor del valor iterativo
		        salida[indice++]=mensajeC[i];	//voy copiando los valores de los string
		        while(a<mensajeC.size()){	//para no exceder
		            a=a+f1;
					cout<<endl<<f2;			//con esto ire saltando en valores por asi decirlo de 4 en 4 en este caso
		            if(f1&&a<mensajeC.size())	//si son menores que el largo ocurre
		                salida[indice++]=mensajeC[a];
		            a=a+f2;			//aumenta a
		            if(f2&&a<mensajeC.size())		
		                salida[indice++]=mensajeC[a];
		        }
		    }
		    return salida;
		}
		
		
		string descifrado(string encriptado){		//esta funcione es casi identica solo que cambia es la inversa
		    string descifrados=encriptado;
		    
		    int f1=(clave*2)-2;
			int indice=0;
			int f2=0;
		    for(int i=0;i<clave;f1-=2,f2+=2,i++){
		        descifrados[i]=encriptado[indice++];
		        int a=i;
		        while(a<encriptado.size()){
		            a+=f1;
		            if(f1&&a<encriptado.size())
		                descifrados[a]=encriptado[indice++];
		            a+=f2;
		            if(f2&&a<encriptado.size())
		                descifrados[a]=encriptado[indice++];
		        }
		    }
		    return descifrados;
		}

};


int main(){
	Algoritmo Emisor;
	Algoritmo Receptor;
	
	string mensaje_Original="Hello-World";
	string mensaje_Codificado=Emisor.cifrado(mensaje_Original);
	string Mensaje_Decodificado=Receptor.descifrado(mensaje_Codificado);
	
	cout<<mensaje_Codificado;
	cout<<endl<<Mensaje_Decodificado;
}
