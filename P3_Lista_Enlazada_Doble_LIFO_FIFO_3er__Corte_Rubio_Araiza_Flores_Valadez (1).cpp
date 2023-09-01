#include <stdio.h>//libreria utlizada para imprimir y guardar datos 
#include <conio.h>
#include <windows.h>//libreria utilizada la limpieza de pantalla 

typedef struct nodo{
	int dato;
	struct nodo* siguiente;
	struct nodo* atras;
}nodo;
//Programa Creado por Julio Leonel Rubio Ramirez, Bryan Josue Flores Gonzales
//Carlos Ernesto Valadez Beristain y Jose de Jesus Araiza Rodriguez
nodo* primero = NULL;
nodo* ultimo = NULL;
//Funciones Necesarias a Utilizar
void insertarNodo();
void eliminarNodo();
void desplegarListaPU();
void desplegarListaUP();

int main(){
	int opcionMenu = 0;
	do{
	//Creacion del Menu 
		printf("\nLISTA DOBLE");
	
		printf("\n 1. Agregar");
		printf("\n 2. Eliminar");
		printf("\n 3. Mostrar lista de primero a ultimo");
		printf("\n 4. Mostrar lista de ultimo a primero");
		printf("\n 5. Salir\n");
	
				
		
		printf("\n\n Escoja una Opcion: ");
		scanf("%d", &opcionMenu);
		switch(opcionMenu){
			case 1:
				system("cls"); //limpiar pantalla 
				
				printf("\n\n AGREGAR NODO EN LA LISTA \n\n");
				
				insertarNodo();
				
				 system("pause");//Sirve para hacer una pequeña pausa en el programa
				
				break;
				
			case 2:
				system("cls");//limpiar pantalla
				
				printf("\n\n ELIMINAR UN NODO DE LA LISTA \n\n");
				
				eliminarNodo();
				
				system("pause");//Sirve para hacer una pequeña pausa en el programa
				
				break;
				
			case 3:	
				system("cls");//limpiar pantalla
				
				printf("\n\n DESPLEGAR LISTA DEL PRIMERO AL UTLIMO\n\n");
				
				desplegarListaPU();
				
				system("pause");//Sirve para hacer una pequeña pausa en el programa
				
				break;
				
			case 4:
				
				system("cls");//limpiar pantalla
				
				printf("\n\n DESPLEGAR LISTA DEL UTLIMO AL PRIMERO\n\n");
				
				desplegarListaUP();
				
				system("pause");//Sirve para hacer una pequeña pausa en el programa
				
				break;
				
			case 5:
				
				printf("\nPrograma finalizado...\n");
				
				system("pause");//Sirve para hacer una pequeña pausa en el programa
				
				break;
				
			default:
				printf("\n\n Opcion No Valida \n\n");
				
				system("pause");//Sirve para hacer una pequeña pausa en el programa	
		}
		system("cls");//limpiar pantalla
	}while(opcionMenu != 5);

}


void insertarNodo(){
	//Esta Funcion se utiliza para poder ingresar datos al nodo 
	nodo* nuevo = (nodo*)malloc(sizeof(nodo));
	printf(" Ingrese el dato que contendra el nuevo Nodo: ");
	scanf("%d", &nuevo->dato);
	
	if(primero==NULL){
		primero = nuevo;
		primero->siguiente = NULL;
		primero->atras = NULL;
		ultimo = primero;
	}else{
		ultimo->siguiente = nuevo;
		nuevo->siguiente = NULL;
		nuevo->atras = ultimo;
		ultimo = nuevo;
	}

	printf("\nNOTA: si desea agregar mas datos en la lista siga presionando esa opcion\n");
}



void eliminarNodo(){
	//Esta funcion sirve para eliminar del primero al ultimo dato
	nodo* actual;
	actual = primero;
	nodo* anterior;
	anterior = NULL;
	int encontrado = 0;

	if(primero!=NULL){
		while(actual != NULL && encontrado != 1){
			
			if(actual->dato == actual->dato){
				
				if(actual==primero){
					primero = primero->siguiente;
					primero->atras = NULL;
				}else if(actual==ultimo){
					anterior->siguiente = NULL;
					ultimo = anterior;
				}else{
					anterior->siguiente = actual->siguiente;
					actual->siguiente->atras = anterior;
				}
				printf("\n Nodo eliminado con exito\n\n");
				
				encontrado = 1;
			}
			anterior = actual;
			actual = actual->siguiente;
		}
	
	}
	else
	printf("\n La lista se encuentra vacia\n\n");//Por si no se ingreso nada a la lista
	
}

void desplegarListaPU(){
	//Esta funcion te muestra los datos que ingresaste del primero al ultimo dato
	nodo* actual;
	actual = primero;
	if(primero!=NULL){
		while(actual != NULL){
			printf("\n %d\n", actual->dato);
			actual = actual->siguiente;
		}
	}else{
		printf("\n La lista se encuentra vacia\n\n");//Por si no se ingreso nada a la lista
	}
}

void desplegarListaUP(){
	//Esta funcion te muestra los datos que ingresaste del ultimo dato al primer dato
	nodo* actual;
	actual = ultimo;
	if(primero!=NULL){
		
		while(actual != NULL){
			printf("\n %d\n", actual->dato);
			actual = actual->atras;
		}
	}else{
		printf("\n La lista se encuentra vacia\n\n");//Por si no se ingreso nada a la lista 
	}	
}
