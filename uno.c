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

        printf("LA CARTA EN JUEGO ES: %s\n",aux->d_name);
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
                           printf("Y la guardó en su mano\n");
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

    int r = rand() % 81;
    cont = 0;
    fake = 0;
    if ((dir = opendir ("mazo")) != NULL) {
        while ((ent = readdir (dir)) != NULL) {
            if (fake < 2)
            {
                fake++;
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

    return 0;
}
