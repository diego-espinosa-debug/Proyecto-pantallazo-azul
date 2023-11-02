#include <stdio.h>
#include <stdlib.h>

typedef struct animal{
  char nombre[100];
  int numero;
  char especie[100];
  char habitat[100];
}animal;

int main(){
  printf("**BioDex**\n\n");
  return EXIT_SUCCESS;
}