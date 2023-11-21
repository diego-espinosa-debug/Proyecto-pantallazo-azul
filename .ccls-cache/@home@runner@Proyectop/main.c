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

void mostrarOpcionesPrincipal();
int validarInstruccion();
void switchPrincipal(int);
void switchCaso1(int);
void mostrarOpcionesCaso1();
int validarInstruccionCaso1();
void switchCaso3(int);
void mostrarOpcionesCaso3();
int validarInstruccionCaso3();

int main(){
  printf("██████╗ ██╗ ██████╗ ██████╗ ███████╗██╗  ██╗\n");
  printf("██╔══██╗██║██╔═══██╗██╔══██╗██╔════╝╚██╗██╔╝\n");
  printf("██████╔╝██║██║   ██║██║  ██║█████╗   ╚███╔╝ \n");
  printf("██╔══██╗██║██║   ██║██║  ██║██╔══╝   ██╔██╗ \n");
  printf("██████╔╝██║╚██████╔╝██████╔╝███████╗██╔╝ ██╗\n");
  printf("╚═════╝ ╚═╝ ╚═════╝ ╚═════╝ ╚══════╝╚═╝  ╚═╝\n\n");
  printf("Bienvenido al BioDex, el lugar donde podrás encontrar información sobre animales y vegetales en camino a la extinción.\n\n");

  int instruccion;
  do{
    mostrarOpcionesPrincipal(); // se mostraran todas las opciones disponibles en el menu principal 
    instruccion = validarInstruccion();
    switchPrincipal(instruccion); // ingresar a opciones del menu principal
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
      printf("debe ingresar una opcion valida\n\n");
      while(getchar() != '\n');
    } else {
        int instruccion;
        if(strlen(aux) == 1 &&  aux[0] >= '0' && aux[0] <= '5')/* hay que ver el maximo de instrucciones y remplazarlo en el 9 */{
        instruccion = atoi(aux);
        while(getchar() != '\n');
        return instruccion;
      } else{
          printf("debe ingresar una opcion valida\n\n");
          mostrarOpcionesPrincipal();
          while(getchar() != '\n');
      }
    }
  }  
}

void mostrarOpcionesPrincipal()
{
  printf("(1) Buscar especies\n");
  printf("(2) Ver informacion detallada de especies\n");
  printf("(3) Favoritos \n");
  printf("(4) Historial de búsqueda\n");
  printf("(0) si desea cerrar el programa\n");
}

void switchPrincipal(int instruccion)
{
  switch(instruccion){ //se recibe la opcion entre 1 y 4 del menu principal 
    case(1): // si es 1) buscar especie abre un submenu
      //mostrar lista y submenu
      printf("Escoja una opción: ");
      int instruccionCaso1;
      do{
        instruccionCaso1 = validarInstruccionCaso1();
        switchCaso1(instruccionCaso1);
      }while(instruccionCaso1 != 0);
      printf("\n");
      break;
    case(2): // si es 2) ver especies abre un submenu
      printf("\n");

      break;
    case(3): // si es 3) favoritos abre un submenu
      printf("\n");
      printf("Ingrese\n");
      int instruccionCaso3;
      do{
        instruccionCaso3 = validarInstruccionCaso3();
        switchCaso3(instruccionCaso3);
      }while(instruccionCaso3 != 0);

      break;
    case(4): // 
      printf("\n");
      //mostrar historial
      break;
    case(5): // si es 5) cerrar programa

      break;
  }
}

int validarInstruccionCaso1(){
  char aux[10];

  while(1){
    printf("Elija que catalogo desee ver\n\n");
    mostrarOpcionesCaso1();
    if(scanf("%9s", aux) != 1){
      printf("debe ingresar una opcion valida\n\n");
      while(getchar() != '\n');
    } else {
        int instruccion;
        if(strlen(aux) == 1 &&  aux[0] >= '0' && aux[0] <= '7'){
        instruccion = atoi(aux);
        while(getchar() != '\n');
        if(instruccion == 0) return 0;
        return instruccion;
      } else{
          printf("debe ingresar una opcion valida\n\n");
          while(getchar() != '\n');
      }
    }
  }  
}

void mostrarOpcionesCaso1(){

  printf("(1) Si desea ver animales en peligro de extinción\n");
  printf("(2) Si desea ver vegetales en peligro de extinción\n");
  printf("(3) Si desea ver animales terrestres en peligro de extinción\n");
  printf("(4) Si desea ver animales voladores en peligro de extinción\n");
  printf("(5) Si desea ver animales acuaticos en peligro de extinción\n");
  printf("(6) Si desea ver vegetales continentales en peligro de extinción\n");
  printf("(7) Si desea ver vegetales acuaticos en peligro de extinción\n");
  printf("(0) Si desea volver al menu principal\n");
}

void switchCaso1(int instruccionCaso1){
  switch(instruccionCaso1){
    case(1):
      //mostrarAnimalesPeligro();
     break;
    case(2):
      //mostrarVegetalesPerigro();
      break;
    case(3):
      //mostrarAnimalesTerrestres();
     break;
    case(4):
      //mostrarAnimalesVoladores();
     break;
    case(5):
      //mostrarAnimalesAcuaticos();
     break;
    case(6):
      //mostrarVegetalesContinentes();
     break;
    case(7):
      //mostrarVegetalesAcuaticos();
      break;
  }
}


int validarInstruccionCaso3(){
  char aux[10];

  while(1){
    mostrarOpcionesCaso3();
    if(scanf("%3s", aux) != 1){
      printf("debe ingresar una opcion valida\n\n");
      while(getchar() != '\n');
    } else {
        int instruccion;
        if(strlen(aux) == 1 &&  aux[0] >= '0' && aux[0] <= '3'){
        instruccion = atoi(aux);
        while(getchar() != '\n');
        if(instruccion == 0) return 0;
        mostrarOpcionesCaso3();
        return instruccion;
      } else{
          printf("debe ingresar una opcion valida\n\n");
          while(getchar() != '\n');
      }
    }
  }  
}

void mostrarOpcionesCaso3(){

  printf("(1)Si desea mostrar los favoritos\n(2)Si desea eliminar algun favorito\n(3)Si desea guardar algun favorito\n(0)Si desea volver al menu principal\n");
}

void switchCaso3(int instruccionCaso1){
  switch(instruccionCaso1){
    case(1):
      //mostrarFavoritos();
     break;
    case(2):
      //EliminarFavoritos();
      break;
    case(3):
      //agregarFavoritos();
      break;
  }
}