#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum{
  frontala,verticala
}Incarcare;

typedef struct{
  int capacitate;
  char clasa;
  char *programe;
}Frontala;

typedef struct{
  char *afisaj;
  int nrProg;
  char *selector;
  int nivelZgomot;
}Verticala;


typedef union{
  Frontala frontala;
  Verticala verticala;
}Detalii;

typedef struct{
  char *producator;
  char *model;
  int pret_furn;
  int pret_vanz;
  int greutate;
  Incarcare incarcare;
  Detalii detalii;
}Masina;

void afisareMasina(Masina aux) {
    printf("\n=== DETALII MASINA ===\n");
    printf("Producator: %s\n", aux.producator);
    printf("Model:      %s\n", aux.model);
    printf("Pret Furn.: %d RON\n", aux.pret_furn);
    printf("Pret Vanz.: %d RON\n", aux.pret_vanz);
    printf("Greutate:   %d kg\n", aux.greutate);

    // Verificam tipul incarcarii pentru a sti ce campuri din UNION sa accesam
    if (aux.incarcare == frontala) {
        printf("Tip:        Incarcare Frontala\n");
        printf("--- Specificatii ---\n");
        printf("Capacitate: %d kg\n", aux.detalii.frontala.capacitate);
        printf("Clasa En.:  %c\n", aux.detalii.frontala.clasa);
        printf("Programe:   %s\n", aux.detalii.frontala.programe);
    } 
    else {
        printf("Tip:        Incarcare Verticala\n");
        printf("--- Specificatii ---\n");
        printf("Afisaj:       %s\n", aux.detalii.verticala.afisaj);
        printf("Nr. Programe: %d\n", aux.detalii.verticala.nrProg);
        printf("Selector:     %s\n", aux.detalii.verticala.selector);
        printf("Zgomot:       %d dB\n", aux.detalii.verticala.nivelZgomot);
    }
    printf("======================\n");
}

void citire(char *pathname){
  FILE *fin=NULL;
  fin=fopen(pathname,"rb");
  
  Masina aux;

  while(fread(&aux,sizeof(Masina),1,fin)==1){
    afisareMasina(aux);
  }

  return ;
}


void adaugare(char *pathname){
  FILE *fout=NULL;

  fout=fopen(pathname,"ab");

  char producator[101],model[101];
  int pret_furn=0,pret_vanz=0,greutate=0;
  Incarcare incarcare=0;
  scanf("%s %s %d %d %d %d",producator,model,&pret_furn,&pret_vanz,&greutate,(int*)&incarcare);

  Masina aux;
  aux.producator=malloc(strlen(producator)+1);
  strcpy(aux.producator,producator);

  aux.model=malloc(strlen(model)+1);
  strcpy(aux.model,model);

  aux.pret_furn=pret_furn;
  aux.pret_vanz=pret_vanz;
  aux.greutate=greutate;
  aux.incarcare=incarcare;
  

  char buffer_detalii[100];
  
  switch(incarcare){
  case frontala:
    scanf("%d %c %s", 
          &(aux.detalii.frontala.capacitate), 
          &(aux.detalii.frontala.clasa), 
          buffer_detalii);

    aux.detalii.frontala.programe = malloc(strlen(buffer_detalii) + 1);
    
    strcpy(aux.detalii.frontala.programe, buffer_detalii);
    break;

  default:
    char buffer_afisaj[100];
    char buffer_selector[100];

    scanf("%s %d %s %d", 
          buffer_afisaj, 
          &(aux.detalii.verticala.nrProg), 
          buffer_selector, 
          &(aux.detalii.verticala.nivelZgomot));

    aux.detalii.verticala.afisaj = malloc(strlen(buffer_afisaj) + 1);
    strcpy(aux.detalii.verticala.afisaj, buffer_afisaj);

    aux.detalii.verticala.selector = malloc(strlen(buffer_selector) + 1);
    strcpy(aux.detalii.verticala.selector, buffer_selector);
    break;
  }

  fwrite(&aux,sizeof(Masina),1,fout);
}
  
int main(){
  //adaugare("magazin1.bin");
  citire("magazin1.bin");
}
