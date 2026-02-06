#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(int argc, char **argv){
  srand(time(NULL));
  char chars[]="qwertyuiopassdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890";

  int dim=atoi(argv[1]);

  FILE *fout=NULL;

  if(!(fout=fopen(argv[2],"wt"))){
    printf("err fisier");
    return 1;
  }

  char *s=malloc(dim+1);
  for(int i=0 ; i<dim ; i++){
    char c=chars[rand()%strlen(chars)];
    s[i]=c;
  }

  s[dim]=0;
  fprintf(fout,"%s",s);

  free(s);
  fclose(fout);
  
  return 0;
}
