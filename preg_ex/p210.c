#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
  int id;
  char nume[101];
  int salar;
}Jucator;

typedef struct{
  char nume[101];
  int nrJucatori;
  Jucator **jucatori;
}Echipa;

typedef struct{
  char nume[101];
  int nrEchipe;
  Echipa **echipe;
}Campionat;

void adaugareJucator(Echipa *echipa, int idx){
  Jucator juc={0,"",0};
  int aux=scanf("%d %s %d",&(juc.id),juc.nume,&(juc.salar));
  if(aux!=3){
    printf("eroare citire jucator");
    exit(1);
  }

  Jucator *jj=malloc(sizeof(Jucator));
  *jj=juc;

  echipa->jucatori[idx]=jj;

  printf("\njucator adaugat\n");
  
  return;
}


/*void adaugareEchipa(Campionat *campionat){
  Echipa ech;
  ech.jucatori=NULL;
  char buffer[101];
  int aux=scanf("%s %d",buffer,&(ech.nrJucatori));
  
  if(aux!=2){
    printf("eroare citire jucator");
    exit(1);
  }
  
  ech.nume=malloc(strlen(buffer)+1);
  strcpy(ech.nume,buffer);

  printf("adauga %d jucatori",ech.nrJucatori);

  int nrj=ech.nrJucatori;
  
  for(int i=0 ; i<nrj ; i++){
    adaugareJucator(&ech);
  }

  campionat->echipe=realloc(campionat->echipe,(campionat->nrEchipe+1)*sizeof(Echipa));
  campionat->echipe[campionat->nrEchipe]=ech;
  campionat->nrEchipe++;
  
  return;
  }*/

void adaugareEchipa(Campionat *campionat, Echipa *echipa){
  campionat->echipe=realloc(campionat->echipe,(campionat->nrEchipe+1) * sizeof(Echipa));
  campionat->echipe[campionat->nrEchipe]=echipa;

  campionat->nrEchipe++;
}


void creareEchipa(Echipa *ech){
  ech->jucatori=NULL;
  int aux=scanf("%s %d",ech->nume,&(ech->nrJucatori));
  
  if(aux!=2){
    printf("eroare citire echipa");
    exit(1);
  }

  ech->jucatori=realloc(ech->jucatori,ech->nrJucatori*sizeof(Jucator *));
  
  printf("adauga %d jucatori",ech->nrJucatori);

  int nrj=ech->nrJucatori;
  
  for(int i=0 ; i<nrj ; i++){
    adaugareJucator(ech,i);
  }

  return;
}



int main(){
  /* {
    Echipa e={"pula",0,NULL};
    adaugareJucator(&e);

    for(int i=0 ; i<e.nrJucatori ; i++){
      printf("%s",e.jucatori[i].nume);
    }
      
    }

  {
    Campionat camp={"liga pulii",0,NULL};
    adaugareEchipa(&camp);

    for(int i=0 ; i<camp.nrEchipe ; i++){
      printf("%s\n",camp.echipe[i].nume);
      for(int j=0 ; j<camp.echipe[i].nrJucatori ; j++){
	printf("%s\n",camp.echipe[i].jucatori[j].nume);
      }

      printf("\n");
    }
  }*/

  {
    Echipa e;
    creareEchipa(&e);

    Campionat camp={"liga pulii",0,NULL};

    adaugareEchipa(&camp,&e);

    for(int i=0 ; i<camp.nrEchipe ; i++){
      printf("%s\n",camp.echipe[i]->nume);
      for(int j=0 ; j<camp.echipe[i]->nrJucatori ; j++){
	printf("%s\n",camp.echipe[i]->jucatori[j]->nume);
      }

      printf("\n");
    }

    for(int i=0 ; i<camp.nrEchipe ; i++){
      for(int j=0 ; j<camp.echipe[i]->nrJucatori ; j++){
	free(camp.echipe[i]->jucatori[j]);
      }
      free(camp.echipe[i]->jucatori);
      //free(camp.echipe[i]);
    }
    free(camp.echipe);
  }

}
