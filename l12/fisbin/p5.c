#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct{
  uint16_t an;
  uint8_t luna;
  uint8_t zi;
  uint8_t idx;
  int16_t valoare;
}senzor;

FILE *fin=NULL;
FILE *fout=NULL;

void creare_fis(){
  if((fout=fopen("test.bin","wb"))==NULL){
    printf("nu paote fi deschis fis");
    exit(EXIT_FAILURE);
  }

  senzor s1[]={{2000,12,11,1,888},{2000,12,11,1,-333},{2000,12,11,1,823},{2000,12,11,2,823},{2000,12,11,2,1823},{2000,12,11,2,-823},{2000,12,11,3,8232},{2000,12,11,3,1823},{2000,12,11,3,8231},{2000,12,11,3,8123},{2000,12,11,1,23}};

  uint32_t n=11;

  fwrite(&n,sizeof(uint32_t),1,fout);

  if(fwrite(s1,sizeof(senzor),11,fout)==11){
    printf("a fost scris cu succes\n");
  }

  fclose(fout);
  
}

int def[101];
int bun[101];

void citire(){
  if((fin=fopen("test.bin","rb"))==NULL){
    printf("nu paote fi deschis fis");
    exit(EXIT_FAILURE);
  }

  uint32_t n=0;
  if(fread(&n,sizeof(uint32_t),1,fin)!=1){
    printf("eroare citire");
    return;
  }

  for(int i=0 ; i<n ; i++){
    senzor s={0};
    if(fread(&s,sizeof(senzor),1,fin)){
      if(s.valoare>1000 || s.valoare<-1000){
	def[s.idx]=1;
      }else{
	bun[s.idx]=1;
      }
    }
    
  }

  for(int i=1 ; i<101 ; i++){
    if(bun[i]==1 && def[i]==1){
      printf("%d probleme\n",i);
    }else{
      if(bun[i]==1 && def[i]==0){
	printf("%d bun\n",i);
      }else{
	if(bun[i]==0 && def[i]==1){
	  printf("%d defect\n",i);
	}
      }
    }
  }
  return ;
}

int main(){
  creare_fis();

  citire();

  return 0;
}
