#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_file(void);
void create_file(void);
void write_file_to_binary(void);


//DRIVER FUNCTION
int main(void){


//create_file();
write_file_to_binary();
//read_file();


    return 0;
}

void read_file(void){
    
    FILE *p;char c=' ';
    p=fopen("test.txt","r");
  if(!p==NULL){
        while(!feof(p)){
        c=fgetc(p);
        printf("%c",c);



    }
    fclose(p);

  }
  else{
      printf("File could'nt be opened !\n");
      exit(0);
  }
}


void create_file(void){
FILE *p;
p=fopen("test.txt","w");
if(!p==NULL){
    printf("The file has been succesfully created !\n");
    fclose(p);
  
}
else{
    printf("Error creating file!\n");
    exit(0);
}



}

void write_file_to_binary(void){
    char arr[200];
    printf("Input the data you want to write to the file :\n");
    fgets(arr,200,stdin);
    FILE *p;
    p=fopen("test.bin","w");
    if(!p==NULL){
        fwrite(arr,sizeof(char),sizeof(arr),p);
        fclose(p);
    }
    else{
        printf("Operation failed!\n");
        exit(0);
    }






}