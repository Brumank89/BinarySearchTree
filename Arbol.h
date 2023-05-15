#include <iostream>
#include <string>
#include <sstream>
#include "Nodo.h"

class Arbol {
	private:
		Nodo *raiz;
		string NodosHermanos, NodosPadres, NodosHijos, NodosHojas;
	public:
		void inicializar() {
			raiz = NULL;
		}

		Nodo *GetRaiz() {
			return raiz;
		}
		bool EsVacio() {
			if(raiz == NULL) {
				return true;
			} else {
				return false;
			}
		}

		void insertar(int n) {
			Nodo *nuevo, *aux;
			nuevo = nuevo->Crear(n);
			if(EsVacio()) { //Cuando el arbol es vacio
				raiz = nuevo;
			} else {
				SiguienteNodo(raiz, nuevo); //Recorrido recursivo
			}
		}

		void SiguienteNodo(Nodo *aux, Nodo *nuevo) {
			if(aux == NULL) {
				return;
			} else {
				if(nuevo->GetIdentificador() < aux->GetIdentificador()) { //Recorrido a la izquierda
					if(aux->GetApuntadorIzq() != NULL) {
						SiguienteNodo(aux->GetApuntadorIzq(), nuevo);
					} else {
						aux->setApuntadorIzq(nuevo);
					}
				} else {
					if(nuevo->GetIdentificador() > aux->GetIdentificador()) { //Recorrido a la derecha
						SiguienteNodo(aux->GetApuntadorDer(), nuevo);
					} else {
						aux->setApuntadorDer(nuevo);
					}
				}
			}
		}

		int GetLongitud(Nodo *aux, int n, int longitud) {
			if(aux != NULL) {
				if(n != aux->GetIdentificador()) { //Recorrer el arbol
					if(n<aux->GetIdentificador() && aux->GetApuntadorIzq()!=NULL) {
						GetLongitud(aux->GetApuntadorIzq(), n, longitud + 1);
					} else {
						if(aux->GetApuntadorDer()!=NULL) {
							GetLongitud(aux->GetApuntadorDer(), n, longitud + 1);
						}
					}
				} else {
					if(n == aux->GetIdentificador()) {
						return longitud;
					} else {
						return -1;
					}
				}
			} else {
				return -1;
			}
		}

		//Profundidad
		int Profundidad(Nodo *aux) {
			if(aux != NULL) {
				int contIzq, contDer;
				contIzq = Profundidad(aux->GetApuntadorIzq()) + 1;
				contDer = Profundidad(aux->GetApuntadorDer()) + 1;
				if(contIzq > contDer) {
					return contIzq;
				} else {
					return contDer;
				}
			} else {
				return -1;
			}
		}
		
		int Altura(Nodo *aux){
			if(aux == NULL){
				return 0;
			}else{
				if(aux->GetApuntadorIzq() == NULL && aux->GetApuntadorDer() == NULL){
					return 1;
				}else{
					return max(Altura(aux->GetApuntadorIzq()), Altura(aux->GetApuntadorDer()))+1;
				}
			}
		}

		void PreOrden(Nodo *aux) {
			if(aux == NULL) { //caso base
				return;
			} else {
				//paso 1: imprime el dato del nodo actual
				cout<<aux->GetIdentificador()<<endl;
				//paso 2: recorre el arbol izquierdo
				PreOrden(aux->GetApuntadorIzq());
				//paso 3: recorre el arbol derecho
				PreOrden(aux->GetApuntadorDer());
			}
		}


		void Orden(Nodo *aux) {
			if(aux == NULL) {
				return;
			} else {
				//paso 1: recorre el arbol a la izquierda
				Orden(aux->GetApuntadorIzq());
				//paso 2: imprime el nodo
				cout<<aux->GetIdentificador();
				//paso 3:
				Orden(aux->GetApuntadorDer());
			}
		}

		void PostOrden(Nodo *aux) {
			if(aux == NULL) {
				return;
			} else {
				//paso 1: recorre el arbol a la izquierda
				PostOrden(aux->GetApuntadorIzq());
				//paso 2: recorre a la derecha
				PostOrden(aux->GetApuntadorDer());
				//paso 3:imprime el dato
				cout<<aux->GetIdentificador();
			}
		}

		string getNodosHermanos(Nodo *aux) {
			if(aux==NULL)
				return "";
			else {
				if(aux->GetApuntadorIzq() != NULL && aux->GetApuntadorDer() != NULL) {
					stringstream ssizq, ssder;
					ssizq<<aux->GetApuntadorIzq()->GetIdentificador();
					ssder<<aux->GetApuntadorDer()->GetIdentificador();
					if(NodosHermanos == "")
						NodosHermanos = "{" + ssizq.str() + " y " + ssder.str() + "}";
					else
						NodosHermanos = NodosHermanos + ", " + "{" + ssizq.str() + " y " + ssder.str() + "}";
				}
				getNodosHermanos(aux->GetApuntadorIzq());
				getNodosHermanos(aux->GetApuntadorDer());
			}
		}
		
		string getNodosPadres(Nodo *aux) {
			if(aux==NULL)
				return "";
			else {
				if(aux->GetApuntadorIzq() != NULL || aux->GetApuntadorDer() != NULL) {
					stringstream ssr;
					ssr<<aux->GetIdentificador();
					if(NodosPadres == "")
						NodosPadres = "[" + ssr.str() + "]";
					else
						NodosPadres = NodosPadres + ", " + "[" + ssr.str() + "]";
				}
				getNodosHermanos(aux->GetApuntadorIzq());
				getNodosHermanos(aux->GetApuntadorDer());
			}
		}
		
		string getNodosHijos(Nodo *aux) {
			if(aux==NULL)
				return "";
			else {
				if(aux->GetApuntadorIzq() != NULL) {
					stringstream ssIzq;
					ssIzq<<aux->GetIdentificador();
					if(NodosHijos == "")
						NodosHijos = "[" + ssIzq.str() + "]";
					else
						NodosHijos = NodosHijos + ", " + "[" + ssIzq.str() + "]";
				}
				
				if(aux->GetApuntadorDer() != NULL) {
					stringstream ssDer;
					ssDer<<aux->GetIdentificador();
					if(NodosHijos == "")
						NodosHijos = "[" + ssDer.str() + "]";
					else
						NodosHijos = NodosPadres + ", " + "[" + ssDer.str() + "]";
				}
				
				getNodosHijos(aux->GetApuntadorIzq());
				getNodosHijos(aux->GetApuntadorDer());
			}
		}
		
		string getNodosHojas(Nodo *aux) {
			if(aux==NULL)
				return "";
			else {
				if(aux->GetApuntadorIzq() == NULL && aux->GetApuntadorDer() == NULL) {
					stringstream ssr;
					ssr<<aux->GetIdentificador();
					if(NodosHojas == "")
						NodosHojas = "[" + ssr.str() + "]";
					else
					NodosHojas = NodosHojas + ", " + "[" + ssr.str() + "]";
				}
				getNodosHojas(aux->GetApuntadorIzq());
				getNodosHojas(aux->GetApuntadorDer());
			}
		}	
		
	
		void GetArbol(Nodo *aux, int cont) {
			if(aux==NULL) {
				return;
			} else {
				GetArbol(raiz->GetApuntadorDer(), cont+1);
				for(int i = 0; i<cont; i++) {
					cout<<" ";
				}
				cout<<aux->GetIdentificador()<<endl;
				GetArbol(raiz->GetApuntadorIzq(), cont+1);
			}
		}


};
