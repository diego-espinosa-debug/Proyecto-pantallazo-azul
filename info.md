Según datos de la Unión Internacional para la Conservación de la Naturaleza (UICN), el organismo internacional con mayor potestad sobre el problema, aproximadamente 5.200 especies de animales se encuentran en peligro de extinción en la actualidad. Además, en un desglose por clase, se encuentran en peligro de extinción el 11% de las aves, el 20% de los reptiles, el 34% de los peces y 25% de los anfibios y mamíferos.

entre las mayores amenazas se encuentra la destrucción y fragmentación de sus hábitats; el cambio climático; la caza y tráfico ilegal; y la introducción de especies exóticas. 

¿Cómo evitar la extinción de especies?
implica la puesta en marcha de una gran cantidad de recursos y acciones concretas. Algunas de ellas serían evitar la fragmentación de sus hábitats, por ejemplo la deforestación; perseguir y castigar con dureza la caza ilegal y el tráfico de especies; la creación de reservas naturales; o el fomento de programas de reproducción, reintroducción y de mejora genética. La lucha contra la contaminación y el cambio climático también es la lucha por la conservación de muchos animales. Cada decisión personal tiene una consecuencia a nivel global en múltiples aspectos, de ahí la importancia de la concienciación social de la población para luchar contra la pérdida de biodiversidad. 

void importarPuntoInteresYTuristas_DesdeArchivoCSV(HashMap * mapa_puntos, HashMap * mapa_Turista, HashMap* mapa_puntosxtipo, HashMap * mapa_turistasXpais)
{
  //mostrar opciones para importar
  printf("Tipo del archivo CSV: \n");
  printf("(1) Punto de interes.\n");
  printf("(2) Turista.\n");
  int opcion;
  scanf("%d", &opcion);
  while(opcion != 1 && opcion != 2){
    printf("Opcion invalida. Favor ingrese nuevamente: ");
    scanf("%d", &opcion);
  }
  getchar();

  //el usuario ingresa el nombre del archivo
  char nombreArchivo[MAX];
  printf("Ingrese el nombre del archivo CSV: ");
  fgets(nombreArchivo, sizeof(nombreArchivo), stdin);
  nombreArchivo[strcspn(nombreArchivo, "\n")] = '\0';

  //abrir archivo
  FILE *archivo = fopen(nombreArchivo, "r");
  if (archivo == NULL) {
      printf("***No se pudo abrir el archivo***\n");
      return;
  }
//cadena para guardar la linea completa del archivo csv
  char linea[MAX];

  switch(opcion){
    case 1: //archivo tipo Punto
      fgets(linea, 5*MAX, archivo); //lee primera linea
      while (fgets(linea, 5*MAX, archivo) != NULL) //lee linea
      {
        //reservar memoria
        Punto * nuevoPunto = (Punto * ) malloc(sizeof(Punto));
        if(nuevoPunto == NULL) exit(EXIT_FAILURE);

        for(int i = 0 ; i < 5 ; i++){
          char * aux = (char *) get_csv_field(linea, i);//se obtiene cadena hasta la coma
          switch(i){
            case 0://nombre
              strcpy(nuevoPunto->nombre, aux);
              break;
            case 1://tipo
              strcpy(nuevoPunto->tipo, aux);
              break;
            case 2://direccion
              strcpy(nuevoPunto->direccion, aux);
              break;
            case 3://horario
              strcpy(nuevoPunto->horario, aux);
              break;
            case 4://descripcion
              strcpy(nuevoPunto->descripcion, aux);
              break;
          }
        }
        insertMap(mapa_puntos, nuevoPunto->nombre, nuevoPunto);
        Pair * aux = searchMap(mapa_puntosxtipo, nuevoPunto->tipo);
        if(aux == NULL){
          List * listaTipo = createList();
          pushFront(listaTipo, nuevoPunto);
          insertMap(mapa_puntosxtipo, nuevoPunto->tipo, listaTipo);
        }else{
          List * listaTipo = aux->value;
          pushFront(listaTipo, nuevoPunto);
          insertMap(mapa_puntosxtipo, nuevoPunto->tipo, listaTipo);
        }
      }
      printf("Archivo importado exitosamente.\n");
      break;
    case 2: //archivo tipo Turista
      fgets(linea, 10*MAX, archivo);
      //Pasaporte,Nombre,País,Lugares Favoritos
      while (fgets(linea, 10*MAX, archivo) != NULL) //lee linea
      {
        //reservar memoria
        Turista * nuevoTurista = (Turista * ) malloc(sizeof(Turista));
        if(nuevoTurista == NULL) exit(EXIT_FAILURE);

        for(int i = 0 ; i < 4 ; i++){
          char * aux = (char *) get_csv_field(linea, i);//se obtiene cadena hasta la coma
          //char *token;
          switch(i){
            case 0://pasaporte
              strcpy(nuevoTurista->pasaporte, aux);
              break;
            case 1://nombre
              strcpy(nuevoTurista->nombre, aux);
              break;
            case 2://pais
              strcpy(nuevoTurista->pais_origen, aux);
              break;
            case 3://lugares
              //intente separar los lugares con un token con delimitador ";" 
              //luego guardar el lugar en el token y insertar en la Lista
              /*char* token = strtok(aux, ";");
                while (token != NULL) {
                // Añadir el lugar favorito a la lista del turista
                  pushFront(nuevoTurista->lugares_favoritos, token);
                  token = strtok(NULL, ",");
                }
                break;*/
              //printf("Lugares no importados.\n");
              break;
          }
        }
        insertMap(mapa_Turista, nuevoTurista->nombre, nuevoTurista);
        insertMap(mapa_turistasXpais, nuevoTurista->pais_origen, nuevoTurista);
      }

      printf("\n***Archivo importado exitosamente***\n");
      break;
  }

  fclose(archivo);
}