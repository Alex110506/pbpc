#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
  char name[101];
  int year;
  float budget;
}film;

FILE *fin;
FILE *fout1,*fout2,*fout3;

film *filme=NULL;
int nrFilme=0;
char sep[]=",";

void eliberare(){
  free(filme);
  fclose(fout1);
  fclose(fout2);
  fclose(fout3);
  fclose(fin);
}

void adaugare(char *linie){
  if(strlen(linie)>1){
    film *aux=(film*)realloc(filme,(nrFilme+1)*sizeof(film));
    if(!aux){
      printf("memeoria insufucienta");
      eliberare();
      exit(EXIT_FAILURE);
    }

    filme=aux;
    nrFilme++;
  }
  char *p=strtok(linie,sep);
  int idx=0;
  film ff;
  
  while(p){
    int an;
    float buget;
    
    switch(idx){
    case 0:
      an=atoi(p);
      ff.year=an;
      break;
    case 2:
      strcpy(ff.name,p);
      break;
    case 6:
      buget=atof(p);
      ff.budget=buget;
      break;
    default:
      break;
    }

    idx++;
    p=strtok(NULL,sep);
  }

  filme[nrFilme-1]=ff;
  return;
}

// Correct qsort comparison: descending by year
int cmp1(const void *a, const void *b) {
    film *f1 = (film *)a;
    film *f2 = (film *)b;
    return f2->year - f1->year; 
}

// Sort alphabetically by title
int cmp2(const void *a, const void *b) {
    return strcmp(((film*)a)->name, ((film*)b)->name);
}

// Sort by budget
int cmp3(const void *a, const void *b) {
    float b1 = ((film*)a)->budget;
    float b2 = ((film*)b)->budget;
    return (b1 > b2) - (b1 < b2);
}


int main(){
  
  if((fin=fopen("filme.csv","rt"))==NULL){
    printf("fisierul nu a putut fi deschis");
    exit(EXIT_FAILURE);
  }

  char *linie=malloc(1000);
  
  while(fgets(linie,1000,fin)!=NULL){
    adaugare(linie);
  }

  qsort(filme,nrFilme,sizeof(film),cmp1);
  
  if((fout1=fopen("out1.txt","wt"))==NULL){
    printf("fisierul de ierisre nu poate fi dsechis");
    exit(EXIT_FAILURE);
  }

  for(int i=0 ; i<nrFilme ; i++){
    fprintf(fout1,"%s %d %f\n",filme[i].name,filme[i].year,filme[i].budget);
  }



  qsort(filme,nrFilme,sizeof(film),cmp2);
  
  if((fout2=fopen("out2.txt","wt"))==NULL){
    printf("fisierul de ierisre nu poate fi dsechis");
    exit(EXIT_FAILURE);
  }

  for(int i=0 ; i<nrFilme ; i++){
    fprintf(fout2,"%s %d %f\n",filme[i].name,filme[i].year,filme[i].budget);
  }



  qsort(filme,nrFilme,sizeof(film),cmp3);
  
  if((fout3=fopen("out3.txt","wt"))==NULL){
    printf("fisierul de ierisre nu poate fi dsechis");
    exit(EXIT_FAILURE);
  }

  for(int i=0 ; i<nrFilme ; i++){
    fprintf(fout3,"%s %d %f\n",filme[i].name,filme[i].year,filme[i].budget);
  }

  free(linie);
  eliberare();
  return 0;
  
}
