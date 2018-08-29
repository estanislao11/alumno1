#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<iomanip>
#include<fstream>
using namespace std;

const int NUM=12;

struct Tienda {
   int clave;
   string nombre;
   string marca;
   double precio;
};
Tienda tienda [NUM];

void insertar(int,string,string,double);
void mostrarDatos();
void escribirEnArchivo();
void recuperarDeArchivo();
void pedirDatos();
void inicializar();
int buscarlugarVacio();
void menu();
void borrar(int);
void mostrarRegistro(int);
int desicion();
int clave, plu;
int creditos();
int comprarproducto();
int credito=100,abono, nuevo=0;
int claveC;
int clavesproductos[12];


int main(){
    int opcion;
do {
    menu();
    cout<<"?"<<"\n";
    cin>>opcion;
    switch (opcion){

    case 1: system("cls");
            pedirDatos();
            escribirEnArchivo();
	 		    break;
    case 2:system("cls");
           mostrarDatos();
           system("pause");
           system("cls");
                break;
    case 3:system("cls");
           cout<<"Lista de los productos";
           comprarproducto();
                break;
    case 4:system("cls");
           creditos();
           cout<<"\n\n";
           system("pause");
           system("cls");
                break ;
    case 5: system("cls");
       cout<<"Acaba el programa";
	   break;
    }
}while (opcion !=4 );
return 0;
}

void menu(){
   	    cout<<"Escoge la opciona que mas te agrade"<<endl;
 	    cout<<"1. Dar de Alta los Productos"<<endl;
  	    cout<<"2. El Reporte general"<<endl;
		cout<<"3. La Compra de los productos "<<endl;
        cout<<"4. Su saldo es:";
	}

void pedirDatos(){
    	int clavex;
 	    string nombrex;
 	    string marcax;
 	    double preciox;
 	    cout<<"Ingresa los datos de la cancion ."<<endl;
 	    cout<<"Clave:";
 	    cin>>clavex;
 	    for(int i=0; i<NUM; i++){
 	    	while(clavex==tienda[i].clave){
 	    		cout<<"Clave existente, favor de ingresar otra : ";
				 cin>>clavex;
				 i=0;
		    }
	    }
 	    cout<<"Nombre: ";
 	    getline(cin, nombrex);
 	    getline(cin, nombrex);
 	    cout<<"\n Marca: ";
 	    getline(cin, marcax);
 	    cout<<"\n El Costo del producto es : ";
  	    cin>>preciox;
 	    insertar(clavex,nombrex,marcax,preciox);
	}

    string reemplazarEspacios(string texto){
    	for (int i= 0;i<( int)texto.length();++i) {
    		if (texto[i]==' '){
    			texto.replace(i,1,"#");
			}
		}
 	return texto;
	}

    string reemplazarSharp(string texto){
    	for ( int i=0;i<(int)texto.length();++i){
    		if (texto[i] == '#'){
    			texto.replace(i, 1," ");
			}
 		}
 	return texto;
	}

    void insertar(int clavex,string nombrex,string marcax,double preciox) {
    	int lugarVacio=buscarlugarVacio();
		if (lugarVacio==-1){
			cout<<"No hay suficiente espacio"<<endl;
			return;
		}
 	    tienda[lugarVacio].clave=clavex;
 	    tienda[lugarVacio].nombre=nombrex;
 	    tienda[lugarVacio].marca=marcax;
 	    tienda[lugarVacio].precio=preciox;
	}
 void escribirEnArchivo(){
    	ofstream salidaArchivo("productos.txt", ios::out);
 	    if (!salidaArchivo){
 	    	cerr<<"No se puede abrir archivo"<<endl; 
	 	    exit(1);
		}
		for (int i=0;i<NUM;i++){
			if (tienda[i].clave!=0){
				salidaArchivo 
		 	    <<tienda[i].clave<<' '
 			    <<reemplazarEspacios(tienda[i].nombre)<<' '
  			    <<reemplazarEspacios(tienda[i].marca)<<' '
		 	    <<tienda[i].precio<< ' '<<endl;
			}
		}
	}
    void mostrarDatos(){
    	cout<<endl;
 	    cout<<setw(6)<<"Clave"
	 	    <<setw(20)<<"Nombre"
 		    <<setw(20)<<"Marca"
 		    <<setw(20)<<"Precio"<<endl;
 	    for ( int i=0;i<NUM;i++){
 	    	if (tienda[i].clave!=0){
 	    		cout <<setw(6)<<tienda[i].clave
	 			     <<setw(20)<<tienda[i].nombre
	 			     <<setw(20)<<tienda[i].marca
	 			     <<setw(20)<<tienda[i].precio<<endl;
			}
		}
	}
	 void inicializar(){
    	for (int i=0;i<NUM;i++){
    		tienda[i].clave=0;
            tienda[i].nombre="";
 		    tienda[i].marca="";
	 	   tienda[i].precio=0;
		}
	}
    int buscarlugarVacio(){
    	for (int i=0;i<NUM;i++){
    		if (tienda[i].clave==0){
    			return i;
			}
		}return-1;
	}

	int comprarproducto(){
		 		mostrarDatos();
				 cout<<"Ingresa la clave del producto que deseas comprar:";
				 cin>>claveC;
		 	     cout<<endl;
 				 cout<<setw(6)<<"Clave"
	 			              <<setw(20)<<"Nombre"
 				              <<setw(20)<<"Marca"
 				              <<setw(15)<<"Precio"<<endl;
 				for ( int i=0;i<NUM;i++){
					if (tienda[i].clave==claveC){
						if (credito>tienda[i].precio){
						 	tienda[i].clave=clavesproductos[i];
							credito=credito-tienda[i].precio;
							cout<<setw(6)<<tienda[i].clave
	 					        <<setw(20)<<tienda[i].nombre
	 					        <<setw(20)<<tienda[i].marca<<endl;
						}else{
							cout<<"No puedes comprar el producto"<<endl;
						  }
			        }
		        }
				cout<<"Ahora tu credito es el siguiente:"<<credito<<"\n";
				system("pause");
		        system("cls");
	}
	
	int creditos(){
		char respuesta,s;
		cout<<"Tu Credito Actual es : "<<credito<<"\n";
		cout<<"\nAbonar saldo-->(b)\nRestar saldo-->(c)\nRegresar a menu principal(conta)";
		cin>>respuesta;
		if (respuesta=='b' || respuesta=='B'){
			cout<<"Cuanto deseas abonar";
		    cin>>abono;
		    credito=credito+abono;
		    cout<<"\n Saldo recargado="<<credito<<"\n";
	        }else if (respuesta=='c' || respuesta=='C'){
	        	cout<<"\n Cuanto deseas restar";
		        cin>>abono;
		        credito=credito-abono;
		        cout<<"\n Saldo restado="<<credito<<endl;
	        }else if (respuesta=='a' || respuesta=='A'){
	        	return 1;
		    }
    }

