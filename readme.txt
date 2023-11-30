**falta TDAS binari y cola
**en donde se lee el archivo hay que guardas los datos en alguna funcion o dentro de ImportarInformacion con los mapas,porque acutalmente creo que se ven los datos pero no se guardan en ningun mapa (antes hacer lo del arbol-binari que es uno de los principales)

**Caso 1 despues de asegurarse que los datos se leen correctamente en los mapas correspondientes lo primero es hacer las funciones para:(verificar que eso es todo o si falta/sobra algun mostrar porque eso esta hecho de antes de la presentacion) Despues de mostrar hay que hacer lo del ppt que sale
Opcion 1 
001,Iguana(simplificado por comodidad los noombres)
002,Zarigueya
003,Gorila
Escoja
(1)Si desea seguir viendo
(2)si desea retroceder y ver otro tipo de catalogo 
(para esto se puede crear una funcion que diga y lea (1)Si desea seguir viendo
(2)si desea retroceder y ver otro tipo de catalogo // o simplemente colocarlo despues, porque enteoria se deberia hacer con un for i = 0 ; i < 3 ; i++  o con un while lo que sea mas comodo )
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
  
**El caso 2 necesita modificacion, primero hacer otro sub menu que tenga el "desea buscar por nombre (1) o por id(2) o algo parecido, para ser mas exactos esta en el ppt que presentamos"
en el ppt esta 
que desea hacer:
2
Escoja si desea buscar por
(1)Id
(2)Nombre
y despues hacer una funcion que reciba los datos del usuario ya sea nombre o id y se vaya comparando con el bi-map (supongo) y si se encuentra se muestre la informacion especifica, (parece que el ejemplo igual deberia estar en el ppt) ADEMAS HAY que hacer aca mismo "segun mi idea" la ¿cola? del historial 
para que despues solamente se muestre o se elimine en el caso 4 
num: 009
Nombre: Panda gigante
Nombre Cientifico:  Ailuropoda melanoleuca
Alimentacion: Carnivoro
Habitat: Terrestre
Tipo: Mamifero
Descripcion: 
ese deberia ser el formato que se muestre despues de buscar en el caso 2.

**caso 3 hay que hacer las siguientes funciones despues de asegurar que se guarden bien los datos(si no se han agregados favoritos debe decir"No hay favoritos guardados o algo asi" lo mismo si al eliminar no hay nada, y si se agrega favorito colaborar que exite el animal o id y de existir guardar los datos en la ¿lista?)
case(1):
  //mostrarFavoritos();
 break;
case(2):
  //EliminarFavoritos();
  break;
case(3):
  //agregarFavoritos();
  break;
  **caso 4 crear las funciones mostrarHistorial y EliminarHistorial con la cola
  case(1):
    //mostrarHistorial();
   break;
  case(2):
    //EliminarHistorial();
    break;

