#include <stdio.h>
#include <stdint.h>

void print_bits(uint32_t n){
  uint32_t mask=1<<31;

  for(int i=0 ; i<32 ; i++){
    if(n&mask)
      printf("1");
    else
      printf("0");

    mask>>=1;
  }
  return ;
}

int revNib(uint32_t n){
  uint32_t new=0;

  for(int i=2*sizeof(uint32_t)-1 ; i>=0 ; i--){
    for(int j=0 ; j<4 ; j++){
      if(n&1){
	new+=(1<<(4*i+j));
      }
      n>>=1;
    }
  }

  return new;
}

int revBits(uint32_t n){
  uint32_t nr=0;

  for(int i=0 ; i<sizeof(uint32_t)*2 ; i++){
    for(int j=0 ; j<4 ; j++){
      if(n&1){
	nr+=1<<(3-j+4*i);
      }
      n>>=1;
    }
  }

  return nr;
}

int main(){
  uint32_t n=165;
  print_bits(revBits(n));
  printf("\n");
  print_bits(revNib(n));
}
