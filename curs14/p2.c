#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//mac



int main(int argc, char **argv){
  if(argc !=3) {
    fprintf(stderr,"eroare");
    exit(1);
  }

  FILE *in;

  if((in=fopen(argv[1],"r"))==NULL){
    perror(argv[1]);
    exit(1);
  }

  uint8_t mac[6];

  
  if(fscanf(in,"%hh02X:%hh02X:%hh02X:%hh02X:%hh02X:%hh02X",&mac[0],&mac[1],&mac[2],&mac[3],&mac[4],&mac[5])){
    printf("%hh02X:%hh02X:%hh02X:%hh02X:%hh02X:%hh02X",&mac[0],&mac[1],&mac[2],&mac[3],&mac[4],&mac[5]);
  }
}
