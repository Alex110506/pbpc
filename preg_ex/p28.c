#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int zi;
  int luna;
  int an;
}Data;

typedef struct{
  float eur;
  Data data;
}Curs;

int cmp(Data a, Data b){
  if(a.zi==b.zi && a.luna==b.luna && a.an==b.an)
    return 1;
  return 0;
}

int main(int argc, char **argv){
  FILE *fin;
  FILE *fout;

  Curs *lista=NULL;
  int size=0;

  if((fin=fopen(argv[1],"rt"))==0){
    printf("eroare fisier");
    return 1;
  }

  if((fout=fopen(argv[2],"wt"))==0){
    printf("eroare fisier");
    return 1;
  }

  Curs aux;

  while(fscanf(fin,"%d.%d.%d;%f ",&(aux.data.zi),&(aux.data.luna),&(aux.data.an),&(aux.eur))==4){

    lista=realloc(lista,(size+1)*sizeof(Curs));
    lista[size]=aux;
    size++;
  }

  if(fclose(fin)){
    printf("eroare fisier");
    return 1;
  }

  printf("%f",lista[0].eur);

  Data d;
  char *s=argv[3];
  d.zi=atoi(s);
  s+=3;
  d.luna=atoi(s);
  s+=3;
  d.an=atoi(s);

  printf("%d %d %d",d.zi,d.luna,d.an);

  for(int i=0 ; i<size ; i++){
    if(cmp(lista[i].data,d)==1){
      fprintf(fout,"%f",lista[i].eur);
    }
  }

  if(fclose(fout)){
    printf("eroare fisier");
    return 1;
  }

  free(lista);
  return 0;
}
