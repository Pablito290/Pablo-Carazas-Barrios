#include <iostream>
#include <ctime>	
using namespace std;
#include "funciones.h"
const int primos[12]={7,11,13,17,19,23,29,31,37,41,43,47};
					//0 1  2  3  4  5  6  7  8  9  10  11

int numero_aleatorio(){		//esta es mi forma base de hacer de que me de un numero aleatorio entre el 1 y el 12
	time_t current_time;	// use una funcion que daba los segundos que ocurren desde una fecha (esa parte l encontre en internet)
	current_time = time(NULL);	//y le agregue un modulo para que ese numero grande siempre este en Z12 , es cual es la cantidad de elementos que tiene mi array de numeros primos
	return modulo(current_time,12);	// esta funcion por ahora no la uso para poder monitorear bien lo que ocurre en mi programa
}

class algoritmoX{
	private:
		int p;			//se que todo esto podria estar en una sola linea pero tenerlo asi me ayuda a no marearme 
		int q;
		int n;
		int simboliton;
		int e;
		int d;
		int ClavePublic[2];
		int ClavePriv[2];
		int SinCifrar;
		int Cifrado;
		int Descifrado;
		
		
	public:
		algoritmoX(int P,int Q,int E){
			p=primos[P];		//aun no se me ocurre como crear una funcion que genere numeros primos de manera aleatoria 
			q=primos[Q];
			n=p*q;
			simboliton=(p-1)*(q-1);
			e=E;
			d=generarD();
			ClavePublic[0]=e;
			ClavePublic[1]=n;
			ClavePriv[0]=d;
			ClavePriv[1]=n;
			
		}
		
		int generarD(){
			return euclidesextendido(e,simboliton);
		}
		
		int generarE(int E){	//hago esto por complicaciones a la hora de crear aleatorios 
			return E;
		}
		
		int mensajeC(int msj){
			Cifrado=msj;
		}
			
		int mensaje(int msj){
			SinCifrar=msj;
		}
		
		int cifrador(int claveK[]){
			Cifrado = expo_mod(SinCifrar,claveK[0],claveK[1]);
		}
		
		int descifrador(){
			Descifrado = expo_mod(Cifrado,ClavePriv[0],ClavePriv[1]);
		}
		
		int compartecif(){
			return Cifrado;
		}
		
		int *comparteClave(){	//la funcion es tipo puntero para que se pueda devolver una matriz la cual es la clave, o sea (e,Øn)
			return ClavePublic;
		}
		void mostrarValores(){
			cout<<"p="<<p<<endl;
			cout<<"q="<<q<<endl;
			cout<<"n="<<n<<endl;
			cout<<"simboliton="<<simboliton<<endl;
			cout<<"e="<<e<<endl;
			cout<<"d="<<d<<endl;
			cout<<"public="<<ClavePublic[0]<<endl;
			cout<<"priv="<<ClavePriv[0]<<endl;
			//cout<<"cifrado="<<Cifrado<<endl;
	}
		void mosmsj(){
			cout<<"Mensaje De mario original fue = "<<SinCifrar<<" Y una vez cifrado con la clave publica de Juan se volvio = "<<Cifrado<<endl;
		}
		void mosdes(){
			cout<<"Mensaje que mario recibio cifrado = "<<Cifrado<<" Y una vez descifrado con la clave privado de Juan se volvio = "<<Descifrado<<endl;
		}
};


int main(){
	cout<<"Valores de Juan (Receptor)"<<endl;
	algoritmoX Juan(3,5,29);
	Juan.mensajeC(20);
	Juan.mostrarValores();
	//Juan.mosdes();
	
	cout<<"-------Valores de Mario (Emisor)-----"<<endl;
	
	algoritmoX Mario(3,10,101);
	Mario.mensaje(362);
	Mario.cifrador(Juan.comparteClave());
	Mario.mostrarValores();
	Mario.mosmsj();
	
	cout<<"-------Mario Descifra-----"<<endl;
	Juan.descifrador();
	Juan.mosdes();
}
