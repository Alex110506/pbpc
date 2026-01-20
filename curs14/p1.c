#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>


typedef struct{
  uint8_t len;
  uint8_t data[255];
  uint16_t checksum;
}XBEE;


uint8_t readData(FILE *f, XBEE *e){
  uint8_t temp;
  if(fread(&temp, sizeof(uint8_t),1,f) != 1){
    return 0;
  }

  if(temp != 0x7E){
    return 0;
  }

  memset(e,0, sizeof(XBEE));

  if(fread(&e->len, sizeof(uint8_t),1,f)!=1){
    return 0;
  }

  if(fread(e->data,sizeof(uint8_t), e->len,f)!=e->len){
    return 0;
  }

  if(fread(&e->checksum,sizeof(uint16_t),1,f)!=1){
    return 0;
  }

  return 1;
}


void printData(const XBEE *e){
  printf("%3d ",e->len);
  for(int i=0 ; i<e->len ; i++){
    printf("%02X",e->data[i]);
  }

  printf(" %04X",e->checksum);
}


uint8_t checkData(const XBEE *e){
  uint16_t calc=0;
  for(int i=0 ; i<e->len ;  i++){
    calc+=e->data[i];
  }

  if(calc==e->checksum){
    return 1;
  }

  return 0;
}


int main(int argc, char **argv){
  if(argc != 4){
    fprintf(stderr,"eroare argumente");
    exit(1);
  }

  FILE *in;
  if((in=fopen(argv[1],"rb"))==NULL){
    perror(argv[1]);
    exit(1);
  }

  XBEE *aux=NULL;
  
  while(readData(in,aux)==1){
    printData(aux);

    if(checkData(aux)){
      printf("ok");
    }else{
      printf("nu");
    }
  }

  if(fclose(in)<0){
    perror(argv[1]);
    exit(1);
  }
  
  return 0;
}
