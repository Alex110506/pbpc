#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

FILE *fin=NULL;
FILE *fout=NULL;

char **lines;
int idxLin=0;

void write_sort(char **lines, char *file){
  if((fout=fopen(file,"wt"))==NULL){
    return;
  }
  
  for(int i=0 ; i<idxLin ; i++){
    for(int j=i+1 ; j<idxLin ; j++){
      if(strcmp(lines[i],lines[j])>0){
	char *aux=lines[i];
	lines[i]=lines[j];
	lines[j]=aux;
      }
    }
  }

  for(int i=0 ; i<idxLin ; i++){
    fprintf(fout,"%s",lines[i]);
  }

  return;
}

void randomm(char **lines, char *file){
  if((fout=fopen(file,"wt"))==NULL){
    return;
  }
  
  srand(time(0));

  for(int i=idxLin-1 ; i>=0 ; i--){
    int rd=rand()%(i+1);
    char *aux=lines[rd];
    lines[rd]=lines[i];
    lines[i]=aux;
  }

  for(int i=0 ; i<idxLin ; i++){
    fprintf(fout,"%s",lines[i]);
  }

  return;
}

int main(){
  char *line=NULL;
  size_t size=0;
  
  if((fin=fopen("scrisoare.txt","rt"))==NULL){
    return 1;
  }

  while((getline(&line,&size,fin))>0){
    char *s=malloc(strlen(line)+1);
    strcpy(s,line);
    
    size_t ss=((idxLin+1) * sizeof(char*));
    lines=realloc(lines,ss);
    lines[idxLin]=s;
    idxLin++;
  }

  if((fout=fopen("outt.txt","wt"))==NULL){
    return 1;
  }
  
  randomm(lines,"outt.txt");

  fclose(fin);
  fclose(fout);
  free(line);
  for(int i=0 ; i<idxLin ; i++){
    free(lines[i]);
  }

  free(lines);
  
  return 0;
}
