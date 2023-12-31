#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Ejercicio 1: Encuentra el Elemento Mayor
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y devuelva el valor más grande del arreglo.
*/
int findMax(int arr[], int size) { 
  int Mayor = arr[0];
  
  for(int i=1; i < size ;i++){
    if (arr[i] > Mayor){
      Mayor=arr[i];
    }
  }
  
  return Mayor; 
}
/*
Ejercicio 2: Invertir un Arreglo
Descripción: Escribe una función que tome un arreglo y su tamaño, y luego
invierta el orden de sus elementos.
*/
void reverseArray(int arr[], int size) {
  int comienzo=0, fin=size-1, aux;

  while (comienzo < fin){
    aux= arr[comienzo];
    arr[comienzo]= arr[fin];
    arr[fin]=aux;

    comienzo++;
    fin--;
  }
}

/*
Ejercicio 3: Filtrar Números Pares
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y luego devuelva un nuevo arreglo que contenga solo
los números pares del arreglo original.
*/
int *filterEvenNumbers(int arr[], int size, int *newSize) { 
  int pares=0, j=0;
  for (int i=0;i<size;i++){
    if (arr[i]%2==0){
      pares++;
    }
  }
  
  *newSize=pares;
  
  int *total=(int *)malloc(*newSize * sizeof(int));

  
  for(int i=0;i<size;i++){
    if (arr[i] % 2==0){
      total[j]=arr[i];
      j++;
    }
  }

  return total; 
}

/*
Ejercicio 4: Fusión de dos Arreglos Ordenados
Descripción: Escribe una función que tome dos arreglos
ordenados y sus tamaños, y luego fusione estos dos
arreglos en un tercer arreglo también ordenado.
*/
void mergeSortedArrays(int arr1[], int size1, int arr2[], int size2,int result[]) {
  int size3, cont=0;
  size3=size1+size2;
  for (int i=0;i<size1;i++){
    result[i]=arr1[i];
  }
    
  for(int j=size1;j<size3;j++){
    result[j]=arr2[cont];
      cont++;
    }
  
  
  
  for (int i=0;i < size3-1;i++){
    for(int j=0;j<size3-i-1;j++){
      if (result[j] > result[j+1]){
        int temp=result[j];
        result[j]=result[j+1];
        result[j+1]=temp;
      }
    }
  }

  
}

/*
Ejercicio 5: Comprobación de Ordenación
Descripción: Escribe una función que tome un arreglo y su tamaño,
y luego devuelva 1 si el arreglo está ordenado en orden ascendente,
  0 si no está ordenado, y -1 si está ordenado en orden descendente.
*/
int checkSorted(int arr[], int size) { 
  int contAsc=0, contDes=0;
  for (int i=0;i<size-1;i++){
    if (arr[i]<=arr[i+1]){
      contAsc++;
    }
    if (arr[i]>=arr[i+1]){
      contDes++;
    }

    if (contAsc==size-1){
      return 1;
    }
    
    if(contDes==size-1){
      return -1;
    }
    
  }
  
  return 0; 
}

/*
Ejercicio 6: Información de una Biblioteca
Descripción: Vamos a representar la información de una biblioteca. En la
biblioteca, hay libros, y cada libro tiene un autor. Queremos organizar esta
información utilizando estructuras anidadas en C. Escribe la función para
inicializar la información de un libro.
*/

typedef struct {
  char nombre[50];
  int anioNacimiento;
} Autor;

typedef struct {
  char titulo[100];
  Autor autor;
  int anioPublicacion;
} Libro;

void inicializarLibro(Libro *libro, const char *titulo, const char *nombreAutor,int anioNacimiento, int anioPublicacion) {
  strncpy(libro->titulo,titulo,sizeof(libro->titulo)-1);
  strncpy(libro->autor.nombre,nombreAutor,sizeof(libro->autor.nombre)-1);
  
  libro->anioPublicacion=anioPublicacion;
  libro->autor.anioNacimiento=anioNacimiento;
  
  
}

/*
Ejercicio 7: Lista enlazada de números
Descripción: Escribe una función que tome un arreglo de enteros y su tamaño, y
luego cree una lista enlazada usando la estructura Nodo. Cada nodo de la lista
debe contener un número del arreglo, y los nodos deben estar enlazados en el
mismo orden que los números aparecen en el arreglo. El último nodo de la lista
debe apuntar a NULL. La función debe devolver un puntero al primer nodo de la
lista enlazada.
Recuerda reservar memoria dinámica para cada nodo usando malloc.
  */

typedef struct nodo {
  int numero;
  struct nodo *siguiente; // puntero al siguiente nodo
} Nodo;

Nodo *crearListaEnlazada(int arr[], int size) { 
  Nodo *Inicio=NULL;
  Nodo *Final=NULL;

  for(int i=0;i<size;i++){
    Nodo *nuevo=(Nodo *) malloc(sizeof(Nodo));

    nuevo->numero=arr[i];
    nuevo->siguiente=NULL;

    if (Final==NULL){
      Inicio=nuevo;
      Final=nuevo;
    }else{
      Final->siguiente=nuevo;
      Final=nuevo;
    }
    
  }
  
  return Inicio; 
}
