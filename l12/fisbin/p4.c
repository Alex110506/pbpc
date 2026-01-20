#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *fin=NULL;
FILE *fout=NULL;

typedef enum{
  Frontala,Verticala
}tip_incarcare;

typedef struct{
  int capacitate;
  char clasa;
  char programe[101];
}frontala;

typedef struct{
  char afisaj[101];
  int nr_prog;
  char selector[101];
  int zgomot;
}verticala;

typedef union{
  verticala vert;
  frontala front;
}Detalii;

typedef struct{
  char producator[101];
  char model[101];
  float pret_furn;
  float pret_vanz;
  float greutate;
  tip_incarcare incarcare;
  Detalii detalii;
}masina;









void citire_afisare() {
  if((fin=fopen("magazin.bin","rb"))==NULL){
    printf("Nu se poate deschide citirea");
    exit(EXIT_FAILURE);
  }

  masina m;
  int nr = 0;

  printf("\n======= LISTA MASINI DIN FISIER =======\n");

  while (fread(&m, sizeof(masina), 1, fin) == 1) {
    nr++;
    printf("\n[%d] PRODUS: %s %s\n", nr, m.producator, m.model);
    printf("    Pret: %.2f RON | Greutate: %.2f kg\n", m.pret_vanz, m.greutate);

    if (m.incarcare == Frontala) {
      printf("    Tip: FRONTALA\n");
      printf("    -> Capacitate: %d kg\n", m.detalii.front.capacitate);
      printf("    -> Clasa: %c\n", m.detalii.front.clasa);
      printf("    -> Programe: %s\n", m.detalii.front.programe);
    } 
    else if (m.incarcare == Verticala) {
      printf("    Tip: VERTICALA\n");
      printf("    -> Afisaj: %s\n", m.detalii.vert.afisaj);
      printf("    -> Programe: %d\n", m.detalii.vert.nr_prog);
      printf("    -> Selector: %s\n", m.detalii.vert.selector);
      printf("    -> Zgomot: %d dB\n", m.detalii.vert.zgomot);
    }
    printf("---------------------------------------\n");
  }

  if (nr == 0) {
    printf("Fisierul este gol sau nu a putut fi citit.\n");
  } else {
    printf("Total: %d produse afisate.\n", nr);
  }

  fclose(fin);
}












void adaugare_produs() {
  if ((fout = fopen("magazin.bin", "ab")) == NULL) {
    perror("Nu se poate deschide scrierea");
    return;
  }

  masina aux = {0}; 
  char str[101];
  int intt = 0;

  while(getchar() != '\n' && getchar() != EOF); 

  printf("\n--- Adaugare Produs Nou ---\n");

  printf("Introdu producatorul: ");
  if (fgets(aux.producator, sizeof(aux.producator), stdin)) {
    aux.producator[strcspn(aux.producator, "\n")] = '\0';
  }

  printf("Introdu model: ");
  if (fgets(aux.model, sizeof(aux.model), stdin)) {
    aux.model[strcspn(aux.model, "\n")] = '\0';
  }

  printf("Introdu pret furnizor: ");
  scanf("%f", &aux.pret_furn);
  printf("Introdu pret vanzare: ");
  scanf("%f", &aux.pret_vanz);
  printf("Introdu greutate: ");
  scanf("%f", &aux.greutate);

  printf("Introdu tip de incarcare (0 - Frontala, 1 - Verticala): ");
  scanf("%d", &intt);
  aux.incarcare = (tip_incarcare)intt;
    
  while(getchar() != '\n');

  if (aux.incarcare == Frontala) {
    printf("Capacitate (kg): ");
    scanf("%d", &aux.detalii.front.capacitate);
    printf("Clasa energetica (un caracter): ");
    scanf(" %c", &aux.detalii.front.clasa);
    while(getchar() != '\n');
    printf("Programe disponibile: ");
    fgets(aux.detalii.front.programe, sizeof(aux.detalii.front.programe), stdin);
    aux.detalii.front.programe[strcspn(aux.detalii.front.programe, "\n")] = '\0';
  } 
  else { 
    printf("Tip afisaj: ");
    fgets(aux.detalii.vert.afisaj, sizeof(aux.detalii.vert.afisaj), stdin);
    aux.detalii.vert.afisaj[strcspn(aux.detalii.vert.afisaj, "\n")] = '\0';
        
    printf("Numar programe: ");
    scanf("%d", &aux.detalii.vert.nr_prog);
    while(getchar() != '\n');

    printf("Tip selector: ");
    fgets(aux.detalii.vert.selector, sizeof(aux.detalii.vert.selector), stdin);
    aux.detalii.vert.selector[strcspn(aux.detalii.vert.selector, "\n")] = '\0';

    printf("Nivel zgomot (dB): ");
    scanf("%d", &aux.detalii.vert.zgomot);
    while(getchar() != '\n');
  }

  fwrite(&aux, sizeof(masina), 1, fout);
  fclose(fout);
  printf("\nProdus salvat cu succes in magazin.bin!\n");
}












void afisare_tip() {
  if((fin=fopen("magazin.bin","rb"))==NULL){
    printf("Nu se poate deschide citirea");
    exit(EXIT_FAILURE);
  }

  masina m;
  int nr = 0;

  printf("\n======= LISTA MASINI DIN FISIER =======\n");

  masina *lista=NULL;

  while (fread(&m, sizeof(masina), 1, fin) == 1) {
    masina *aux=realloc(lista,(nr+1)*sizeof(masina));
    if(aux==NULL){
      printf("nu mai e memeorie");
      free(lista);
      exit(EXIT_FAILURE);
    }

    lista=aux;
    lista[nr]=m;
    nr++;
  }

  for(int i=0 ; i<nr ; i++){
    if(lista[i].incarcare==(tip_incarcare)0){
      m=lista[i];
      
      printf("\n[%d] PRODUS: %s %s\n", i+1, m.producator, m.model);
      printf("    Pret: %.2f RON | Greutate: %.2f kg\n", m.pret_vanz, m.greutate);

      printf("    Tip: FRONTALA\n");
      printf("    -> Capacitate: %d kg\n", m.detalii.front.capacitate);
      printf("    -> Clasa: %c\n", m.detalii.front.clasa);
      printf("    -> Programe: %s\n", m.detalii.front.programe);
      printf("---------------------------------------\n");
    }
  }

  for(int i=0 ; i<nr ; i++){
    if(lista[i].incarcare==(tip_incarcare)1){
      m=lista[i];
      
      printf("\n[%d] PRODUS: %s %s\n", i+1, m.producator, m.model);
      printf("    Pret: %.2f RON | Greutate: %.2f kg\n", m.pret_vanz, m.greutate);
      
      printf("    Tip: VERTICALA\n");
      printf("    -> Afisaj: %s\n", m.detalii.vert.afisaj);
      printf("    -> Programe: %d\n", m.detalii.vert.nr_prog);
      printf("    -> Selector: %s\n", m.detalii.vert.selector);
      printf("    -> Zgomot: %d dB\n", m.detalii.vert.zgomot);
      printf("---------------------------------------\n");
    }
  }

  free(lista);
  fclose(fin);
}


int main(){
  printf("Selectati variantele:\n");
  printf("1 - Citire\n2 - Adaugare\n3 - Afisare\n4 - Creare fisier oferta\n5 - Cauta dupa greutate\n7 - Afisare dupa producator\n8 - Iesire\n");

  int ok=1;
  int alegere;
  while(ok){
    printf("introduceti alegerea: ");
    scanf("%d",&alegere);
    printf("\n");

    switch(alegere){
    case 1:
      citire_afisare();
      break;
    case 2:
      adaugare_produs();
      break;
    case 3:
      afisare_tip();
      break;
    case 4:
      break;
    case 5:
      break;
    case 6:
      break;
    case 7:
      break;
    case 8:
      ok=0;
      break;
    default:
      printf("Alegere invalida, mai alegeti odata!\n");
      break;
    }
  }
}
