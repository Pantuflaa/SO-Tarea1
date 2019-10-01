#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <time.h>

int main()
{
    /*

Creación de carpetas que albergaran los mazos y las manos de los jugadores.

    */
    struct stat st = {0};
    if (stat("mazo", &st) == -1) {
        mkdir("mazo", 0700);
    }
    if (stat("j1", &st) == -1) {
        mkdir("j1", 0700);
    }
    if (stat("j2", &st) == -1) {
        mkdir("j2", 0700);
    }
    if (stat("j3", &st) == -1) {
        mkdir("j3", 0700);
    }
    if (stat("j4", &st) == -1) {
        mkdir("j4", 0700);
    }
    if (stat("juego", &st) == -1) {
        mkdir("juego", 0700);
    }
/*


Creación de string con números


*/
    char ** numeros = (char **)malloc(sizeof(char *)*10);
    int i = 0;
    for ( i = 0; i < 10; i++)
    {
        char * numero= (char *)malloc(sizeof(char)*8);
        if (i==0)
        {
            strcpy(numero,"cero");
            numeros[i]=numero;
        }
        if (i==1)
        {
            strcpy(numero,"uno");
            numeros[i]=numero;

        }

        if (i==2)
        {
            strcpy(numero,"dos");
            numeros[i]=numero;
        }

        if (i==3)
        {
            strcpy(numero,"tres");
            numeros[i]=numero;
        }

        if (i==4)
        {
            strcpy(numero,"cuatro");
            numeros[i]=numero;
        }

        if (i==5)
        {
            strcpy(numero,"cinco");
            numeros[i]=numero;
        }

        if (i==6)
        {
            strcpy(numero,"seis");
            numeros[i]=numero;
        }

        if (i==7)
        {
            strcpy(numero,"siete");
            numeros[i]=numero;
        }

        if (i==8)
        {
            strcpy(numero,"ocho");
            numeros[i]=numero;
        }

        if (i==9)
        {
            strcpy(numero,"nueve");
            numeros[i]=numero;
        }
    }

    /*


Creación de string de colores

    */
    char ** colores = (char **)malloc(sizeof(char*)*4);
    for (i = 0; i <4;  i++)
    {
        char* color = (char*)malloc(sizeof(char)*10);
        if (i==0)
        {
           strcpy(color,"rojo");
        }
        if (i==1)
        {
            strcpy(color,"azul");
        }
        if (i==2)
        {
           strcpy(color,"verde");
        }
        if (i==3)
        {
            strcpy(color,"amarillo");
        }
        colores[i]=color;

    }

    /*

Creación de todas las cartas del mazo

    */

   for ( i = 0; i < 4; i++)
   {
        char * archivo= (char *)malloc(sizeof(char)*30);
        char * archivo2= (char *)malloc(sizeof(char)*30);
        strcpy(archivo,"mazo/");
        strcpy(archivo2,"mazo/2");
        strcat(archivo,colores[i]);
        strcat(archivo2,colores[i]);
        strcat(archivo,"masdos.txt");
        strcat(archivo2,"masdos.txt");
        FILE* file1 = fopen(archivo, "w");
        fclose(file1);
        FILE* file2 = fopen(archivo2, "w");
        fclose(file2);
        strcpy(archivo,"mazo/");
        strcpy(archivo2,"mazo/2");
        strcat(archivo,colores[i]);
        strcat(archivo2,colores[i]);
        strcat(archivo,"reversa.txt");
        strcat(archivo2,"reversa.txt");
        FILE* file3 = fopen(archivo, "w");
        fclose(file3);
        FILE* file4 = fopen(archivo2, "w");
        fclose(file4);
         strcpy(archivo,"mazo/");
        strcpy(archivo2,"mazo/2");
        strcat(archivo,colores[i]);
        strcat(archivo2,colores[i]);
        strcat(archivo,"cancelar.txt");
        strcat(archivo2,"cancelar.txt");
        FILE* file5 = fopen(archivo, "w");
        fclose(file5);
        FILE* file6 = fopen(archivo2, "w");
        fclose(file6);
        free(archivo);
        free(archivo2);
       int i2;
       for (i2 = 0; i2 < 10; i2++)
       {
           if (i2==0){
                char * archivo= (char *)malloc(sizeof(char)*30);
                strcpy(archivo,"mazo/");
                strcat(archivo,colores[i]);
                strcat(archivo,numeros[i2]);
                strcat(archivo,".txt");
                FILE* file1 = fopen(archivo, "w");
                fclose(file1);
                free(archivo);
           }
           else{
                char * archivo= (char *)malloc(sizeof(char)*30);
                char * archivo2= (char *)malloc(sizeof(char)*30);
                strcpy(archivo,"mazo/");
                strcpy(archivo2,"mazo/2");
                strcat(archivo,colores[i]);
                strcat(archivo,numeros[i2]);
                strcat(archivo,".txt");
                strcat(archivo2,colores[i]);
                strcat(archivo2,numeros[i2]);
                strcat(archivo2,".txt");
                FILE* file1 = fopen(archivo, "w");
                fclose(file1);
                FILE* file2 = fopen(archivo2, "w");
                fclose(file2);
                free(archivo);
                free(archivo2);
            }
        }
   }
    FILE* file1 = fopen("mazo/negramascuatro.txt", "w");
    FILE* file2 = fopen("mazo/2negramascuatro.txt", "w");
    FILE* file3 = fopen("mazo/3negramascuatro.txt", "w");
    FILE* file4 = fopen("mazo/4negramascuatro.txt", "w");
    FILE* file5 = fopen("mazo/negracolores.txt", "w");
    FILE* file6 = fopen("mazo/2negracolores.txt", "w");
    FILE* file7 = fopen("mazo/3negracolores.txt", "w");
    FILE* file8 = fopen("mazo/4negracolores.txt", "w");
    fclose(file1);
    fclose(file2);
    fclose(file3);
    fclose(file4);
    fclose(file5);
    fclose(file6);
    fclose(file7);
    fclose(file8);

/*

Repartir las cartas al azar a todos los jugadores.

*/


    srand(time(NULL));

    int mano1[7];
    int mano2[7];
    int mano3[7];
    int mano4[7];
    int flag=1;
    while (flag)
    {
        int si=1;
        for (i = 0; i < 7; i++) {
            int r = rand() % 109;
            mano1[i]=r;
        }
        for (i = 0; i < 7; i++)
        {
            int i2;
            int copias=0;
            for (i2 = 0; i2 < 7; i2++)
            {
               if(mano1[i]==mano1[i2]){
                   copias+=1;
               }
               if (copias>=2)
               {
                   si=0;
                   break;
               }

            }
            if (copias>=2)
            {
                si=0;
                break;
            }


        }
        if(si) flag=0;

    }





    DIR *dir;
    struct dirent *ent;
    int fake=0;
    int cont=0;
    if ((dir = opendir ("mazo")) != NULL) {
        while ((ent = readdir (dir)) != NULL) {
            if (fake < 2){
                fake++;
            }
            else if((cont==mano1[0])|(cont==mano1[1]) | (cont==mano1[2])|(cont==mano1[3])|(cont==mano1[4])|(cont==mano1[5])|(cont==mano1[6])){
                char * cartas = (char * )malloc(sizeof(char)*40);
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
             }
            cont++;
        }
    closedir (dir);
    }


    flag=1;
     while (flag)
    {
        int si=1;
        for (i = 0; i < 7; i++) {
            int r = rand() % 102;
            mano2[i]=r;
        }
        for (i = 0; i < 7; i++)
        {
            int i2;
            int copias=0;
            for (i2 = 0; i2 < 7; i2++)
            {
               if(mano2[i]==mano2[i2]){
                   copias+=1;
               }
               if (copias>=2)
               {
                   si=0;
                   break;
               }

            }
            if (copias>=2)
            {
                si=0;
                break;
            }


        }
        if(si) flag=0;

    }
    fake=0;
    cont=0;
    if ((dir = opendir ("mazo")) != NULL) {
        while ((ent = readdir (dir)) != NULL) {
            if (fake < 2)
            {
                fake++;
            }

            else if((cont==mano2[0])|(cont==mano2[1] )| (cont==mano2[2])|(cont==mano2[3])|(cont==mano2[4])|(cont==mano2[5])|(cont==mano2[6])){
                char * cartas = (char * )malloc(sizeof(char)*40);
                strcpy(cartas,"j2/");
                strcat(cartas,ent->d_name);
                FILE* carta= fopen(cartas,"w");
                fclose(carta);
                char * borrar = (char * )malloc(sizeof(char)*40);
                strcpy(borrar,"mazo/");
                strcat(borrar,ent->d_name);
                remove(borrar);
                free(cartas);
                free(borrar);
             }
            cont++;
        }
    closedir (dir);
    }


     flag=1;
     while (flag)
    {
        int si=1;
        for (i = 0; i < 7; i++) {
            int r = rand() % 95;
            mano3[i]=r;
        }
        for (i = 0; i < 7; i++)
        {
            int i2;
            int copias=0;
            for (i2 = 0; i2 < 7; i2++)
            {
               if(mano3[i]==mano3[i2]){
                   copias+=1;
               }
               if (copias>=2)
               {
                   si=0;
                   break;
               }

            }
            if (copias>=2)
            {
                si=0;
                break;
            }


        }
        if(si) flag=0;

    }
    cont=0;
    fake = 0;
    if ((dir = opendir ("mazo")) != NULL) {
        while ((ent = readdir (dir)) != NULL) {
            if (fake < 2)
            {
                fake++;
            }

            else if((cont==mano3[0])|(cont==mano3[1]) | (cont==mano3[2])|(cont==mano3[3])|(cont==mano3[4])|(cont==mano3[5])|(cont==mano3[6])){
                char * cartas = (char * )malloc(sizeof(char)*40);
                strcpy(cartas,"j3/");
                strcat(cartas,ent->d_name);
                FILE* carta= fopen(cartas,"w");
                fclose(carta);
                char * borrar = (char * )malloc(sizeof(char)*40);
                strcpy(borrar,"mazo/");
                strcat(borrar,ent->d_name);
                remove(borrar);
                free(cartas);
                free(borrar);
             }
            cont++;
        }
    closedir (dir);
    }


     flag=1;
     while (flag)
    {
        int si=1;
        for (i = 0; i < 7; i++) {
            int r = rand() % 88;
            mano4[i]=r;
        }
        for (i = 0; i < 7; i++)
        {
            int i2;
            int copias=0;
            for (i2 = 0; i2 < 7; i2++)
            {
               if(mano4[i]==mano4[i2]){
                   copias+=1;
               }
               if (copias>=2)
               {
                   si=0;
                   break;
               }

            }
            if (copias>=2)
            {
                si=0;
                break;
            }


        }
        if(si) flag=0;

    }
    cont=0;
    fake = 0;
    if ((dir = opendir ("mazo")) != NULL) {
        while ((ent = readdir (dir)) != NULL) {
            if (fake < 2)
            {
                fake++;
            }

            else if((cont==mano4[0])|(cont==mano4[1]) | (cont==mano4[2])|(cont==mano4[3])|(cont==mano4[4])|(cont==mano4[5])|(cont==mano4[6])){
                char * cartas = (char * )malloc(sizeof(char)*40);
                strcpy(cartas,"j4/");
                strcat(cartas,ent->d_name);
                FILE* carta= fopen(cartas,"w");
                fclose(carta);
                char * borrar = (char * )malloc(sizeof(char)*40);
                strcpy(borrar,"mazo/");
                strcat(borrar,ent->d_name);
                remove(borrar);
                free(cartas);
                free(borrar);
             }
            cont++;
        }
    closedir (dir);
    }


printf("xd\n");
printf("JAJAJA\n");



    return 0;
}
