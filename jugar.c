#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <time.h>

int main(){
    int i,x, turno[4];
    DIR *dir;
    struct dirent *ent;
    int flag = 1, fake = 0;
    turno[0] = getpid();
    for(i=0; i<3; i++ ){
        x = fork();
        if(x == 0){
            break;
        }
        turno[i+1] = x;
    }
    while(flag){
        char * carta = (char * )malloc(sizeof(char)*40);
        if ((dir = opendir ("juego")) != NULL) {
            while ((ent = readdir(dir)) != NULL) {
                if (fake < 2){
                    fake++;
                }
                else{
                    strcpy(carta,ent->d_name);
                }
            }
            if(carta[0]=='2'){
                if(carta[2] == 'm'){
                    
                }
                else if(carta[1] == 'v'){
                    
                }
            }
            strcpy(cartas,"j1/");
                    strcat(cartas,ent->d_name);
                    FILE* carta= fopen(cartas,"w");
                    fclose(carta);
                    char * borrar = (char * )malloc(sizeof(char)*40);
                    strcpy(borrar,"mazo/");
                    strcat(borrar,ent->d_name);
                    remove(borrar);
                    free(cartas);
                    free(borrar);
            closedir(dir);
        }
    }    
}