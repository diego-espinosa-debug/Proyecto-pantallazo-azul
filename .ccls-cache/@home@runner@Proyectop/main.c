#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
int validarInstruccion();
void mostrarOpcionesPrincipal();



int main(){
  printf("**BioDex**\n\n");
  printf("Bienvenido al BioDex, el lugar donde podrás encontrar información sobre animales y vegetales en camino a la extinción.\n\n");

  int instruccion;
  do{
    mostrarOpcionesPrincipal(); // se mostraran todas las opciones disponibles en el menu principal 
    instruccion = validarInstruccion();
    
    switch(instruccion){
      case(1):
        
        break;
      case(2):
        break;
      case(3):
      break;
      case(4):
      break;
      case(5):
      break;
    }
  }while(instruccion != 0);
  printf("\nGracias por utilizar Biodex...");

  
  //--------------------------------------------------------
  //hacer una funcion que importe un archivo con animales y vegetales, ingresarlos en memoria.
  //--------------------------------------------------------
  //importarInfoBiodex();
  
  //luego ingresarlo en los distintos mapas creados a continuacion
  
  //---------------------------------------------
  //mapas ordenados para los distintos catalogos
  //---------------------------------------------

  //animales
  //herbivoro, carnivoro o omnivoro
  //terrestre, acuatico o volador
  //mamifero, ave, reptil, anfibio, peces

  //vegetales
  //arbol o hongo
  //acuatico o continental

  //---------------------------------------------------
  //funcion para ingresar animales y vegetales en mapas
  //---------------------------------------------------
  return EXIT_SUCCESS;
}

int validarInstruccion(){
  char aux[10];
  
  while(1){
    printf("Que desea hacer: \n");

    if(scanf("%9s", aux) != 1){
      printf("debe ingresar una opcion valida\n");
      while(getchar() != '\n');
    } else {
        int instruccion;
        if(strlen(aux) == 1 &&  aux[0] >= '0' && aux[0] <= '9')/* hay que ver el maximo de instrucciones y remplazarlo en el 9 */{
        instruccion = atoi(aux);
        while(getchar() != '\n');
        return instruccion;
      } else{
          printf("debe ingresar una opcion valida\n");
          mostrarOpcionesPrincipal();
          while(getchar() != '\n');
      }
    }
  }  
}

void mostrarOpcionesPrincipal(){
  
  printf("(1) Si desea ver el catalogo de especies\n");
  printf("(2) Si desea ver informacion detallada del animal o vegetal\n");
  printf("(3) Si desea hacer una busqueda mas especifica \n");
  printf("(4) Si desea guardar un animal o vegetal en especifico\n");
  printf("(5) Si desea ver el historial de busquedad realizado\n");
  printf("(0) si desea cerrar el programa\n");
}