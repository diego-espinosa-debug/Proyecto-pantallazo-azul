#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashmap.h"
#include "list.h"
#include "treemap.h"
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
  char descripcion[500];//necesidades que tengan los animales y porque están en camino a la extinción. Educación sobre especies. Se informará de manera breve sobre el animal y como el usuario podría contribuir para mantener a salvo esta especie
}animal;

typedef struct vegetal{
  int ID; //2
  char nombre[100];
  char numero[4];
  char nombreCientifico[100];
  char especie[100];//arbol, hongo, planta
  char habitat[100];//acuatico, continental
  char descripcion[500];//necesidades que tengan los vegetales y porque están en camino a la extinción Educación sobre especies. Se informará de manera breve sobre el vegetal y como el usuario podría contribuir para mantener a salvo esta especie
}vegetal;

//--------------------------------------------------------------
//            Prototipo Funciones
//--------------------------------------------------------------

//void CrearBiodex();
const char *get_csv_field(char * , int );
void importarInfoBiodex(TreeMap *,HashMap *,HashMap *, HashMap *, HashMap *, HashMap *, HashMap *, HashMap *, HashMap *, HashMap *, HashMap *, HashMap *, HashMap *);
void mostrarOpcionesPrincipal();
int validarInstruccion();
void switchPrincipal(int,List *,TreeMap *,HashMap *,HashMap *, HashMap *, HashMap *, HashMap *, HashMap *, HashMap *, HashMap *, HashMap *, HashMap *, HashMap *, HashMap *);
void switchCaso1(int, HashMap *,HashMap *, HashMap *, HashMap *, HashMap *, HashMap *, HashMap *, HashMap *, HashMap *, HashMap *, HashMap *, HashMap *);

void mostrarOpcionesCaso1();
int validarInstruccionCaso1();
void switchCaso2(int,TreeMap *);
void mostrarOpcionesCaso2();
int validarInstruccionCaso2();

void busquedaNumerica(TreeMap *);
void busquedaPalabra(TreeMap * );
char Asegurar3digitos();
int validarInstruccionFav();
void switchCaso3(int, List *, TreeMap *);
void mostrarOpcionesCaso3();
int validarInstruccionCaso3();
void switchCaso4(int);
void mostrarOpcionesCaso4();
int validarInstruccionCaso4();
int lower_than_int(void *, void *);
void mostrarFavoritos(List *);
void agregarFavoritos(int,List *, TreeMap *);
void eliminarFavoritos(List *);
void busquedaNumericaFav(List *, TreeMap *);
void busquedaPalabraFav(List *, TreeMap *);
void mostrarOpcionesFav();
//----------------------------------------------------------
//             Main principal
//----------------------------------------------------------

int main()
{
  printf("Bienvenido al BioDex, el lugar donde podrás encontrar información sobre animales y vegetales en camino a la extinción.\n\n");
  //funcion que crea los mapas del programa e importa la informacion de los archivos a los mapas
  //CrearBiodex();
  HashMap * Animales = createMap(20);
  HashMap * Vegetales = createMap(20);
  HashMap * Ani_Marinos = createMap(100);
  HashMap * Ani_Terrestres = createMap(100);
  HashMap * Ani_Aeroterrestres = createMap(100);
  HashMap * Ani_Carnivoros = createMap(100);
  HashMap * Ani_Herbivoros = createMap(100);
  HashMap * Ani_Omnivoros = createMap(100);
  HashMap * Veg_Plantas = createMap(100);
  HashMap * Veg_Hongos = createMap(100);
  HashMap * Veg_Acuatico = createMap(100);
  HashMap * Veg_Continentales = createMap(100);
  TreeMap * BinarioGeneral = createTreeMap(lower_than_int);
  List * listaFav = createList();
  
  
  
  importarInfoBiodex(BinarioGeneral, Animales, Vegetales, Ani_Marinos, Ani_Terrestres, Ani_Aeroterrestres, Ani_Carnivoros, Ani_Herbivoros, Ani_Omnivoros, Veg_Plantas, Veg_Hongos, Veg_Acuatico, Veg_Continentales);
  int instruccion; //opcion usuario
  do{
    mostrarOpcionesPrincipal();// se muestra todas las opciones del menu principal 
    instruccion = validarInstruccion(); //validar opcion
    switchPrincipal(instruccion,listaFav,BinarioGeneral,Animales, Vegetales, Ani_Marinos, Ani_Terrestres, Ani_Aeroterrestres, Ani_Carnivoros, Ani_Herbivoros, Ani_Omnivoros, Veg_Plantas, Veg_Hongos, Veg_Acuatico, Veg_Continentales); // ingresar a opciones
  }while(instruccion != 0); //mientras no se escoja opcion "cerrar programa"
  printf("\nGracias por utilizar Biodex...");
  return EXIT_SUCCESS;
}

//------------------------------------------------------------
//                Funciones
//-----------------------------------------------------------

int lower_than_int(void* key1, void* key2){
    int k1 = *((int*) (key1));
    int k2 = *((int*) (key2));
    return k1<k2;
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
  printf("██████╗ ██╗ ██████╗ ██████╗ ███████╗██╗  ██╗\n");
  printf("██╔══██╗██║██╔═══██╗██╔══██╗██╔════╝╚██╗██╔╝\n");
  printf("██████╔╝██║██║   ██║██║  ██║█████╗   ╚███╔╝ \n");
  printf("██╔══██╗██║██║   ██║██║  ██║██╔══╝   ██╔██╗ \n");
  printf("██████╔╝██║╚██████╔╝██████╔╝███████╗██╔╝ ██╗\n");
  printf("╚═════╝ ╚═╝ ╚═════╝ ╚═════╝ ╚══════╝╚═╝  ╚═╝\n\n");
  printf("(1) Ver especies\n");
  printf("(2) Buscar informacion detallada de especies\n");
  printf("(3) Favoritos \n");
  printf("(4) Historial de búsqueda\n");
  printf("(0) Si desea cerrar el programa\n");
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
    if(open_mark || tmp[i] != ';'){
      if(k==j) ret[i-ini_i] = tmp[i];
      i++;
      continue;
    }
    if(tmp[i]==';'){
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

void importarInfoBiodex(TreeMap * BinarioGeneral, HashMap * mapaAnimales,HashMap *mapaVegetales, HashMap *mapaAnimal_Marinos, HashMap *mapaAnimal_Terrestres, HashMap *mapaAnimal_Aeroterrestres, HashMap *mapaAnimal_Carnivoros, HashMap *mapaAnimal_Herbivoros, HashMap *mapaAnimal_Omnivoros, HashMap *mapaVegetal_Plantas, HashMap *mapaVegetal_Hongos, HashMap *mapaVegetal_Acuatico, HashMap *mapaVegetal_Continentales)
{
  //abrir y leer archivo Animal
  char * archivoAnimal = "archivoAnimal.csv";
  FILE *archivo = fopen(archivoAnimal, "r");
  if(archivo == NULL){
    printf("***No se pudo abrir el archivo***\n");
    return;
  }
  
  //cadena para guardar la linea completa del archivo
  char lineaA[1000];
  fgets(lineaA, 1000, archivo); //lee primera linea
  while (fgets(lineaA, 1000, archivo) != NULL) //lee linea
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
      nuevaEspecieAnimal->ID = 1;
      for(int i = 0 ; i < 7 ; i++){
        char * aux = (char *) get_csv_field(lineaA, i);//se obtiene cadena hasta la coma
        switch(i){
          case 0://Numero
            strcpy(nuevaEspecieAnimal->numero, aux);
            //printf("num: %s\n", nuevaEspecieAnimal->numero);
            
            break;
          case 1://Nombre
            strcpy(nuevaEspecieAnimal->nombre, aux);
            //printf("Nombre: %s\n", nuevaEspecieAnimal->nombre);
            break;
          case 2://nombreCientifico
            strcpy(nuevaEspecieAnimal->nombreCientifico, aux);
            //printf("Nombre Cientifico: %s\n", nuevaEspecieAnimal->nombreCientifico);
            break;
          case 3://alimentacion
            strcpy(nuevaEspecieAnimal->alimentacion, aux);
            //printf("Alimentacion: %s\n", nuevaEspecieAnimal->alimentacion);
            break;
          case 4://Habitat
            strcpy(nuevaEspecieAnimal->habitat, aux);
            //printf("Habitat: %s\n", nuevaEspecieAnimal->habitat);
            break;
          case 5://Tipo
            strcpy(nuevaEspecieAnimal->tipo, aux);
            //printf("Tipo: %s\n", nuevaEspecieAnimal->tipo);
            break;
          case 6:
          // Encuentra la posición de la coma
            strcpy(nuevaEspecieAnimal->descripcion, aux);//leer hasta el salto de linea
            //printf("Descripcion: %s\n", nuevaEspecieAnimal->descripcion);
            break;
        }
      }
      insertTreeMap(BinarioGeneral, nuevaEspecieAnimal->numero, nuevaEspecieAnimal);
      insertMap(mapaAnimales, nuevaEspecieAnimal->numero, nuevaEspecieAnimal);
      if(strcmp(nuevaEspecieAnimal->alimentacion, "Herbivoro") == 0){ 
        insertMap(mapaAnimal_Herbivoros, nuevaEspecieAnimal->numero, nuevaEspecieAnimal);
      }else if(strcmp(nuevaEspecieAnimal->alimentacion, "Carnivoro") == 0){ 
        insertMap(mapaAnimal_Carnivoros, nuevaEspecieAnimal->numero, nuevaEspecieAnimal);
      }else if(strcmp(nuevaEspecieAnimal->alimentacion, "Omnivoro") == 0) insertMap(mapaAnimal_Omnivoros, nuevaEspecieAnimal->numero, nuevaEspecieAnimal);

      
      if(strcmp(nuevaEspecieAnimal->habitat, "Marino") == 0){
        insertMap(mapaAnimal_Marinos, nuevaEspecieAnimal->numero, nuevaEspecieAnimal);
      }else if(strcmp(nuevaEspecieAnimal->habitat, "Terrestre") == 0) {
        insertMap(mapaAnimal_Terrestres, nuevaEspecieAnimal->numero, nuevaEspecieAnimal);
      }else if(strcmp(nuevaEspecieAnimal->habitat, "Aeroterrestre") == 0) insertMap(mapaAnimal_Aeroterrestres, nuevaEspecieAnimal->numero, nuevaEspecieAnimal);
      
    }
  fclose(archivo);
  
  //-----------------
  //archivo Vegetales
  //-----------------
  
  char * archivoVegetal = "archivoVegetal.csv";
  FILE *archivo2 = fopen(archivoVegetal, "r");
  if(archivo2 == NULL){
    printf("***No se pudo abrir el archivo***\n");
    return;
  }
  //cadena para guardar la linea completa del archivo
  char lineaV[1000];
  fgets(lineaV, 1000, archivo2); //lee primera linea
  while (fgets(lineaV, 1000, archivo2) != NULL) //lee linea
    {
      //reservar memoria
      vegetal * nuevaEspecieVegetal = (vegetal *) malloc(sizeof(vegetal));
      //validacion memoria
      if(nuevaEspecieVegetal == NULL){
        printf("Error en el programa. Lo sentimos mucho, espere un momento o intentelo nuevamente.\n");
        exit(EXIT_FAILURE);
      }
      //--------------------------------------------------
      //leer: Numero, Nombre, Nombre científico, Habitat, Especie, 
      for(int i = 0 ; i < 6 ; i++){
        nuevaEspecieVegetal->ID = 2;
        char * aux2 = (char *) get_csv_field(lineaV, i);//se obtiene cadena hasta la coma
        switch(i){
          case 0://Numero
            strcpy(nuevaEspecieVegetal->numero, aux2);
            //printf("num: %s\n", nuevaEspecieVegetal->numero);
            break;
          case 1://Nombre
            strcpy(nuevaEspecieVegetal->nombre, aux2);
            //printf("Nombre: %s\n", nuevaEspecieVegetal->nombre);
            break;
          case 2://nombreCientifico
            strcpy(nuevaEspecieVegetal->nombreCientifico, aux2);
            //printf("Nombre Cientifico: %s\n", nuevaEspecieVegetal->nombreCientifico);
            break;
          case 3://Habitat
            strcpy(nuevaEspecieVegetal->habitat, aux2);
            //printf("Habitat: %s\n", nuevaEspecieVegetal->habitat);
            break;
          case 4://especie
            strcpy(nuevaEspecieVegetal->especie, aux2);
            //printf("Especie: %s\n", nuevaEspecieVegetal->especie);
            break;
          case 5:
            strcpy(nuevaEspecieVegetal->descripcion, aux2);
            //printf("Descripcion: %s\n", nuevaEspecieVegetal->descripcion);
            break;
        }
     }
    //ir guardando en el mapa
    insertTreeMap(BinarioGeneral, nuevaEspecieVegetal->numero, nuevaEspecieVegetal);
    insertMap(mapaVegetales, nuevaEspecieVegetal->numero, nuevaEspecieVegetal);
    if(strcmp(nuevaEspecieVegetal->habitat, "Acuatico") == 0){
      insertMap(mapaVegetal_Acuatico, nuevaEspecieVegetal->numero, nuevaEspecieVegetal);
    }else if(strcmp(nuevaEspecieVegetal->habitat, "Continental") == 0)
      insertMap(mapaVegetal_Continentales, nuevaEspecieVegetal->numero, nuevaEspecieVegetal);

    if(strcmp(nuevaEspecieVegetal->especie, "Planta") == 0){
      insertMap(mapaVegetal_Plantas, nuevaEspecieVegetal->numero, nuevaEspecieVegetal);
    }else if(strcmp(nuevaEspecieVegetal->especie, "Hongo") == 0) insertMap(mapaVegetal_Hongos, nuevaEspecieVegetal->numero, nuevaEspecieVegetal);
  }
  fclose(archivo2);
}

void switchPrincipal(int instruccion,List *listaFav,TreeMap * BinarioGeneral,HashMap * mapaAnimales,HashMap *mapaVegetales, HashMap *mapaAnimal_Marinos, HashMap *mapaAnimal_Terrestres, HashMap *mapaAnimal_Aeroterrestres, HashMap *mapaAnimal_Carnivoros, HashMap *mapaAnimal_Herbivoros, HashMap *mapaAnimal_Omnivoros, HashMap *mapaVegetal_Plantas, HashMap *mapaVegetal_Hongos, HashMap *mapaVegetal_Acuatico, HashMap *mapaVegetal_Continentales){
  switch(instruccion){ //se recibe la opcion entre 1 y 4 del menu principal 
    case(1): // si es 1) buscar especie abre un submenu
      //mostrar lista y submenu
      printf("Escoja una opción: ");
      int instruccionCaso1;
      do{
        instruccionCaso1 = validarInstruccionCaso1();
        switchCaso1(instruccionCaso1, mapaAnimales, mapaVegetales, mapaAnimal_Marinos, mapaAnimal_Terrestres, mapaAnimal_Aeroterrestres, mapaAnimal_Carnivoros, mapaAnimal_Herbivoros, mapaAnimal_Omnivoros, mapaVegetal_Plantas, mapaVegetal_Hongos, mapaVegetal_Acuatico, mapaVegetal_Continentales);
      }while(instruccionCaso1 != 0);
      printf("\n");
      break;
    case(2): // si es 2) ver especies abre un submenu
      printf("");
      int instruccionCaso2;
      do{
        int instruccionCaso2 = validarInstruccionCaso2();
        switchCaso2(instruccionCaso2,BinarioGeneral);
      }while(instruccionCaso2 != 0);
      printf("\n");

      break;
    case(3): // si es 3) favoritos abre un submenu
      printf("\n");
      printf("Ingrese\n");
      int instruccionCaso3;
      do{
        instruccionCaso3 = validarInstruccionCaso3();
        switchCaso3(instruccionCaso3,listaFav,BinarioGeneral);
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
        if(strlen(aux) == 1 &&  aux[0] >= '0' && aux[0] <= '9'){
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

  printf("(1) Ver todo animal en peligro de extinción\n");
  printf("(2) Ver todo vegetal en peligro de extinción\n");
  printf("(3) Ver animales terrestres en peligro de extinción\n");
  printf("(4) Ver animales voladores en peligro de extinción\n");
  printf("(5) Ver animales acuaticos en peligro de extinción\n");
  printf("(6) Ver vegetales continentales en peligro de extinción\n");
  printf("(7) Ver vegetales acuaticos en peligro de extinción\n");
  printf("(8) Ver vegetales hongos en peligro de extinción\n");
  printf("(9) Ver vegetales plantas en peligro de extinción\n");
  //printf("(10) Ver vegetales arboles en peligro de extinción\n");
  printf("(0) Volver al menu principal\n");
}

int verMas(){
  printf("(1)Si desea ver mas especies\n(0)si desea volver al menu principal\n");
  int instruccion;
  
  do{
    scanf("%d", &instruccion);
  }while(instruccion!=1 || instruccion!=0);
  return instruccion;
}

void switchCaso1(int instruccionCaso1,HashMap * mapaAnimales,HashMap *mapaVegetales, HashMap *mapaAnimal_Marinos, HashMap *mapaAnimal_Terrestres, HashMap *mapaAnimal_Aeroterrestres, HashMap *mapaAnimal_Carnivoros, HashMap *mapaAnimal_Herbivoros, HashMap *mapaAnimal_Omnivoros, HashMap *mapaVegetal_Plantas, HashMap *mapaVegetal_Hongos, HashMap *mapaVegetal_Acuatico, HashMap *mapaVegetal_Continentales){
  Pair * dato;
  switch(instruccionCaso1){
    case 0:
      return;
    case(1):
      //mostrarAnimalesPeligro();
      printf("--------------\n");
      printf("Ver *Fauna*\n");
      printf("--------------\n\n");
      dato = firstMap(mapaAnimales);
      while(1)
        {
          if(dato == NULL){
            printf("\nNo hay mas animales en peligro de extincion de este catalogo, pero puede conocer mas acerca de otros.\n\n");
            break;
          }
          
          for(int i = 0; i < 3; i++){
            animal * especie = dato->value;
            
            printf("-Numero: %s", especie->numero);
            printf(" - %s\n", especie->nombre);
            //printf("-Nombre cinetifico: %s\n", especie->nombreCientifico);
            //printf("-Tipo: %s\n", especie->tipo);
            //printf("-Habitat: %s\n", especie->habitat);
            //printf("-Alimentacion: %s\n", especie->alimentacion);
            //printf("-Mas sobre la especie: %s\n***\n", especie->descripcion);
            dato = nextMap(mapaAnimales);
            if(dato == NULL) break;
          }
          if(dato == NULL){
            printf("\nNo hay mas animales en peligro de extincion de este catalogo, pero puede conocer mas acerca de otros.\n\n");
            return;
          }
          int opcionUsuario;
          printf("\n(1)Si desea ver mas especies\n(0)si desea volver al menu principal\n");
          printf("Opcion: ");
          scanf("%d", &opcionUsuario);
          if(opcionUsuario == 0) return;
          
        }
      break;
    case(2):
      printf("--------------\n");
      printf("Ver *flora*\n");
      printf("--------------\n\n");
      dato = firstMap(mapaVegetales);
      while(1)
        {
          if(dato == NULL){
            printf("\nNo hay mas flora en peligro de extincion de este catalogo, pero puede conocer mas acerca de otros.\n\n");
            break;
          }

          for(int i = 0; i < 3; i++){
            animal * especie = dato->value;
            printf("-Numero: %s", especie->numero);
            printf(" - %s\n", especie->nombre);
            //printf("-Nombre cinetifico: %s\n", especie->nombreCientifico);
            //printf("-Tipo: %s\n", especie->tipo);
            //printf("-Habitat: %s\n", especie->habitat);
            //printf("-Alimentacion: %s\n", especie->alimentacion);
            //printf("-Mas sobre la especie: %s\n***\n", especie->descripcion);
            dato = nextMap(mapaVegetales);
            if(dato == NULL) break;
          }
            if(dato == NULL){
              printf("\nNo hay mas animales en peligro de extincion de este catalogo, pero puede conocer mas acerca de otros.\n\n");
              return;
            }
          int opcionUsuario;
          printf("\n(1)Si desea ver mas especies\n(0)si desea volver al menu principal\n");
          printf("Opcion: ");
          scanf("%d", &opcionUsuario);
          if(opcionUsuario == 0) return;
        }
      break;
    case(3): // *******************
      printf("--------------\n");
      printf("Ver *Animales Terrestres*\n");
      printf("--------------\n\n");
      dato = firstMap(mapaAnimal_Terrestres);
      while(1)
        {
          if(dato == NULL){
            printf("\nNo hay mas animales en peligro de extincion de este catalogo, pero puede conocer mas acerca de otros.\n\n");
            break;
          }

          for(int i = 0; i < 3; i++){
            animal * especie = dato->value;
            if(strcmp(especie->habitat, "Terrestre") == 0){
              printf("-Numero: %s", especie->numero);
              printf(" - %s\n", especie->nombre);
            }
            //printf("-Nombre cinetifico: %s\n", especie->nombreCientifico);
            //printf("-Tipo: %s\n", especie->tipo);
            //printf("-Habitat: %s\n", especie->habitat);
            //printf("-Alimentacion: %s\n", especie->alimentacion);
            //printf("-Mas sobre la especie: %s\n***\n", especie->descripcion);
            dato = nextMap(mapaAnimal_Terrestres);
            if(dato == NULL) break;
          }
          if(dato == NULL){
            printf("\nNo hay mas animales en peligro de extincion de este catalogo, pero puede conocer mas acerca de otros.\n\n");
            return;
          }
          int opcionUsuario;
          printf("\n(1)Si desea ver mas especies\n(0)si desea volver al menu principal\n");
          printf("Opcion: ");
          scanf("%d", &opcionUsuario);
          if(opcionUsuario == 0) return;

        }
      //mostrarAnimalesTerrestres();
     break;
    case(4):
      printf("------------------------\n");
      printf("Ver *Animales Voladores*\n");
      printf("------------------------\n\n");
      dato = firstMap(mapaAnimal_Aeroterrestres);
      while(1)
        {
          if(dato == NULL){
            printf("\nNo hay mas animales en peligro de extincion de este catalogo, pero puede conocer mas acerca de otros.\n\n");
            break;
          }

          for(int i = 0; i < 3; i++){
            animal * especie = dato->value;

            if(strcmp(especie->habitat, "Aeroterrestre") == 0){
              printf("-Numero: %s", especie->numero);
              printf(" - %s\n", especie->nombre);
            }
            //printf("-Nombre cinetifico: %s\n", especie->nombreCientifico);
            //printf("-Tipo: %s\n", especie->tipo);
            //printf("-Habitat: %s\n", especie->habitat);
            //printf("-Alimentacion: %s\n", especie->alimentacion);
            //printf("-Mas sobre la especie: %s\n***\n", especie->descripcion);
            dato = nextMap(mapaAnimal_Aeroterrestres);
            if(dato == NULL) break;
          }
          if(dato == NULL){
            printf("\nNo hay mas animales en peligro de extincion de este catalogo, pero puede conocer mas acerca de otros.\n");
            return;
          }
          int opcionUsuario;
          printf("\n(1)Si desea ver mas especies\n(0)si desea volver al menu principal\n");
          printf("Opcion: ");
          scanf("%d", &opcionUsuario);
          if(opcionUsuario == 0) return;

        }
      //mostrarAnimalesVoladores();
     break;
    case(5):
      printf("------------------------\n");
      printf("Ver *Animales Marinos*\n");
      printf("------------------------\n\n");
      dato = firstMap(mapaAnimal_Marinos);
      while(1)
        {
          if(dato == NULL){
            printf("\nNo hay mas animales en peligro de extincion de este catalogo, pero puede conocer mas acerca de otros.\n\n");
            break;
          }

          for(int i = 0; i < 3; i++){
            animal * especie = dato->value;

            if(strcmp(especie->habitat, "Marino") == 0){
              printf("-Numero: %s", especie->numero);
              printf(" - %s\n", especie->nombre);
            }
            //printf("-Nombre cinetifico: %s\n", especie->nombreCientifico);
            //printf("-Tipo: %s\n", especie->tipo);
            //printf("-Habitat: %s\n", especie->habitat);
            //printf("-Alimentacion: %s\n", especie->alimentacion);
            //printf("-Mas sobre la especie: %s\n***\n", especie->descripcion);
            dato = nextMap(mapaAnimal_Marinos);
            if(dato == NULL) break;
          }
          if(dato == NULL){
            printf("\nNo hay mas animales en peligro de extincion de este catalogo, pero puede conocer mas acerca de otros.\n");
            return;
          }
          int opcionUsuario;
          printf("\n(1)Si desea ver mas especies\n(0)si desea volver al menu principal\n");
          printf("Opcion: ");
          scanf("%d", &opcionUsuario);
          if(opcionUsuario == 0) return;
        }
      //mostrarAnimalesAcuaticos();
     break;
    case(6):
      printf("-----------------------\n");
      printf("Ver *flora Continental*\n");
      printf("-----------------------\n\n");
      dato = firstMap(mapaVegetal_Continentales);
      while(1)
        {
          if(dato == NULL){
            printf("\nNo hay mas flora en peligro de extincion de este catalogo, pero puede conocer mas acerca de otros.\n\n");
            break;
          }

          for(int i = 0; i < 3; i++){
            vegetal * especie = dato->value;
            if(strcmp(especie->habitat, "Continental") == 0){
              printf("-Numero: %s", especie->numero);
              printf(" - %s\n", especie->nombre);
            }
            //printf("-Nombre cinetifico: %s\n", especie->nombreCientifico);
            //printf("-Tipo: %s\n", especie->tipo);
            //printf("-Habitat: %s\n", especie->habitat);
            //printf("-Alimentacion: %s\n", especie->alimentacion);
            //printf("-Mas sobre la especie: %s\n***\n", especie->descripcion);
            dato = nextMap(mapaVegetal_Continentales);
            if(dato == NULL) break;
          }
            if(dato == NULL){
              printf("\nNo hay mas animales en peligro de extincion de este catalogo, pero puede conocer mas acerca de otros.\n");
              return;
            }
          int opcionUsuario;
          printf("\n(1)Si desea ver mas especies\n(0)si desea volver al menu principal\n");
          printf("Opcion: ");
          scanf("%d", &opcionUsuario);
          if(opcionUsuario == 0) return;
        }
      //mostrarVegetalesContinentes();
     break;
    case(7):
      printf("--------------------\n");
      printf("Ver *flora Acuatica*\n");
      printf("--------------------\n\n");
      dato = firstMap(mapaVegetal_Acuatico);
      while(1)
        {
          if(dato == NULL){
            printf("\nNo hay mas flora en peligro de extincion de este catalogo, pero puede conocer mas acerca de otros.\n\n");
            break;
          }

          for(int i = 0; i < 3; i++){
            vegetal * especie = dato->value;
            if(strcmp(especie->habitat, "Acuatico") == 0){
              printf("-Numero: %s", especie->numero);
              printf(" - %s\n", especie->nombre);
            }
            //printf("-Nombre cinetifico: %s\n", especie->nombreCientifico);
            //printf("-Tipo: %s\n", especie->tipo);
            //printf("-Habitat: %s\n", especie->habitat);
            //printf("-Alimentacion: %s\n", especie->alimentacion);
            //printf("-Mas sobre la especie: %s\n***\n", especie->descripcion);
            dato = nextMap(mapaVegetal_Acuatico);
            if(dato == NULL) break;
          }
            if(dato == NULL){
              printf("\nNo hay mas animales en peligro de extincion de este catalogo, pero puede conocer mas acerca de otros.\n");
              return;
            }
          int opcionUsuario;
          printf("\n(1)Si desea ver mas especies\n(0)si desea volver al menu principal\n");
          printf("Opcion: ");
          scanf("%d", &opcionUsuario);
          if(opcionUsuario == 0) return;
        }
      //mostrarVegetalesAcuaticos();
      break;
    case(8):
      printf("------------\n");
      printf("Ver *Hongos*\n");
      printf("------------\n\n");
      dato = firstMap(mapaVegetal_Hongos);
      while(1)
        {
          if(dato == NULL){
            printf("\nNo hay mas flora en peligro de extincion de este catalogo, pero puede conocer mas acerca de otros.\n\n");
            break;
          }

          for(int i = 0; i < 3; i++){
            vegetal * especie = dato->value;
            if(strcmp(especie->habitat, "Hongo") == 0){
              printf("-Numero: %s", especie->numero);
              printf(" - %s\n", especie->nombre);
            }
            //printf("-Nombre cinetifico: %s\n", especie->nombreCientifico);
            //printf("-Tipo: %s\n", especie->tipo);
            //printf("-Habitat: %s\n", especie->habitat);
            //printf("-Alimentacion: %s\n", especie->alimentacion);
            //printf("-Mas sobre la especie: %s\n***\n", especie->descripcion);
            dato = nextMap(mapaVegetal_Hongos);
            if(dato == NULL) break;
          }
            if(dato == NULL){
              printf("\nNo hay mas flora en peligro de extincion de este catalogo, pero puede conocer mas acerca de otros.\n");
              return;
            }
          int opcionUsuario;
          printf("\n(1)Si desea ver mas especies\n(0)si desea volver al menu principal\n");
          printf("Opcion: ");
          scanf("%d", &opcionUsuario);
          if(opcionUsuario == 0) return;
        }
      //mostrarVegetalesAcuaticos();
      break;
    case 9:
      printf("-------------\n");
      printf("Ver *Plantas*\n");
      printf("-------------\n\n");
      dato = firstMap(mapaVegetal_Plantas);
      while(1)
        {
          if(dato == NULL){
            printf("\nNo hay mas flora en peligro de extincion de este catalogo, pero puede conocer mas acerca de otros.\n\n");
            break;
          }

          for(int i = 0; i < 3; i++){
            vegetal * especie = dato->value;
            if(strcmp(especie->habitat, "Planta") == 0){
              printf("-Numero: %s", especie->numero);
              printf(" - %s\n", especie->nombre);
            }
            //printf("-Nombre cinetifico: %s\n", especie->nombreCientifico);
            //printf("-Tipo: %s\n", especie->tipo);
            //printf("-Habitat: %s\n", especie->habitat);
            //printf("-Alimentacion: %s\n", especie->alimentacion);
            //printf("-Mas sobre la especie: %s\n***\n", especie->descripcion);
            dato = nextMap(mapaVegetal_Plantas);
            if(dato == NULL) break;
          }
            if(dato == NULL){
              printf("\nNo hay mas animales en peligro de extincion de este catalogo, pero puede conocer mas acerca de otros.\n");
              return;
            }
          int opcionUsuario;
          printf("\n(1)Si desea ver mas especies\n(0)si desea volver al menu principal\n");
          printf("Opcion: ");
          scanf("%d", &opcionUsuario);
          if(opcionUsuario == 0) return;
        }
      break;
  }
}

int validarInstruccionCaso2(){
  char aux[10];

  while(1){
    mostrarOpcionesCaso2();
    if(scanf("%2s", aux) != 1){
      printf("debe ingresar una opcion valida\n\n");
      while(getchar() != '\n');
    } else {
        int instruccion;
        if(strlen(aux) == 1 &&  aux[0] >= '0' && aux[0] <= '2'){
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

void mostrarOpcionesCaso2(){
  printf("(1) Buscar por ID númerico\n");
  printf("(2) Buscar por nombre completo\n");
  printf("(0) Volver al menú principal\n");
}

char *asegurarId(){
  char aux[4];

  do{
    printf("Ingrese el ID: \n");
    fgets(aux, sizeof(aux), stdin);

    if( sscanf(aux, "%3s", aux) == 1 && aux[0] != ' ' && aux[0] != '\n'){
      return strdup(aux);
    }
  }while(1);
}


void busquedaNumerica (TreeMap * BinarioGeneral){
  char* busquedaBinaroNum;
  busquedaBinaroNum = asegurarId();
  printf("%s", busquedaBinaroNum);
  PairTree * tempNum = searchTreeMap(BinarioGeneral,busquedaBinaroNum);

  if(tempNum != NULL && ((animal *)tempNum->value)->ID == 1){
    printf("-Numero: %s", ((animal *)tempNum->value)->numero);
    printf(" - %s\n", ((animal *)tempNum->value)->nombre);
    printf("-Nombre cinetifico: %s\n", ((animal *)tempNum->value)->nombreCientifico);
    printf("-Tipo: %s\n", ((animal *)tempNum->value)->tipo);
    printf("-Habitat: %s\n", ((animal *)tempNum->value)->habitat);
    printf("-Alimentacion: %s\n", ((animal *)tempNum->value)->alimentacion);
    printf("-Mas sobre la especie: %s\n***\n", ((animal *)tempNum->value)->descripcion);
  }else if(tempNum != NULL && ((animal *)tempNum->value)->ID == 2){
    
    printf("-Numero: %s", ((vegetal *)tempNum->value)->numero);
    printf(" - %s\n", ((vegetal *)tempNum->value)->nombre);
    printf("-Nombre cinetifico: %s\n", ((vegetal *)tempNum->value)->nombreCientifico);
    printf("-Especie: %s\n", ((vegetal *)tempNum->value)->especie);
    printf("-Habitat: %s\n", ((vegetal *)tempNum->value)->habitat);
    printf("-Mas sobre la especie: %s\n***\n", ((vegetal *)tempNum->value)->descripcion);
  }else if(tempNum == NULL){
    printf("no se encontró la especie que busca");
  }  
}

char *asegurarPalabra(TreeMap * BinarioGeneral){
  char auxiliar[110];
  char *caracteres = malloc(110);
  while(1){ 
    printf("Ingrese el nombre exacto: \n");
    fgets(auxiliar, sizeof(auxiliar), stdin);

    size_t longitud = strlen(auxiliar);
    if(longitud > 0 && auxiliar[longitud-1] == '\n'){
      auxiliar[longitud - 1] = '\0';
    }
    if(longitud <= 100 && longitud > 0){
      strcpy(caracteres, auxiliar);
      break;
    } else {
      while(getchar()!= '\n');
      printf("Se ha excedido la capacidad maxima de caracteres permitidos, intente nuevamente:\n");
    }
  
  }
  return caracteres;
}

void busquedaPalabra (TreeMap * BinarioGeneral){
  char* busquedaBinaroPal;
  busquedaBinaroPal = asegurarPalabra(BinarioGeneral);
  printf("-%s\n", busquedaBinaroPal);
  PairTree * tempPal = firstTreeMap(BinarioGeneral);

  if(tempPal != NULL && (strcmp(((animal *)tempPal->value)->nombre,busquedaBinaroPal) == 0 || (strcmp(((vegetal *)tempPal->value)->nombre,busquedaBinaroPal) == 0))){
    if(tempPal != NULL && ((animal *)tempPal->value)->ID == 1){
      printf("-Numero: %s", ((animal *)tempPal->value)->numero);
      printf(" - %s\n", ((animal *)tempPal->value)->nombre);
      printf("-Nombre cinetifico: %s\n", ((animal *)tempPal->value)->nombreCientifico);
      printf("-Tipo: %s\n", ((animal *)tempPal->value)->tipo);
      printf("-Habitat: %s\n", ((animal *)tempPal->value)->habitat);
      printf("-Alimentacion: %s\n", ((animal *)tempPal->value)->alimentacion);
      printf("-Mas sobre la especie: %s\n***\n", ((animal *)tempPal->value)->descripcion);
    }else if(tempPal != NULL && ((animal *)tempPal->value)->ID == 2){
    
      printf("-Numero: %s", ((vegetal *)tempPal->value)->numero);
      printf(" - %s\n", ((vegetal *)tempPal->value)->nombre);
      printf("-Nombre cinetifico: %s\n", ((vegetal *)tempPal->value)->nombreCientifico);
      printf("-Especie: %s\n", ((vegetal *)tempPal->value)->especie);
      printf("-Habitat: %s\n", ((vegetal *)tempPal->value)->habitat);
      printf("-Mas sobre la especie: %s\n***\n", ((vegetal *)tempPal->value)->descripcion);
    }
  }else{
    while(1){
      tempPal = nextTreeMap(BinarioGeneral);
      if(tempPal != NULL && strcmp(((animal *)tempPal->value)->nombre,busquedaBinaroPal) == 0){
        printf("-Numero: %s", ((animal *)tempPal->value)->numero);
        printf(" - %s\n", ((animal *)tempPal->value)->nombre);
        printf("-Nombre cinetifico: %s\n", ((animal *)tempPal->value)->nombreCientifico);
        printf("-Tipo: %s\n", ((animal *)tempPal->value)->tipo);
        printf("-Habitat: %s\n", ((animal *)tempPal->value)->habitat);
        printf("-Alimentacion: %s\n", ((animal *)tempPal->value)->alimentacion);
        printf("-Mas sobre la especie: %s\n***\n", ((animal *)tempPal->value)->descripcion);
        break;
      }else if(tempPal != NULL && (strcmp(((vegetal *)tempPal->value)->nombre,busquedaBinaroPal) == 0)){

        printf("-Numero: %s", ((vegetal *)tempPal->value)->numero);
        printf(" - %s\n", ((vegetal *)tempPal->value)->nombre);
        printf("-Nombre cinetifico: %s\n", ((vegetal *)tempPal->value)->nombreCientifico);
        printf("-Especie: %s\n", ((vegetal *)tempPal->value)->especie);
        printf("-Habitat: %s\n", ((vegetal *)tempPal->value)->habitat);
        printf("-Mas sobre la especie: %s\n***\n", ((vegetal *)tempPal->value)->descripcion);
        break;
      }else if(tempPal == NULL){
        printf("no se encontró la especie que busca");
      }
    }
  }
}



void switchCaso2(int instruccionCaso2,TreeMap * BinarioGeneral){

  switch(instruccionCaso2){
    case 1:
      busquedaNumerica(BinarioGeneral);
      break;
    case 2:
      busquedaPalabra(BinarioGeneral);
      break;
    case 0:
      return;
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
        
        return instruccion;
      } else{
          printf("debe ingresar una opcion valida\n\n");
          while(getchar() != '\n');
      }
    }
  }  
}

void mostrarOpcionesCaso3(){

  printf("(1)Si desea mostrar los favoritos\n");
  printf("(2)Si desea eliminar algun favorito\n");  
  printf("(3)Si desea guardar algun favorito\n");
  printf("(0)Si desea volver al menu principal\n");
}

void mostrarFavoritos(List * listaFav){
  void * aux = firstList(listaFav); 
  
  while(1){
    int ID = *((int*)aux);
    animal * auxA = NULL;
    vegetal * auxV = NULL;
    
    if(ID == 1){
      auxA = (animal*) aux;
    }else if(ID == 2){
      auxV = (vegetal*) aux;
    }
    
    if(auxV == NULL){
      printf("-Numero: %s", auxA->numero);
      printf(" - %s\n", auxA->nombre);
    }else if(auxA == NULL){
      printf("-Numero: %s", auxV->numero);
      printf(" - %s\n", auxV->nombre);
    }
    aux = nextList(listaFav);
    if(aux == NULL) break;
  }

  
}

void busquedaNumericaFav(List * listaFav,TreeMap * BinarioGeneral){
  char* busquedaBinaroNum;
  busquedaBinaroNum = asegurarId();
  PairTree * tempNum = searchTreeMap(BinarioGeneral,busquedaBinaroNum);

  if(tempNum == NULL){
    printf("no se encontró la especie que busca");
  }else{
    pushBack(listaFav,tempNum->value);
  }
}

void busquedaPalabraFav(List * listaFav,TreeMap *BinarioGeneral){
  char * busquedaBinaroPal;
  busquedaBinaroPal = asegurarPalabra(BinarioGeneral);
  printf("-%s\n", busquedaBinaroPal);
  PairTree * tempPal = firstTreeMap(BinarioGeneral);
  
  if(tempPal != NULL && (strcmp(((animal *)tempPal->value)->nombre,busquedaBinaroPal) == 0 || (strcmp(((vegetal *)tempPal->value)->nombre,busquedaBinaroPal) == 0))){
    pushBack(listaFav,tempPal->value);
  
  }else{
    while(1){
      tempPal = nextTreeMap(BinarioGeneral);
      if(tempPal != NULL && strcmp(((animal *)tempPal->value)->nombre,busquedaBinaroPal) == 0){
        pushBack(listaFav,tempPal->value);
        break;
      
      }else if(tempPal != NULL && (strcmp(((vegetal *)tempPal->value)->nombre,busquedaBinaroPal) == 0)){
        pushBack(listaFav,tempPal->value);
        break;
      }else if(tempPal == NULL){
        printf("no se encontró la especie que busca");
      }
    }  
  }
}

void agregarFavoritos(int instruccionFav,List * listaFav,TreeMap * BinarioGeneral){
  
  switch(instruccionFav){
    case 1:
      busquedaNumericaFav(listaFav,BinarioGeneral);
      break;
    case 2:
      busquedaPalabraFav(listaFav,BinarioGeneral);
      break;
    case 0:
      return;
    break;
  }
}



void EliminarFavoritos(List * listaFav,TreeMap * BinarioGeneral){

}
void mostrarOpcionesFav(){
  printf("(1) Buscar por ID númerico\n");
  printf("(2) Buscar por nombre completo\n");
  printf("(0) Volver al menú principal\n");
}



int  validarInstruccionFav(){
  char aux[10];

  while(1){
    mostrarOpcionesFav();
    if(scanf("%2s", aux) != 1){
      printf("debe ingresar una opcion valida\n\n");
      while(getchar() != '\n');
    } else {
        int instruccion;
        if(strlen(aux) == 1 &&  aux[0] >= '0' && aux[0] <= '2'){
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
  
void switchCaso3(int instruccionCaso3, List * listaFav, TreeMap * BinarioGeneral){
  switch(instruccionCaso3){
    case(1):
      mostrarFavoritos(listaFav);
     break;
    case(2):
      printf("");
      int instruccionFav;
      do{
          instruccionFav = validarInstruccionFav();
        agregarFavoritos(instruccionFav,listaFav,BinarioGeneral);
        printf("Agregar otro favorito:\n");
      }while(instruccionFav != 0);  
      break;
    case(3):
      EliminarFavoritos(listaFav,BinarioGeneral);
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
        
        return instruccion;
      } else{
          printf("debe ingresar una opcion valida\n\n");
          while(getchar() != '\n');
      }
    }
  }  
}

void mostrarOpcionesCaso4(){
  printf("(1)Si desea ver el historial\n");
  printf("(2)Si desea borrar el historial\n");
  printf("(0)Si desea volver al menu principal\n\n");
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