#include <stdio.h>
#include <stdint.h>

int nrb(uint32_t n){
  int nr=0;
  uint32_t mask=1<<31;

  for(int i=0 ; i<32 ; i++){
    if(n & mask) nr++;
    mask>>=1;
  }

  return nr;
}

int main(){
  uint32_t n=15;
  printf("%d",nrb(n));
}
