#include <iostream>
#include "Arbol.h"
using namespace std;

int main() {
	Arbol arb;
	int opc, n;
	arb.inicializar();
	do {
		system("cls");
		cout<<"Ingrese la opcion que desea: "<<endl;
		cout <<" 1.- Ingresar dato" <<endl;
		cout <<" 2.- Obtener longitud" <<endl;
		cout <<" 3.- Obtener nivel" <<endl;
		cout <<" 4.- Obtener altura" <<endl;
		cout <<" 5.- Recorrer por preorden" <<endl;
		cout <<" 6.- Recorrer por orden" <<endl;
		cout <<" 7.- Recorrer por postorden" <<endl;
		cout <<" 8.- Mostrar arbol" <<endl;
		cout <<" 9.- Salir" <<endl;
		cin>>opc;
		switch(opc) {
			case 1:
				cout<<"Selecciono 'Ingresar dato' "<<endl;
				cout<<"Ingrese el dato que desea guardar: ";
				cin>>n;
				arb.insertar(n);
				cout<<"El dato se ingreso"<<endl;
				system("pause");
				break;
			case 2:
				cout<<"Selecciono 'Obtener longitud' "<<endl;
				cout<<"Ingrese el dato que desea: ";
				cin>>n;
				cout<<"La longitud es: ";
				cout<<arb.GetLongitud(arb.GetRaiz(), n, 0);	
				cout<<endl;
				system("pause");
				break;
			case 3: 
				cout<<"Selecciono 'Obtener nivel' "<<endl;
				cout<<"El nivel es: ";
				cout<<arb.Profundidad(arb.GetRaiz());
				cout<<endl;
				system("pause");
				break;
				
			case 4:
				cout<<"Selecciono 'Obtener altura' "<<endl;
				cout<<"La altura es: ";
				cout<<arb.Altura(arb.GetRaiz());
				cout<<endl;
				system("pause");
				break;
			case 5:
				cout<<"Selecciono 'Recorrer por preorden' "<<endl;
				arb.PreOrden(arb.GetRaiz());
				cout<<endl;
				system("pause");
				break;
			case 6:
				cout<<"Selecciono 'Recorrer por orden' "<<endl;
				arb.Orden(arb.GetRaiz());
				cout<<endl;
				system("pause");
				break;
			case 7:
				cout<<"Selecciono 'Recorrer por postorden' "<<endl;
				arb.PostOrden(arb.GetRaiz());
				cout<<endl;
				system("pause");
				break;
			
				break;
				
			case 8:
				cout<<"Selecciono 'Mostrar arbol' "<<endl;
				cout<<"Nodos padres: ";
				arb.getNodosPadres(arb.GetRaiz());
				cout<<endl;
				cout<<"Nodos Hijos: ";
				arb.getNodosHijos(arb.GetRaiz());
				cout<<endl;
				cout<<"Nodos Hermanos: ";
				arb.getNodosHermanos(arb.GetRaiz());
				cout<<endl;
				cout<<"Hojas: ";
				arb.getNodosHojas(arb.GetRaiz());
				cout<<endl;
				system("pause");
				break;
		}

	} while (opc != 9);
	return 0;
}
