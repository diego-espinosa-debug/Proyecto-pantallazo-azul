#include <stdio.h>
#include <stdlib.h>

typedef struct animal{
  char nombre[100];
  int numero;
  char especie[100];//herbivoro, carnivoro, omnivoro
  char habitat[100];//terrestre, acuatico, aereo
  char tipo[100];//mamifero, ave, reptil, anfibio, peces
  int peso;
  char descripcion[1000];//necesidades que tengan los animales y porque están en camino a la extinción 
//Exploración y Búsqueda. Se implementaran formas para que puedas buscar de manera específica el animal o vegetal que desee el usuario
//Educación sobre especies. Se informará de manera breve sobre el animal y como el usuario podría contribuir para mantener a salvo esta especie
}animal;

typedef struct vegetal{
  char nombre[100];
  int numero;
  char especie[100];//arbol, hongo
  char habitat[100];//acuatico, continental
  char descripcion[1000];//necesidades que tengan los vegetales y porque están en camino a la extinción 
//Exploración y Búsqueda. Se implementaran formas para que puedas buscar de manera específica el animal o vegetal que desee el usuario
//Educación sobre especies. Se informará de manera breve sobre el vegetal y como el usuario podría contribuir para mantener a salvo esta especie
}vegetal;

int main(){
  printf("**BioDex**\n\n");
  printf("Bienvenido al BioDex, el lugar donde podrás encontrar información sobre animales y vegetales en camino a la extinción.\n\n");
  
  //--------------------------------------------------------
  //hacer una funcion que importe un archivo con animales y vegetales, ingresarlos en memoria.
  //--------------------------------------------------------

  
  //luego ingresarlo en los distintos mapas creados a continuacion
  
  //---------------------------------------------
  //mapas ordenados para los distintos catalogos
  //---------------------------------------------

  //animales
  //herbivoro, carnivoro o omnivoro
  //terrestre, acuatico o volador

  //vegetales
  //arbol o hongo
  //acuatico o continental
  
  return EXIT_SUCCESS;
}