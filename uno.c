#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <time.h>
int mano[4] = {7,7,7,7};
int cartasmazo = 79;


char leerPozo(){
     DIR *dir;

    struct dirent *ent;
    
    int fake = 0;
    char * carta = (char * )malloc(sizeof(char)*40);
    if ((dir = opendir ("juego")) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
                if (strcmp(ent->d_name,".") == 0 || strcmp(ent->d_name,"..") == 0 ){
                fake++;
            }
            else{
                strcpy(carta,ent->d_name);
                
            }
        }
    }
    if(carta[4]=='4'&& carta[1]=='n'){
        return 'z';
    }
    else{
        return carta[4];
    }
    
    
}


void robarN (int J , int n){
    int iteraciones;
    if (cartasmazo < n){
        iteraciones=cartasmazo;
    }else{
        iteraciones=n;
    }

    int sualazar[iteraciones];
    int i;
    
    for (i = 0; i < iteraciones; i++) {
        int r = rand() % cartasmazo+1;
        int i2;
        for ( i2 = 0; i2 < i; i2++)
        {
            if(r==sualazar[i2]){
                i2--;
                 r= rand() % cartasmazo+1;
            }
            
        }              
         sualazar[i]=r;   
    }
        
    DIR *dir;
    struct dirent *ent;
    int cont,k;
    int fake = 0;
    int cartas=iteraciones;

    if ((dir = opendir ("juego")) != NULL ) {
        while ((ent = readdir(dir)) != NULL||iteraciones !=0) {
            if (strcmp(ent->d_name,".") == 0 || strcmp(ent->d_name,"..") == 0 ){
                fake++;
            }
            else{
                for(k = 0; k < cartas; k++){
                    if(cont==sualazar[k]){
                         char* direccion= (char *)malloc(sizeof(char)*40);
                         strcpy(direccion, "mazo/");
                         strcat(direccion,ent->d_name);
                         remove(direccion);
                         if (J==1)
                         {     
                            strcpy(direccion,"j1/");
                         }
                         else if(J==2){
                            strcpy(direccion,"j2/");
        
                         }
                         else if(J==3){
                            strcpy(direccion,"j3/");                 
                         }
                         else
                         {
                            strcpy(direccion,"j4");
                             /* code */
                         }
                         strcat(direccion,ent->d_name);
                         FILE *F=fopen(direccion,"w");
                         fclose(F); 
                         free(direccion);
                         iteraciones--;                  
                         break;
                    }
                }
                
            }
            cont++;
        }
    }
    closedir(dir);
    cartasmazo-=cartas;

}
void crearArchivos(){
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
            strcpy(numero,"0");
            numeros[i]=numero;
        }
        if (i==1)
        {
            strcpy(numero,"1");
            numeros[i]=numero;

        }

        if (i==2)
        {
            strcpy(numero,"2");
            numeros[i]=numero;
        }

        if (i==3)
        {
            strcpy(numero,"3");
            numeros[i]=numero;
        }

        if (i==4)
        {
            strcpy(numero,"4");
            numeros[i]=numero;
        }

        if (i==5)
        {
            strcpy(numero,"5");
            numeros[i]=numero;
        }

        if (i==6)
        {
            strcpy(numero,"6");
            numeros[i]=numero;
        }

        if (i==7)
        {
            strcpy(numero,"7");
            numeros[i]=numero;
        }

        if (i==8)
        {
            strcpy(numero,"8");
            numeros[i]=numero;
        }

        if (i==9)
        {
            strcpy(numero,"9");
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
           strcpy(color,"roj");
        }
        if (i==1)
        {
            strcpy(color,"zul");
        }
        if (i==2)
        {
           strcpy(color,"ver");
        }
        if (i==3)
        {
            strcpy(color,"ama");
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
        strcpy(archivo,"mazo/1");
        strcpy(archivo2,"mazo/2");
        strcat(archivo,colores[i]);
        strcat(archivo2,colores[i]);
        strcat(archivo,"p.txt");
        strcat(archivo2,"p.txt");
        FILE* file1 = fopen(archivo, "w");
        fclose(file1);
        FILE* file2 = fopen(archivo2, "w");
        fclose(file2);
        strcpy(archivo,"mazo/1");
        strcpy(archivo2,"mazo/2");
        strcat(archivo,colores[i]);
        strcat(archivo2,colores[i]);
        strcat(archivo,"r.txt");
        strcat(archivo2,"r.txt");
        FILE* file3 = fopen(archivo, "w");
        fclose(file3);
        FILE* file4 = fopen(archivo2, "w");
        fclose(file4);
         strcpy(archivo,"mazo/1");
        strcpy(archivo2,"mazo/2");
        strcat(archivo,colores[i]);
        strcat(archivo2,colores[i]);
        strcat(archivo,"b.txt");
        strcat(archivo2,"b.txt");
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
                strcpy(archivo,"mazo/1");
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
                strcpy(archivo,"mazo/1");
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
    FILE* file1 = fopen("mazo/1ngr4.txt", "w");
    FILE* file2 = fopen("mazo/2ngr4.txt", "w");
    FILE* file3 = fopen("mazo/3ngr4.txt", "w");
    FILE* file4 = fopen("mazo/4ngr4.txt", "w");
    FILE* file5 = fopen("mazo/1ngrc.txt", "w");
    FILE* file6 = fopen("mazo/2ngrc.txt", "w");
    FILE* file7 = fopen("mazo/3ngrc.txt", "w");
    FILE* file8 = fopen("mazo/4ngrc.txt", "w");
    fclose(file1);
    fclose(file2);
    fclose(file3);
    fclose(file4);
    fclose(file5);
    fclose(file6);
    fclose(file7);
    fclose(file8);

/*

Repartir las cartas al azar a todos los jugadores y una carta al azar al pozo de juego.

*/


    srand(time(NULL));

    int mano1[7];
    int mano2[7];
    int mano3[7];
    int mano4[7];
  
    for (i = 0; i < 7; i++) {
        int r = rand() % 107;
        int i2;
        for ( i2 = 0; i2 < i; i2++)
        {
            if(r==mano1[i2]){
                i2--;
                 r= rand() % 107;
            }
        }              
         mano1[i]=r;
        
    }


    DIR *dir;
    struct dirent *ent;
    int fake=0;
    int cont=0;
    if ((dir = opendir ("mazo")) != NULL) {
        while ((ent = readdir (dir)) != NULL) {
            if (fake < 2){
                fake++;
                cont--;
            }
        else if((cont==mano1[0])||(cont==mano1[1]) || (cont==mano1[2])||(cont==mano1[3])||(cont==mano1[4])||(cont==mano1[5])||(cont==mano1[6])){
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
   
    for (i = 0; i < 7; i++) {
        int r = rand() % 100;
        int i2;
        for ( i2 = 0; i2 < i; i2++)
        {
            if(r==mano2[i2]){
                i2--;
                 r= rand() % 100;
            }
        }              
         mano2[i]=r;
        
    }
        
    fake=0;
    cont=0;
    if ((dir = opendir ("mazo")) != NULL) {
        while ((ent = readdir (dir)) != NULL) {
            if (fake < 2)
            {
                fake++;
                cont--;
            }

            else if((cont==mano2[0])||(cont==mano2[1] )|| (cont==mano2[2])||(cont==mano2[3])||(cont==mano2[4])||(cont==mano2[5])||(cont==mano2[6])){
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


       
    for (i = 0; i < 7; i++) {
        int r = rand() % 93;
        int i2;
        for ( i2 = 0; i2 < i; i2++)
        {
            if(r==mano3[i2]){
                i2--;
                 r= rand() % 93;
            }
        }              
         mano3[i]=r;
         
    }
        
       
    cont=0;
    fake = 0;
    if ((dir = opendir ("mazo")) != NULL) {
        while ((ent = readdir (dir)) != NULL) {
            if (fake < 2)
            {
                fake++;
                cont--;
            }

            else if((cont==mano3[0])||(cont==mano3[1]) || (cont==mano3[2])||(cont==mano3[3])||(cont==mano3[4])||(cont==mano3[5])||(cont==mano3[6])){
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


     
    for (i = 0; i < 7; i++) {
        int r = rand() % 86;
        int i2;
        for ( i2 = 0; i2 < i; i2++)
        {
            if(r==mano4[i2]){
                i2--;
                 r= rand() % 86;
            }
            
        }              
         mano4[i]=r;
       
    }
        
    cont=0;
    fake = 0;
    if ((dir = opendir ("mazo")) != NULL) {
        while ((ent = readdir (dir)) != NULL) {
            if (fake < 2)
            {
                fake++;
                cont--;
            }

            else if((cont==mano4[0])||(cont==mano4[1]) || (cont==mano4[2])||(cont==mano4[3])||(cont==mano4[4])||(cont==mano4[5])||(cont==mano4[6])){
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

    int r = rand() % 79;
    cont = 0;
    fake = 0;
    if ((dir = opendir ("mazo")) != NULL) {
        while ((ent = readdir (dir)) != NULL) {
            if (fake < 2)
            {
                fake++;
                cont--;
            }
            else if(cont == r)
            {
                char * cartas = (char * )malloc(sizeof(char)*40);
                strcpy(cartas,"juego/");
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
        closedir(dir);
    }
    for(i = 0; i < 4; i++){
        free(colores[i]);
    }
    free(colores);

    for(i = 0; i < 10; i++){
        free(numeros[i]);
    }
    free(numeros);
}

char robar (int J){
    sleep(1);
    DIR *dir;
    struct dirent *ent;
    struct dirent *aux;  
    char * nent = (char * )malloc(sizeof(char)*40);
    char * naux = (char * )malloc(sizeof(char)*40);
    int fake=0;
    int cont=0;
    int random= rand() % (cartasmazo+1);
    if(cartasmazo<=0){
        printf("El jugador %d no puede robar carta, ya que el mazo está vacío",J);
        free(nent);
        free(naux);
    }
    else{
        if ((dir = opendir ("juego")) != NULL){
            int newfake=0;
             while ((ent = readdir (dir)) != NULL) {
                 if (newfake < 2)
                 {

                     newfake++;
                 }
                 else
                 {
                    aux = ent;
                    strcpy(naux,aux->d_name);
                    closedir(dir);
                    break;
                 }
                 
                 
             }

        }
        if ((dir = opendir ("mazo")) != NULL) {       
            if (J==1)
            {
                while ((ent = readdir (dir)) != NULL) {
                    if (fake < 2){
                        fake++;
                    }
                    else if (cont==random)
                    {
                       char * mazo= (char * )malloc(sizeof(char)*40); 
                       strcpy(mazo,"mazo/");
                       strcat(mazo,ent->d_name);
                       remove(mazo);
                       free(mazo);
                       cartasmazo--;
                       printf("El jugador %d robó la carta %s\n",J,ent->d_name);
                       strcpy(nent,ent->d_name);
                 
                       if (nent[4]=='c'||(nent[1]=='n'&& nent[4]=='4'))
                       {
                           while (1)
                           {
                               printf("Desea jugarla?\n1.-Si\n2.-No\nIngrese su opción:");
                               int op;
                               scanf("%d",&op);
                               printf("\n");
                                if (op==1)
                                {     
                                    while (1)
                                    {
                                      printf("Seleccione el color que desea:\n0.-Rojo\n1.-Verde\n2.-Azul\n3.-Amarillo\nIngrese su opcion:");
                                        int r;
                                        scanf("%d",&r);
                                        if(r == 0){
                                             char * play = (char * )malloc(sizeof(char)*40);
                                            strcpy(play,"juego/");
                                            strcat(play,"_roj_.txt");
                                            printf("La carta se ha jugado\n");
                                            char * borrar = (char * )malloc(sizeof(char)*40);
                                            strcpy(borrar,"juego/");
                                            strcat(borrar,naux);
                                            remove(borrar);
                                          
                                            FILE* file1 = fopen(play, "w");
                                            fclose(file1);
            
                                            char re = play[4];
                                            free(borrar);
                                            free(play);
                                            free(nent);
                                            free(naux);
                                            closedir(dir);
                                            if (nent[1]=='n'&& nent[4]=='4')
                                            {
                                                return 'n';
                                            }
                                            
                                            return re;   

                                            break;

                                        }
                                        else if(r == 1){
                                             char * play = (char * )malloc(sizeof(char)*40);
                                            strcpy(play,"juego/");
                                            strcat(play,"_ver_.txt");
                                            printf("La carta se ha jugado\n");
                                            char * borrar = (char * )malloc(sizeof(char)*40);
                                            strcpy(borrar,"juego/");
                                            strcat(borrar,naux);
                                            remove(borrar);
                                 
                                            FILE* file1 = fopen(play, "w");
                                            fclose(file1);
                                         
                                            printf("Y la jugó\n");
                                            char re = play[4];
                                            free(borrar);
                                            free(play);
                                            free(nent);
                                            free(naux);
                                            closedir(dir);
                                            if (nent[1]=='n'&& nent[4]=='4')
                                            {
                                                return 'n';
                                            }
                                            
                                            return re;   

                                            break;

                                        }
                                        else if(r == 2){
                                             char * play = (char * )malloc(sizeof(char)*40);
                                            strcpy(play,"juego/");
                                            strcat(play,"_zul_.txt");
                                            printf("La carta se ha jugado\n");
                                            char * borrar = (char * )malloc(sizeof(char)*40);
                                            strcpy(borrar,"juego/");
                                            strcat(borrar,naux);
                                            remove(borrar);
                                        
                                            FILE* file1 = fopen(play, "w");
                                            fclose(file1);
                                      
                                            printf("Y la jugó\n");
                                            char re = play[4];
                                            free(borrar);
                                            free(play);
                                            free(nent);
                                            free(naux);
                                            closedir(dir);
                                            if (nent[1]=='n'&& nent[4]=='4')
                                            {
                                                return 'n';
                                            }
                                            
                                            return re;   

                                            break;

                                        }
                                        else if (r==3)
                                        {
                                            char * play = (char * )malloc(sizeof(char)*40);
                                            strcpy(play,"juego/");
                                            strcat(play,"_ama_.txt");
                                            printf("La carta se ha jugado\n");
                                            char * borrar = (char * )malloc(sizeof(char)*40);
                                            strcpy(borrar,"juego/");
                                            strcat(borrar,naux);
                                            remove(borrar);
                                      
                                            FILE* file1 = fopen(play, "w");
                                            fclose(file1);
                                      
                                            char re = play[4];
                                            free(borrar);
                                            free(play);
                                            free(nent);
                                            free(naux);
                                            closedir(dir);
                                            if (nent[1]=='n'&& nent[4]=='4')
                                            {
                                                return 'n';
                                            }
                                            
                                            return re;   

                                           break;
                                        }
                                        else
                                        {
                                            printf("Opción invalida, ingrese de nuevo su color.\n");
                                        }
                                    }
                                    
                                          
                                        
                                  
                                }
                                else if(op==2){
                                        printf("El jugador %d ha guardado la carta en su mano\n",J);
                                        char * guardar = (char * )malloc(sizeof(char)*40);
                                        strcpy(guardar,"j1/");
                                        strcat(guardar,ent->d_name);
                                        FILE* file1 = fopen(guardar, "w");
                                        fclose(file1);
                                        free(guardar);
                                        closedir(dir);
                                        mano[0]++;

                                        return 'x';
                                        break;

                                }
                                else{
                                    printf("Opción invalida, ingrese nuevamente\n");
                                }
                           }
                           
                         
                          

                          
                           
                       }   
                       else if (nent[1]==naux[1]||nent[4]==naux[4])
                       {
                            while (1)
                            {
                                /* code */
                                printf("Ha obtenido la carta %s\n",nent);
                                printf("Desea jugarla?\n1.-Si\n2.-No\nIngrese su opción:");
                                int op;
                                scanf("%d",&op);
                                printf("\n");
                                if(op==1){
                                    char * borrar = (char * )malloc(sizeof(char)*40);
                                    strcpy(borrar,"juego/");
                                    strcat(borrar,naux);
                                    remove(borrar);
                             
                                    char * agregar= (char *)malloc(sizeof(char)*40);
                                    strcpy(agregar,"juego/");
                                    strcat(agregar,ent->d_name);
                                    FILE* file1 = fopen(agregar, "w");
                                    fclose(file1);
                            
                                    printf("Ha jugado la carta\n");
                                    char re = agregar[4];
                                    free(borrar);
                                    free(agregar);
                                    free(nent);
                                    free(naux);
                                    closedir(dir);
                                    return re;

                                }
                                else if(op==2){
                                        printf("El jugador %d ha guardado la carta en su mano\n",J);
                                    char * guardar = (char * )malloc(sizeof(char)*40);
                                    strcpy(guardar,"j1/");
                                    strcat(guardar,ent->d_name);
                                    FILE* file1 = fopen(guardar, "w");
                                    fclose(file1);
                                    free(guardar);
                                    closedir(dir);
                                    mano[0]++;

                                    return 'x';
                                    break;

                                }
                                else{
                                    printf("Opción invalida, ingresela nuevamente\n");
                                }    
                            }
                       } 
                       else
                       {
                           printf("El jugador %d ha guardado la carta en su mano\n",J);
                           char * guardar = (char * )malloc(sizeof(char)*40);
                           strcpy(guardar,"j1/");
                           strcat(guardar,ent->d_name);
                           FILE* file1 = fopen(guardar, "w");
                           fclose(file1);
                           free(guardar);
                            closedir(dir);
                            mano[0]++;

                           return 'x';
                           break;
                       }
                       
                        
                    }
                    cont++;
                }
            }
            else if (J==2)
            {
                   while ((ent = readdir (dir)) != NULL) {
                    if (fake < 2){
                        fake++;
                    }
                    else if (cont==random)
                    {
                       char * mazo= (char * )malloc(sizeof(char)*40); 
                       strcpy(mazo,"mazo/");
                       strcat(mazo,ent->d_name);
                       remove(mazo);
                       free(mazo);
                       cartasmazo--;
                       printf("El jugador %d robó la carta %s\n",J,ent->d_name);
                       strcpy(nent,ent->d_name);
                       printf("%s\n",nent);
                       printf("%s\n",naux);
                       if (nent[4]=='c'||(nent[1]=='n'&& nent[4]=='4'))
                       {
                           while (1)
                           {
                               printf("Ha obtenido la carta %s\n",nent);
                               printf("Desea jugarla?\n1.-Si\n2.-No\nIngrese su opción:");
                               int op;
                               scanf("%d",&op);
                               printf("\n");
                                if (op==1)
                                {     
                                    while (1)
                                    {
                                      printf("Seleccione el color que desea:\n0.-Rojo\n1.-Verde\n2.-Azul\n3.-Amarillo\nIngrese su opcion:");
                                        int r;
                                        scanf("%d",&r);
                                        if(r == 0){
                                             char * play = (char * )malloc(sizeof(char)*40);
                                            strcpy(play,"juego/");
                                            strcat(play,"_roj_.txt");
                                            printf("La carta se ha jugado\n");
                                            char * borrar = (char * )malloc(sizeof(char)*40);
                                            strcpy(borrar,"juego/");
                                            strcat(borrar,naux);
                                            remove(borrar);
                                          
                                            FILE* file1 = fopen(play, "w");
                                            fclose(file1);
              
                                            printf("Y la jugó\n");
                                            char re = play[4];
                                            free(borrar);
                                            free(play);
                                            free(nent);
                                            free(naux);
                                            closedir(dir);
                                            if (nent[1]=='n'&& nent[4]=='4')
                                            {
                                                return 'n';
                                            }
                                            
                                            return re;   

                                            break;

                                        }
                                        else if(r == 1){
                                             char * play = (char * )malloc(sizeof(char)*40);
                                            strcpy(play,"juego/");
                                            strcat(play,"_ver_.txt");
                                            printf("La carta se ha jugado\n");
                                            char * borrar = (char * )malloc(sizeof(char)*40);
                                            strcpy(borrar,"juego/");
                                            strcat(borrar,naux);
                                            remove(borrar);
                                 
                                            FILE* file1 = fopen(play, "w");
                                            fclose(file1);
                                         
                                            printf("Y la jugó\n");
                                            char re = play[4];
                                            free(borrar);
                                            free(play);
                                            free(nent);
                                            free(naux);
                                            closedir(dir);
                                            if (nent[1]=='n'&& nent[4]=='4')
                                            {
                                                return 'n';
                                            }
                                            
                                            return re;   

                                            break;

                                        }
                                        else if(r == 2){
                                             char * play = (char * )malloc(sizeof(char)*40);
                                            strcpy(play,"juego/");
                                            strcat(play,"_zul_.txt");
                                            printf("La carta se ha jugado\n");
                                            char * borrar = (char * )malloc(sizeof(char)*40);
                                            strcpy(borrar,"juego/");
                                            strcat(borrar,naux);
                                            remove(borrar);
                                        
                                            FILE* file1 = fopen(play, "w");
                                            fclose(file1);
                                      
                                            printf("Y la jugó\n");
                                            char re = play[4];
                                            free(borrar);
                                            free(play);
                                            free(nent);
                                            free(naux);
                                            closedir(dir);
                                            if (nent[1]=='n'&& nent[4]=='4')
                                            {
                                                return 'n';
                                            }
                                            
                                            return re;   

                                            break;

                                        }
                                        else if (r==3)
                                        {
                                            char * play = (char * )malloc(sizeof(char)*40);
                                            strcpy(play,"juego/");
                                            strcat(play,"_ama_.txt");
                                            printf("La carta se ha jugado\n");
                                            char * borrar = (char * )malloc(sizeof(char)*40);
                                            strcpy(borrar,"juego/");
                                            strcat(borrar,naux);
                                            remove(borrar);
                                      
                                            FILE* file1 = fopen(play, "w");
                                            fclose(file1);
                                      
                                            printf("Y la jugó\n");
                                            char re = play[4];
                                            free(borrar);
                                            free(play);
                                            free(nent);
                                            free(naux);
                                            closedir(dir);
                                            if (nent[1]=='n'&& nent[4]=='4')
                                            {
                                                return 'n';
                                            }
                                            
                                            return re;   

                                           break;
                                        }
                                        else
                                        {
                                            printf("Opción invalida, ingrese de nuevo su color.\n");
                                        }
                                    }
                                    
                                          
                                        
                                  
                                }
                                else if(op==2){
                                        printf("Y la guardó en su mano\n");
                                        char * guardar = (char * )malloc(sizeof(char)*40);
                                        strcpy(guardar,"j2/");
                                        strcat(guardar,ent->d_name);
                                        FILE* file1 = fopen(guardar, "w");
                                        fclose(file1);
                                        free(guardar);
                                        closedir(dir);
                                        mano[1]++;

                                        return 'x';
                                        break;

                                }
                                else{
                                    printf("Opción invalida, ingrese nuevamente\n");
                                }
                           }
                           
                         
                          

                          
                           
                       }   
                       else if (nent[1]==naux[1]||nent[4]==naux[4])
                       {
                            while (1)
                            {
                                /* code */
                                printf("Ha obtenido la carta %s\n",nent);
                                printf("Desea jugarla?\n1.- Si\n2.-No\nIngrese su opción:");
                                int op;
                                scanf("%d",&op);
                                printf("\n");
                                if(op==1){
                                    char * borrar = (char * )malloc(sizeof(char)*40);
                                    strcpy(borrar,"juego/");
                                    strcat(borrar,naux);
                                    remove(borrar);
                             
                                    char * agregar= (char *)malloc(sizeof(char)*40);
                                    strcpy(agregar,"juego/");
                                    strcat(agregar,ent->d_name);
                                    FILE* file1 = fopen(agregar, "w");
                                    fclose(file1);
                            
                                    printf("Y la jugó\n");
                                    char re = agregar[4];
                                    free(borrar);
                                    free(agregar);
                                    free(nent);
                                    free(naux);
                                    closedir(dir);
                                    return re;

                                }
                                else if(op==2){
                                        printf("Y la guardó en su mano\n");
                                    char * guardar = (char * )malloc(sizeof(char)*40);
                                    strcpy(guardar,"j2/");
                                    strcat(guardar,ent->d_name);
                                    FILE* file1 = fopen(guardar, "w");
                                    fclose(file1);
                                    free(guardar);
                                    closedir(dir);
                                    mano[1]++;

                                    return 'x';
                                    break;

                                }
                                else{
                                    printf("Opción invalida, ingresela nuevamente\n");
                                }    
                            }
                       } 
                       else
                       {
                           printf("Y la guardó en su mano\n");
                           char * guardar = (char * )malloc(sizeof(char)*40);
                           strcpy(guardar,"j2/");
                           strcat(guardar,ent->d_name);
                           FILE* file1 = fopen(guardar, "w");
                           fclose(file1);
                           free(guardar);
                            closedir(dir);
                            mano[1]++;

                           return 'x';
                           break;
                       }
                       
                        
                    }
                    cont++;
                }
               
            }
            else if (J==3)
            {
                   while ((ent = readdir (dir)) != NULL) {
                    if (fake < 2){
                        fake++;
                    }
                    else if (cont==random)
                    {
                       char * mazo= (char * )malloc(sizeof(char)*40); 
                       strcpy(mazo,"mazo/");
                       strcat(mazo,ent->d_name);
                       remove(mazo);
                       free(mazo);
                       cartasmazo--;
                       printf("El jugador %d robó la carta %s\n",J,ent->d_name);
                       strcpy(nent,ent->d_name);
                       printf("%s\n",nent);
                       printf("%s\n",naux);
                       if (nent[4]=='c'||(nent[1]=='n'&& nent[4]=='4'))
                       {
                           while (1)
                           {
                               printf("Ha obtenido la carta %s\n",nent);
                               printf("Desea jugarla?\n1.- Si\n2.-No\nIngrese su opción:");
                               int op;
                               scanf("%d",&op);
                               printf("\n");
                                if (op==1)
                                {     
                                    while (1)
                                    {
                                      printf("Seleccione el color que desea:\n0.-Rojo\n1.-Verde\n2.-Azul\n3.-Amarillo\nIngrese su opcion:");
                                        int r;
                                        scanf("%d",&r);
                                        if(r == 0){
                                             char * play = (char * )malloc(sizeof(char)*40);
                                            strcpy(play,"juego/");
                                            strcat(play,"_roj_.txt");
                                            printf("La carta se ha jugado\n");
                                            char * borrar = (char * )malloc(sizeof(char)*40);
                                            strcpy(borrar,"juego/");
                                            strcat(borrar,naux);
                                            remove(borrar);
                                          
                                            FILE* file1 = fopen(play, "w");
                                            fclose(file1);
              
                                            printf("Y la jugó\n");
                                            char re = play[4];
                                            free(borrar);
                                            free(play);
                                            free(nent);
                                            free(naux);
                                            closedir(dir);
                                            if (nent[1]=='n'&& nent[4]=='4')
                                            {
                                                return 'n';
                                            }
                                            
                                            return re;   

                                            break;

                                        }
                                        else if(r == 1){
                                             char * play = (char * )malloc(sizeof(char)*40);
                                            strcpy(play,"juego/");
                                            strcat(play,"_ver_.txt");
                                            printf("La carta se ha jugado\n");
                                            char * borrar = (char * )malloc(sizeof(char)*40);
                                            strcpy(borrar,"juego/");
                                            strcat(borrar,naux);
                                            remove(borrar);
                                 
                                            FILE* file1 = fopen(play, "w");
                                            fclose(file1);
                                         
                                            printf("Y la jugó\n");
                                            char re = play[4];
                                            free(borrar);
                                            free(play);
                                            free(nent);
                                            free(naux);
                                            closedir(dir);
                                            if (nent[1]=='n'&& nent[4]=='4')
                                            {
                                                return 'n';
                                            }
                                            
                                            return re;   

                                            break;

                                        }
                                        else if(r == 2){
                                             char * play = (char * )malloc(sizeof(char)*40);
                                            strcpy(play,"juego/");
                                            strcat(play,"_zul_.txt");
                                            printf("La carta se ha jugado\n");
                                            char * borrar = (char * )malloc(sizeof(char)*40);
                                            strcpy(borrar,"juego/");
                                            strcat(borrar,naux);
                                            remove(borrar);
                                        
                                            FILE* file1 = fopen(play, "w");
                                            fclose(file1);
                                      
                                            printf("Y la jugó\n");
                                            char re = play[4];
                                            free(borrar);
                                            free(play);
                                            free(nent);
                                            free(naux);
                                            closedir(dir);
                                            if (nent[1]=='n'&& nent[4]=='4')
                                            {
                                                return 'n';
                                            }
                                            
                                            return re;   

                                            break;

                                        }
                                        else if (r==3)
                                        {
                                            char * play = (char * )malloc(sizeof(char)*40);
                                            strcpy(play,"juego/");
                                            strcat(play,"_ama_.txt");
                                            printf("La carta se ha jugado\n");
                                            char * borrar = (char * )malloc(sizeof(char)*40);
                                            strcpy(borrar,"juego/");
                                            strcat(borrar,naux);
                                            remove(borrar);
                                      
                                            FILE* file1 = fopen(play, "w");
                                            fclose(file1);
                                      
                                            printf("Y la jugó\n");
                                            char re = play[4];
                                            free(borrar);
                                            free(play);
                                            free(nent);
                                            free(naux);
                                            closedir(dir);
                                            if (nent[1]=='n'&& nent[4]=='4')
                                            {
                                                return 'n';
                                            }
                                            
                                            return re;   

                                           break;
                                        }
                                        else
                                        {
                                            printf("Opción invalida, ingrese de nuevo su color.\n");
                                        }
                                    }
                                    
                                          
                                        
                                  
                                }
                                else if(op==2){
                                        printf("Y la guardó en su mano\n");
                                        char * guardar = (char * )malloc(sizeof(char)*40);
                                        strcpy(guardar,"j3/");
                                        strcat(guardar,ent->d_name);
                                        FILE* file1 = fopen(guardar, "w");
                                        fclose(file1);
                                        free(guardar);
                                        closedir(dir);
                                        mano[2]++;

                                        return 'x';
                                        break;

                                }
                                else{
                                    printf("Opción invalida, ingrese nuevamente\n");
                                }
                           }
                           
                         
                          

                          
                           
                       }   
                       else if (nent[1]==naux[1]||nent[4]==naux[4])
                       {
                            while (1)
                            {
                                /* code */
                                printf("Ha obtenido la carta %s\n",nent);
                                printf("Desea jugarla?\n1.- Si\n2.-No\nIngrese su opción:");
                                int op;
                                scanf("%d",&op);
                                printf("\n");
                                if(op==1){
                                    char * borrar = (char * )malloc(sizeof(char)*40);
                                    strcpy(borrar,"juego/");
                                    strcat(borrar,naux);
                                    remove(borrar);
                             
                                    char * agregar= (char *)malloc(sizeof(char)*40);
                                    strcpy(agregar,"juego/");
                                    strcat(agregar,ent->d_name);
                                    FILE* file1 = fopen(agregar, "w");
                                    fclose(file1);
                            
                                    printf("Y la jugó\n");
                                    char re = agregar[4];
                                    free(borrar);
                                    free(agregar);
                                    free(nent);
                                    free(naux);
                                    closedir(dir);
                                    return re;

                                }
                                else if(op==2){
                                        printf("Y la guardó en su mano\n");
                                    char * guardar = (char * )malloc(sizeof(char)*40);
                                    strcpy(guardar,"j3/");
                                    strcat(guardar,ent->d_name);
                                    FILE* file1 = fopen(guardar, "w");
                                    fclose(file1);
                                    free(guardar);
                                    closedir(dir);
                                    mano[2]++;

                                    return 'x';
                                    break;

                                }
                                else{
                                    printf("Opción invalida, ingresela nuevamente\n");
                                }    
                            }
                       } 
                       else
                       {
                           printf("Y la guardó en su mano\n");
                           char * guardar = (char * )malloc(sizeof(char)*40);
                           strcpy(guardar,"j3/");
                           strcat(guardar,ent->d_name);
                           FILE* file1 = fopen(guardar, "w");
                           fclose(file1);
                           free(guardar);
                            closedir(dir);
                            mano[2]++;

                           return 'x';
                           break;
                       }
                       
                        
                    }
                    cont++;
                }
               
            }
            else if (J==4)
            {
                   while ((ent = readdir (dir)) != NULL) {
                    if (fake < 2){
                        fake++;
                    }
                    else if (cont==random)
                    {
                       char * mazo= (char * )malloc(sizeof(char)*40); 
                       strcpy(mazo,"mazo/");
                       strcat(mazo,ent->d_name);
                       remove(mazo);
                       free(mazo);
                       cartasmazo--;
                       printf("El jugador %d robó la carta %s\n",J,ent->d_name);
                       strcpy(nent,ent->d_name);
                       printf("%s\n",nent);
                       printf("%s\n",naux);
                       if (nent[4]=='c'||(nent[1]=='n'&& nent[4]=='4'))
                       {
                           while (1)
                           {
                               printf("Ha obtenido la carta %s\n",nent);
                               printf("Desea jugarla?\n1.- Si\n2.-No\nIngrese su opción:");
                               int op;
                               scanf("%d",&op);
                               printf("\n");
                                if (op==1)
                                {     
                                    while (1)
                                    {
                                      printf("Seleccione el color que desea:\n0.-Rojo\n1.-Verde\n2.-Azul\n3.-Amarillo\nIngrese su opcion:");
                                        int r;
                                        scanf("%d",&r);
                                        if(r == 0){
                                             char * play = (char * )malloc(sizeof(char)*40);
                                            strcpy(play,"juego/");
                                            strcat(play,"_roj_.txt");
                                            printf("La carta se ha jugado\n");
                                            char * borrar = (char * )malloc(sizeof(char)*40);
                                            strcpy(borrar,"juego/");
                                            strcat(borrar,naux);
                                            remove(borrar);
                                          
                                            FILE* file1 = fopen(play, "w");
                                            fclose(file1);
              
                                            printf("Y la jugó\n");
                                            char re = play[4];
                                            free(borrar);
                                            free(play);
                                            free(nent);
                                            free(naux);
                                            closedir(dir);
                                            if (nent[1]=='n'&& nent[4]=='4')
                                            {
                                                return 'n';
                                            }
                                            
                                            return re;   

                                            break;

                                        }
                                        else if(r == 1){
                                             char * play = (char * )malloc(sizeof(char)*40);
                                            strcpy(play,"juego/");
                                            strcat(play,"_ver_.txt");
                                            printf("La carta se ha jugado\n");
                                            char * borrar = (char * )malloc(sizeof(char)*40);
                                            strcpy(borrar,"juego/");
                                            strcat(borrar,naux);
                                            remove(borrar);
                                 
                                            FILE* file1 = fopen(play, "w");
                                            fclose(file1);
                                         
                                            printf("Y la jugó\n");
                                            char re = play[4];
                                            free(borrar);
                                            free(play);
                                            free(nent);
                                            free(naux);
                                            closedir(dir);
                                            if (nent[1]=='n'&& nent[4]=='4')
                                            {
                                                return 'n';
                                            }
                                            
                                            return re;   

                                            break;

                                        }
                                        else if(r == 2){
                                             char * play = (char * )malloc(sizeof(char)*40);
                                            strcpy(play,"juego/");
                                            strcat(play,"_zul_.txt");
                                            printf("La carta se ha jugado\n");
                                            char * borrar = (char * )malloc(sizeof(char)*40);
                                            strcpy(borrar,"juego/");
                                            strcat(borrar,naux);
                                            remove(borrar);
                                        
                                            FILE* file1 = fopen(play, "w");
                                            fclose(file1);
                                      
                                            printf("Y la jugó\n");
                                            char re = play[4];
                                            free(borrar);
                                            free(play);
                                            free(nent);
                                            free(naux);
                                            closedir(dir);
                                            if (nent[1]=='n'&& nent[4]=='4')
                                            {
                                                return 'n';
                                            }
                                            
                                            return re;   

                                            break;

                                        }
                                        else if (r==3)
                                        {
                                            char * play = (char * )malloc(sizeof(char)*40);
                                            strcpy(play,"juego/");
                                            strcat(play,"_ama_.txt");
                                            printf("La carta se ha jugado\n");
                                            char * borrar = (char * )malloc(sizeof(char)*40);
                                            strcpy(borrar,"juego/");
                                            strcat(borrar,naux);
                                            remove(borrar);
                                      
                                            FILE* file1 = fopen(play, "w");
                                            fclose(file1);
                                      
                                            printf("Y la jugó\n");
                                            char re = play[4];
                                            free(borrar);
                                            free(play);
                                            free(nent);
                                            free(naux);
                                            closedir(dir);
                                            if (nent[1]=='n'&& nent[4]=='4')
                                            {
                                                return 'n';
                                            }
                                            
                                            return re;   

                                           break;
                                        }
                                        else
                                        {
                                            printf("Opción invalida, ingrese de nuevo su color.\n");
                                        }
                                    }
                                    
                                          
                                        
                                  
                                }
                                else if(op==2){
                                        printf("Y la guardó en su mano\n");
                                        char * guardar = (char * )malloc(sizeof(char)*40);
                                        strcpy(guardar,"j4/");
                                        strcat(guardar,ent->d_name);
                                        FILE* file1 = fopen(guardar, "w");
                                        fclose(file1);
                                        free(guardar);
                                        closedir(dir);
                                        mano[3]++;

                                        return 'x';
                                        break;

                                }
                                else{
                                    printf("Opción invalida, ingrese nuevamente\n");
                                }
                           }
                           
                         
                          

                          
                           
                       }   
                       else if (nent[1]==naux[1]||nent[4]==naux[4])
                       {
                            while (1)
                            {
                                /* code */
                                printf("Ha obtenido la carta %s\n",nent);
                                printf("Desea jugarla?\n1.- Si\n2.-No\nIngrese su opción:");
                                int op;
                                scanf("%d",&op);
                                printf("\n");
                                if(op==1){
                                    char * borrar = (char * )malloc(sizeof(char)*40);
                                    strcpy(borrar,"juego/");
                                    strcat(borrar,naux);
                                    remove(borrar);
                             
                                    char * agregar= (char *)malloc(sizeof(char)*40);
                                    strcpy(agregar,"juego/");
                                    strcat(agregar,ent->d_name);
                                    FILE* file1 = fopen(agregar, "w");
                                    fclose(file1);
                            
                                    printf("Y la jugó\n");
                                    char re = agregar[4];
                                    free(borrar);
                                    free(agregar);
                                    free(nent);
                                    free(naux);
                                    closedir(dir);
                                    return re;

                                }
                                else if(op==2){
                                        printf("Y la guardó en su mano\n");
                                    char * guardar = (char * )malloc(sizeof(char)*40);
                                    strcpy(guardar,"j4/");
                                    strcat(guardar,ent->d_name);
                                    FILE* file1 = fopen(guardar, "w");
                                    fclose(file1);
                                    free(guardar);
                                    closedir(dir);
                                    mano[3]++;

                                    return 'x';
                                    break;

                                }
                                else{
                                    printf("Opción invalida, ingresela nuevamente\n");
                                }    
                            }
                       } 
                       else
                       {
                           printf("Y la guardó en su mano\n");
                           char * guardar = (char * )malloc(sizeof(char)*40);
                           strcpy(guardar,"j4/");
                           strcat(guardar,ent->d_name);
                           FILE* file1 = fopen(guardar, "w");
                           fclose(file1);
                           free(guardar);
                            closedir(dir);
                            mano[3]++;

                           return 'x';
                           break;
                       }
                       
                        
                    }
                    cont++;
                }
                
            }
            else
            {
                printf("Jugador ingresado no valido");
                closedir(dir);
                return 'z';
            
            }
            
            
        }
        
    }  
    return 'M';
}

char jugar(int jugador){
    DIR *dir;
    DIR *dir2;
    struct dirent *ent;
    struct dirent *ent2;
    char color, tipo, jugada = 'x';
    int fake = 0, done = 0, r, carta2,flag,flag2,flag3;
    char * carta = (char * )malloc(sizeof(char)*40);
    if ((dir = opendir ("juego")) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
             if (strcmp(ent->d_name,".") == 0 || strcmp(ent->d_name,"..") == 0 ){
                fake++;
            }
            else{
                strcpy(carta,ent->d_name);
                
            }
        }
    }
    color = carta[1];
    tipo = carta[4];
    printf("\nLa carta en el pozo es %s\n",carta);
    printf("Tus cartas son: \n");
    int cont = 0;
    char** cartasmano;
    cartasmano = (char**)malloc(sizeof(char*)*80);
    char * dirplayer = (char * )malloc(sizeof(char)*40);
    char * player = (char * )malloc(sizeof(char)*40);

    if(jugador == 1){
        strcpy(player,"j1");
    }
    else if(jugador == 2){
        strcpy(player,"j2");
    }
    else if(jugador == 3){
        strcpy(player,"j3");
    }
    else{
        strcpy(player,"j4");
    }
    done = 0;
    if ((dir2 = opendir(player)) != NULL) {
        while ((ent2 = readdir(dir2)) != NULL) {
            if (strcmp(ent2->d_name,".") == 0 || strcmp(ent2->d_name,"..") ==0 ){
                fake++;
            }
            else{
                cartasmano[cont] = (char*)malloc(sizeof(char)*40);
                strcpy(cartasmano[cont],ent2->d_name);
                if(cartasmano[cont][1] == 'n' || cartasmano[cont][1] == color || cartasmano[cont][4] == tipo){
                    done = 1;
                }
                cont++;
                printf("%d.-%s\n",cont,ent2->d_name);
            }
        }
    }
    cartasmano[cont] = (char*)malloc(sizeof(char)*40);
    strcpy(cartasmano[cont],"###");
    flag = 1;
    while(flag){
        flag2 = 1;
        if(!done){
            printf("No hay cartas validas para jugar\n");
            flag--;
        }
        else{
            while(flag2){
                printf("Ingrese el numero de la carta que desea jugar: ");
                scanf("%d", &carta2);
                printf("\n");
                if(carta2 <= cont && carta2 > 0){
                    flag2--;
                }
                else{
                    printf("Ingrese un numero valido\n");
                }   
            }

            carta2--;
            if(cartasmano[carta2][1] == 'n'){
                if(cartasmano[carta2][4]=='4'){
                    jugada = 'n';
                }
                else{
                    jugada = cartasmano[carta2][4];
                }
                flag3 = 1;
                while(flag3){    
                    printf("Escoja el numero del color:\n1.- Rojo\n2.- Verde\n3.- Azul\n4.- Amarillo\n");
                    scanf("%d",&r);
                    if(r <= 4 && r > 0){
                        flag3--;
                    }
                    else{
                        printf("Ingrese un numero valido");
                    }
                }
                r--;
                char * play = (char * )malloc(sizeof(char)*40);
                strcpy(play,"juego/");
                if(r == 0){
                    strcat(play,"_roj_.txt");

                }
                else if(r == 1){
                    strcat(play,"_ver_.txt");

                }
                else if(r == 2){
                    strcat(play,"_zul_.txt");

                }
                else{
                    strcat(play,"_ama_.txt");
                }
                FILE* archivo= fopen(play,"w");
                fclose(archivo);
                char * borrar = (char * )malloc(sizeof(char)*40);
                strcpy(dirplayer,player);
                strcat(dirplayer,"/");
                strcpy(borrar,dirplayer);
                strcat(borrar,cartasmano[carta2]);
                remove(borrar);
                free(play);
                free(borrar);
                mano[jugador-1]--;
                flag--;                                                                              
            }
            else if(cartasmano[carta2][1] == color || cartasmano[carta2][4] == tipo){
                jugada = cartasmano[carta2][4];
                char * play = (char * )malloc(sizeof(char)*40);
                strcpy(play,"juego/");
                strcat(play,cartasmano[carta2]);
                FILE* archivo= fopen(play,"w");
                fclose(archivo);
                char * borrar = (char * )malloc(sizeof(char)*40);
                strcpy(dirplayer,player);
                strcat(dirplayer,"/");
                strcpy(borrar,dirplayer);
                strcat(borrar,cartasmano[carta2]);
                remove(borrar);
                free(play);
                free(borrar);
                mano[jugador-1]--;
                flag--;
            }
            else{
                printf("Jugada invalida\n");
            }
        }
    }
    
    cont = 0;
    while(strcmp(cartasmano[cont],"###")){
        free(cartasmano[cont]);
        cont++;
    }
    free(cartasmano);
    
    if(done){
        char * borrar = (char * )malloc(sizeof(char)*40);
        strcpy(borrar,"juego/");
        strcat(borrar,carta);
        remove(borrar);
        free(borrar);
        free(player);
        free(dirplayer);
        free(carta);
        closedir(dir);
        closedir(dir2);
        return(jugada);
    }
    else{
        printf("Robas carta\n");
        free(player);
        free(dirplayer);
        free(carta);
        closedir(dir);
        closedir(dir2);
        return robar(jugador);
    }    
}

int main(int argc, char const *argv[])
{
    int tuberia12[2];
    int tuberia21[2];
    int tuberia23[2];
    int tuberia32[2];
    int tuberia34[2];
    int tuberia43[2];
    int tuberia41[2];
    int tuberia14[2];
    pipe(tuberia12);
    pipe(tuberia21);
    pipe(tuberia23);
    pipe(tuberia32);
    pipe(tuberia34);
    pipe(tuberia43);
    pipe(tuberia41);
    pipe(tuberia14);


    int idH1=-1;
    int idH2=-1;
    int idH3=-1;
    idH1=fork();
    if (idH1!=0)
    {
        idH2= fork();
        if (idH2!=0){
            idH3= fork();
            if(idH3==0){
                idH3 = getpid();
            }
        }
        else
        {
            idH2=getpid();
        }
        
    }
    else
    {
        idH1 = getpid();
    }
    
    int id = getpid();

    if(id==idH1){
        //Player 2
        close(tuberia21[0]);//0 = leer, 1= escribir
        close(tuberia12[1]);
        //------------------------------
        close(tuberia34[1]);
        close(tuberia43[1]);
        close(tuberia34[0]);
        close(tuberia43[0]);
        close(tuberia41[1]);
        close(tuberia14[1]);
        close(tuberia41[0]);
        close(tuberia14[0]);
        //------------------------------
        close(tuberia23[0]);
        close(tuberia32[1]);
    }
    else if (id==idH2){
        //Player 3
        close(tuberia34[0]);
        close(tuberia43[1]);
        //-----------------------
        close(tuberia41[1]);
        close(tuberia14[1]);
        close(tuberia41[0]);
        close(tuberia14[0]);
        close(tuberia12[0]);
        close(tuberia21[0]);
        close(tuberia12[1]);
        close(tuberia21[1]);
        //------------------------
        close(tuberia23[1]);
        close(tuberia32[0]);

    }
    else if (id==idH3){
        //Player 4
        close(tuberia41[0]);
        close(tuberia14[1]);
        
        //--------------------
        close(tuberia23[0]);
        close(tuberia32[0]);
        close(tuberia23[1]);
        close(tuberia32[1]);
        close(tuberia12[0]);
        close(tuberia21[0]);
        close(tuberia12[1]);
        close(tuberia21[1]);
        //--------------------
        close(tuberia34[1]);
        close(tuberia43[0]);
    }
    else{

        //Player 1
        close(tuberia21[1]);
        close(tuberia12[0]);
        //---------------------
        close(tuberia23[0]);
        close(tuberia32[0]);
        close(tuberia34[0]);
        close(tuberia43[0]);
        close(tuberia23[1]);
        close(tuberia32[1]);
        close(tuberia34[1]);
        close(tuberia43[1]);
        //--------------------
        close(tuberia14[0]);
        close(tuberia41[1]);


    }

int cont=1;
int reversa=0;
char jugada;
int r;
int flag3;
while (1)
{
    while(id==idH1){

        //Player 2
        char mensaje1 [11];
        while(read(tuberia12[0],mensaje1,12)<0 && read(tuberia32[0],mensaje1,12)<0);
        int i;
        int aux;
        for (size_t i = 0; i < 4; i++)
        {
            //Or more readable: 'int x = character - '0'
            aux = mensaje1[i]-'0';
         
            mano[i]=aux;
        }
        if(mensaje1[5]=='0'){
            //sscanf(mensaje1[6],"%d",&cartasmazo);
            cartasmazo= mensaje1[6] -'0';
        }
        else
        {
            char maux[2];
            maux[0]=mensaje1[5];
            maux[1]=mensaje1[6];
            sscanf(maux,"%d",&cartasmazo);
        }

        reversa=mensaje1[10] - '0';
        if (mensaje1[8]=='b')
        {
            printf("EL JUGADOR 2 HA SIDO BLOQUEADO\n");
            jugada = 'x';
        }
        else if (mensaje1[8]=='n')
        {
            printf("EL JUGADOR 2 ROBA 4 CARTAS\n");
            robarN(2,4);
            jugada = 'x';
        }
        else if (mensaje1[8]=='p')
        {
            printf("EL JUGADOR 1 ROBA 2 CARTAS\n");
            robarN(2,2);
            jugada = 'x';
        }
        else
        {
            jugada = jugar(2);
        }
    

        char mensaje[11];
    

        for ( i = 0; i < 4; i++)
        {
            sprintf(mensaje,"%d",mano[i]);
        }
        strcat(mensaje, "_");
        if (cartasmazo < 10)
        {
            sprintf(mensaje,"%d",0);
            sprintf(mensaje,"%d",cartasmazo);
        }
        else sprintf(mensaje,"%d",cartasmazo);

        strcat(mensaje, "_");
        char caux[2];caux[0]=jugada;caux[1]='\0';
        
        strcat(mensaje, caux);
        strcat(mensaje, "_");
        sprintf(mensaje,"%d",reversa);
        
    
        if(reversa==0){                    
            write(tuberia23[1], mensaje, (strlen(mensaje)+1));

        }
        else{       
            write(tuberia21[1], mensaje, (strlen(mensaje)+1));
        }
       
    }

    while (id==idH2)
    {
        //Player 3
        char mensaje1 [11];
        while(read(tuberia43[0],mensaje1,12)<0 && read(tuberia23[0],mensaje1,12)<0);
        int i;
        int aux;
        for (size_t i = 0; i < 4; i++)
        {
            //Or more readable: 'int x = character - '0'
            aux = mensaje1[i]-'0';
         
            mano[i]=aux;
        }
        if(mensaje1[5]=='0'){
            //sscanf(mensaje1[6],"%d",&cartasmazo);
            cartasmazo= mensaje1[6] -'0';
        }
        else
        {
            char maux[2];
            maux[0]=mensaje1[5];
            maux[1]=mensaje1[6];
            sscanf(maux,"%d",&cartasmazo);
        }

        reversa=mensaje1[10] - '0';
        if (mensaje1[8]=='b')
        {
            printf("EL JUGADOR 2 HA SIDO BLOQUEADO\n");
            jugada = 'x';
        }
        else if (mensaje1[8]=='n')
        {
            printf("EL JUGADOR 2 ROBA 4 CARTAS\n");
            robarN(3,4);
            jugada = 'x';
        }
        else if (mensaje1[8]=='p')
        {
            printf("EL JUGADOR 1 ROBA 2 CARTAS\n");
            robarN(3,2);
            jugada = 'x';
        }
        else
        {
            jugada = jugar(3);
        }
    

        char mensaje[11];

        for ( i = 0; i < 4; i++)
        {
            sprintf(mensaje,"%d",mano[i]);
        }
        strcat(mensaje, "_");
        if (cartasmazo < 10)
        {
            sprintf(mensaje,"%d",0);
            sprintf(mensaje,"%d",cartasmazo);
        }
        else sprintf(mensaje,"%d",cartasmazo);

        strcat(mensaje, "_");
        char caux[2];caux[0]=jugada;caux[1]='\0';
        
        strcat(mensaje, caux);
        strcat(mensaje, "_");
        sprintf(mensaje,"%d",reversa);
        if(reversa==0){                    
            write(tuberia34[1], mensaje, (strlen(mensaje)+1));

        }
        else{       
            write(tuberia32[1], mensaje, (strlen(mensaje)+1));
        }
       
       
    }
    while (id==idH3)
    {
        //Player 4
        printf("TURNO DEL JUGADOR 4");
       char mensaje1 [11];
        while(read(tuberia34[0],mensaje1,12)<0 && read(tuberia14[0],mensaje1,12)<0);
       int i;
        int aux;
        for (size_t i = 0; i < 4; i++)
        {
            //Or more readable: 'int x = character - '0'
            aux = mensaje1[i]-'0';
         
            mano[i]=aux;
        }
        if(mensaje1[5]=='0'){
            //sscanf(mensaje1[6],"%d",&cartasmazo);
            cartasmazo= mensaje1[6] -'0';
        }
        else
        {
            char maux[2];
            maux[0]=mensaje1[5];
            maux[1]=mensaje1[6];
            sscanf(maux,"%d",&cartasmazo);
        }

        reversa=mensaje1[10] - '0';
        if (mensaje1[8]=='b')
        {
            printf("EL JUGADOR 2 HA SIDO BLOQUEADO\n");
            jugada = 'x';
        }
        else if (mensaje1[8]=='n')
        {
            printf("EL JUGADOR 2 ROBA 4 CARTAS\n");
            robarN(4,4);
            jugada = 'x';
        }
        else if (mensaje1[8]=='p')
        {
            printf("EL JUGADOR 1 ROBA 2 CARTAS\n");
            robarN(4,2);
            jugada = 'x';
        }
        else
        {
            jugada = jugar(4);
        }
    

        char mensaje[11];

        for ( i = 0; i < 4; i++)
        {
            sprintf(mensaje,"%d",mano[i]);
        }
        strcat(mensaje, "_");
        if (cartasmazo < 10)
        {
            sprintf(mensaje,"%d",0);
            sprintf(mensaje,"%d",cartasmazo);
        }
        else sprintf(mensaje,"%d",cartasmazo);

        strcat(mensaje, "_");
        char caux[2];caux[0]=jugada;caux[1]='\0';
        
        strcat(mensaje, caux);
        strcat(mensaje, "_");
        sprintf(mensaje,"%d",reversa);
    
        if(reversa==0){                    
            write(tuberia41[1], mensaje, (strlen(mensaje)+1));

        }
        else{       
            write(tuberia43[1], mensaje, (strlen(mensaje)+1));
        }
       
    }
    while (1)
    {
        printf("TURNO DE JUGADOR 1");
        if(cont==1){
            cont++;
            char c = leerPozo();
            if (c=='z')
            {
                robarN(1,4);
                jugada = 'x';
                flag3 = 1;
                printf("\n En el pozo hay un +4\n");
                while(flag3){    
                    printf("Escoja el numero del color:\n1.- Rojo\n2.- Verde\n3.- Azul\n4.- Amarillo\n");
                    scanf("%d",&r);
                    if(r <= 4 && r > 0){
                        flag3--;
                    }
                    else{
                        printf("Ingrese un numero valido");
                    }
                }
                char * play = (char * )malloc(sizeof(char)*40);
                strcpy(play,"juego/");
                if(r == 0){
                    strcat(play,"_roj_.txt");

                }
                else if(r == 1){
                    strcat(play,"_ver_.txt");

                }
                else if(r == 2){
                    strcat(play,"_zul_.txt");

                }
                else{
                    strcat(play,"_ama_.txt");
                }
                FILE* archivo= fopen(play,"w");
                fclose(archivo);
                free(play);
            }
            else if (c=='p')
            {
                robarN(1,2);
                jugada = 'x';
            }
            else if (c=='b')
            {
                jugada = 'x';
            }
            else if (c=='r')
            {
                reversa = 1;
                jugada = jugar(1);
            }
            else if (c=='c')
            {
                int flag3 = 1;
                printf("\n En el pozo hay un cambiocolor\n");
                while(flag3){    
                    printf("Escoja el numero del color:\n1.- Rojo\n2.- Verde\n3.- Azul\n4.- Amarillo\n");
                    scanf("%d",&r);
                    if(r <= 4 && r > 0){
                        flag3--;
                    }
                    else{
                        printf("Ingrese un numero valido");
                    }
                }
                char * play = (char * )malloc(sizeof(char)*40);
                strcpy(play,"juego/");
                if(r == 0){
                    strcat(play,"_roj_.txt");

                }
                else if(r == 1){
                    strcat(play,"_ver_.txt");

                }
                else if(r == 2){
                    strcat(play,"_zul_.txt");

                }
                else{
                    strcat(play,"_ama_.txt");
                }
                FILE* archivo= fopen(play,"w");
                fclose(archivo);
                free(play);
                jugada=jugar(1);
                
            }
                  
            else
            {
                jugada = jugar(1);
            }


            
        }
        else{
            char mensaje1 [11];
            while(read(tuberia21[0],mensaje1,12)<0 && read(tuberia41[0],mensaje1,12)<0);
            int i;
            int aux;
            for ( i = 0; i < 4; i++)
            {
                //Or more readable: 'int x = character - '0'
                aux = mensaje1[i]-'0';
            
                mano[i]=aux;
            }
            if(mensaje1[5]=='0'){
                //sscanf(mensaje1[6],"%d",&cartasmazo);
                cartasmazo= mensaje1[6] -'0';
            }
            else
            {
                char maux[2];
                maux[0]=mensaje1[5];
                maux[1]=mensaje1[6];
                sscanf(maux,"%d",&cartasmazo);
            }

            reversa=mensaje1[10] - '0';
            if (mensaje1[8]=='b')
            {
                printf("EL JUGADOR 2 HA SIDO BLOQUEADO\n");
                jugada = 'x';
            }
            else if (mensaje1[8]=='n')
            {
                printf("EL JUGADOR 2 ROBA 4 CARTAS\n");
                robarN(1,4);
                jugada = 'x';
            }
            else if (mensaje1[8]=='p')
            {
                printf("EL JUGADOR 1 ROBA 2 CARTAS\n");
                robarN(1,2);
                jugada = 'x';
            }
            else
            {
                jugada = jugar(1);
            }
    
        }

        char mensaje[11];
    
        int i;
        for ( i = 0; i < 4; i++)
        {
            sprintf(mensaje,"%d",mano[i]);
        }
        strcat(mensaje, "_");
        if (cartasmazo < 10)
        {
            sprintf(mensaje,"%d",0);
            sprintf(mensaje,"%d",cartasmazo);
        }
        else sprintf(mensaje,"%d",cartasmazo);

        strcat(mensaje, "_");
        char caux[2];caux[0]=jugada;caux[1]='\0';
        
        strcat(mensaje, caux);
        strcat(mensaje, "_");
        sprintf(mensaje,"%d",reversa);
    
        
    
        if(reversa==0){                    
            write(tuberia12[1], mensaje, (strlen(mensaje)+1));

        }
        else{       
            write(tuberia14[1], mensaje, (strlen(mensaje)+1));
        }
       
        
    }
}





    return 0;
}


















/*
int main()
{
    crearArchivos();






    int i = 0, flag = 1;
    while(flag){
        printf("\nTurno del jugador %d", i%4+1);
        jugar(i%4 + 1);
        if(mano[i%4] == 0){
            flag = 0;
        }
        else if(mano[i%4] == 1){
            printf("Al jugador %d le queda 1 carta!!!", i%4+1);
        }
        i++;
    }
    printf("El jugador %d ganó!!!!!\n",i%4);
    return 0;
}*/
