#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashmap.h"
#include "list.h"

//---------------------------------------------------------
//                estructuras
//---------------------------------------------------------

typedef struct animal{
  int ID; //1
  char nombre[100];
  char numero[4];
  char nombreCientifico[100];
  char alimentacion[100];//herbivoro, carnivoro, omnivoro
  char habitat[100];//terrestre, marino, aeroterrestre
  char tipo[100];//mamifero, ave, reptil, anfibio, peces, insecto
  char peso[10];
  char descripcion[500];//necesidades que tengan los animales y porque están en camino a la extinción. Educación sobre especies. Se informará de manera breve sobre el animal y como el usuario podría contribuir para mantener a salvo esta especie
}animal;

typedef struct vegetal{
  int ID; //2
  char nombre[100];
  char numero;
  char especie[100];//arbol, hongo
  char habitat[100];//acuatico, continental
  char descripcion[500];//necesidades que tengan los vegetales y porque están en camino a la extinción Educación sobre especies. Se informará de manera breve sobre el vegetal y como el usuario podría contribuir para mantener a salvo esta especie
}vegetal;

//--------------------------------------------------------------
//            Prototipo Funciones
//--------------------------------------------------------------

void creacionMapas();
const char *get_csv_field(char * , int );
void importarInfoBiodex(HashMap *,HashMap *, HashMap *, HashMap *, HashMap *, HashMap *, HashMap *, HashMap *, HashMap *, HashMap *, HashMap *, HashMap *, HashMap *);
void mostrarOpcionesPrincipal();
int validarInstruccion();
void switchPrincipal(int);
void switchCaso1(int);
void mostrarOpcionesCaso1();
int validarInstruccionCaso1();
void switchCaso3(int);
void mostrarOpcionesCaso3();
int validarInstruccionCaso3();
void switchCaso4(int);
void mostrarOpcionesCaso4();
int validarInstruccionCaso4();

//----------------------------------------------------------
//             Main principal
//----------------------------------------------------------

int main()
{
  printf("Bienvenido al BioDex, el lugar donde podrás encontrar información sobre animales y vegetales en camino a la extinción.\n\n");
  //funcion que crea los mapas del programa
  creacionMapas();
  //funcion que importe un archivo con animales y vegetales, ingresarlos en memoria.
  void importarInfoBiodex(HashMap * mapaAnimales,HashMap *mapaVegetales, HashMap *mapaAnimal_Marinos, HashMap *mapaAnimal_Terrestres, HashMap *mapaAnimal_Aeroterrestres, HashMap *mapaAnimal_Carnivoros, HashMap *mapaAnimal_Herbivoros, HashMap *mapaAnimal_Omnivoros, HashMap *mapaVegetal_Arbol, HashMap *mapaVegetal_Plantas, HashMap *mapaVegetal_Hongos, HashMap *mapaVegetal_Acuatico, HashMap *mapaVegetal_Continentales);
  int instruccion;
  do{
    mostrarOpcionesPrincipal();// se muestra todas las opciones del menu principal 
    instruccion = validarInstruccion(); //opcion usuario
    switchPrincipal(instruccion); // ingresar a opciones
  }while(instruccion != 0); //mientras no se escoja opcion "cerrar programa"
  printf("\nGracias por utilizar Biodex...");
  return EXIT_SUCCESS;
}

//------------------------------------------------------------
//                Funciones
//-----------------------------------------------------------

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
  printf("██████╗ ██╗ ██████╗ ██████╗ ███████╗██╗  ██╗\n");
  printf("██╔══██╗██║██╔═══██╗██╔══██╗██╔════╝╚██╗██╔╝\n");
  printf("██████╔╝██║██║   ██║██║  ██║█████╗   ╚███╔╝ \n");
  printf("██╔══██╗██║██║   ██║██║  ██║██╔══╝   ██╔██╗ \n");
  printf("██████╔╝██║╚██████╔╝██████╔╝███████╗██╔╝ ██╗\n");
  printf("╚═════╝ ╚═╝ ╚═════╝ ╚═════╝ ╚══════╝╚═╝  ╚═╝\n\n");
  printf("(1) ver especies\n");
  printf("(2) buscar informacion detallada de especies\n");
  printf("(3) Favoritos \n");
  printf("(4) Historial de búsqueda\n");
  printf("(0) si desea cerrar el programa\n");
}

void creacionMapas()
{
  //Crear HashMaps
  HashMap * mapaAnimales = createMap(20);
  HashMap * mapaVegetales = createMap(20);
  HashMap * mapaAnimal_Marinos = createMap(100);
  HashMap * mapaAnimal_Terrestres = createMap(100);
  HashMap * mapaAnimal_Aeroterrestres = createMap(100);
  HashMap * mapaAnimal_Carnivoros = createMap(100);
  HashMap * mapaAnimal_Herbivoros = createMap(100);
  HashMap * mapaAnimal_Omnivoros = createMap(100);
  HashMap * mapaVegetal_Arbol = createMap(100);
  HashMap * mapaVegetal_Plantas = createMap(100);
  HashMap * mapaVegetal_Hongos = createMap(100);
  HashMap * mapaVegetal_Acuatico = createMap(100);
  HashMap * mapaVegetal_Continentales = createMap(100);
  //Crear arbol binario
}
const char *get_csv_field(char * tmp, int k)
{
  int open_mark = 0;
  char* ret = (char*) malloc (1000*sizeof(char));
  int ini_i = 0, i = 0;
  int j=0;

  while(tmp[i+1]!= '\0'){
    if(tmp[i]=='\"'){
      open_mark = 1-open_mark;
      if(open_mark) ini_i = i+1;
      i++;
      continue;
    }
    if(open_mark || tmp[i] != ','){
      if(k==j) ret[i-ini_i] = tmp[i];
      i++;
      continue;
    }
    if(tmp[i]==','){
      if(k==j){
        ret[i-ini_i] = 0;
        return ret;
      }
      j++;
      ini_i = i+1;
    }
    i++;
  }
  if(k==j){
    ret[i-ini_i]=0;
    return ret;
  }

  return NULL;
}

void importarInfoBiodex(HashMap * mapaAnimales,HashMap *mapaVegetales, HashMap *mapaAnimal_Marinos, HashMap *mapaAnimal_Terrestres, HashMap *mapaAnimal_Aeroterrestres, HashMap *mapaAnimal_Carnivoros, HashMap *mapaAnimal_Herbivoros, HashMap *mapaAnimal_Omnivoros, HashMap *mapaVegetal_Arbol, HashMap *mapaVegetal_Plantas, HashMap *mapaVegetal_Hongos, HashMap *mapaVegetal_Acuatico, HashMap *mapaVegetal_Continentales)
{
  //abrir y leer archivo Animal
  char * archivoAnimal = "archivoAnimal.txt";
  FILE *archivo = fopen(archivoAnimal, "r");
  if(archivo == NULL){
    printf("***No se pudo abrir el archivo***\n");
    return;
  }
  
  //cadena para guardar la linea completa del archivo
  char linea[1000];
  fgets(linea, 1000, archivo); //lee primera linea
  while (fgets(linea, 1000, archivo) != NULL) //lee linea
    {
      //reservar memoria
      animal * nuevaEspecieAnimal = (animal *) malloc(sizeof(animal));
      //validacion memoria
      if(nuevaEspecieAnimal == NULL){
        printf("Error en el programa. Lo sentimos mucho, espere un momento o intentelo nuevamente.\n");
        exit(EXIT_FAILURE);
      }
      //--------------------------------------------------
      //leer: Numero, Nombre, nombre cientifico, alimentacion, Habitat, Tipo, Peso,
      for(int i = 0 ; i < 6 ; i++){
        nuevaEspecieAnimal->ID = 1;
        char * aux = (char *) get_csv_field(linea, i);//se obtiene cadena hasta la coma
        switch(i){
          case 0://Numero
            strcpy(nuevaEspecieAnimal->numero, aux);
            break;
          case 1://Nombre
            strcpy(nuevaEspecieAnimal->nombre, aux);
            break;
          case 2://nombreCientifico
            strcpy(nuevaEspecieAnimal->nombreCientifico, aux);
            break;
          case 3://alimentacion
            strcpy(nuevaEspecieAnimal->alimentacion, aux);
            break;
          case 4://Habitat
            strcpy(nuevaEspecieAnimal->habitat, aux);
            break;
          case 5://Tipo
            strcpy(nuevaEspecieAnimal->tipo, aux);
            break;
        }
      }
      //leer: Descripcion
      //nuevaEspecieAnimal->descripcion = ;//leer hasta el salto de linea
    }
  //ir guardando 
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
    case(4):
      printf("\n");
      printf("Ingrese\n");
      int instruccionCaso4;
      do{
        instruccionCaso4 = validarInstruccionCaso4();
        switchCaso4(instruccionCaso4);
      }while(instruccionCaso4 != 0);
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
int validarInstruccionCaso4(){
  char aux[10];

  while(1){
    mostrarOpcionesCaso4();
    if(scanf("%2s", aux) != 1){
      printf("debe ingresar una opcion valida\n\n");
      while(getchar() != '\n');
    } else {
        int instruccion;
        if(strlen(aux) == 1 &&  aux[0] >= '0' && aux[0] <= '2'){
        instruccion = atoi(aux);
        while(getchar() != '\n');
        if(instruccion == 0) return 0;
        mostrarOpcionesCaso4();
        return instruccion;
      } else{
          printf("debe ingresar una opcion valida\n\n");
          while(getchar() != '\n');
      }
    }
  }  
}

void mostrarOpcionesCaso4(){

  printf("(1)Si desea ver el historial\n(2)Si desea borrar el historial\n(0)Si desea volver al menu principal\n\n");
}

void switchCaso4(int instruccionCaso1){
  switch(instruccionCaso1){
    case(1):
      //mostrarHistorial();
     break;
    case(2):
      //EliminarHistorial();
      break;
  }
}