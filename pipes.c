    
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <time.h>
int cartasmazo=79;
int mano[4] = {7,7,7,7};
char jugar(int a){
    return 'x';
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


/*
    close(tuberia12[0]);
    close(tuberia21[0]);
    close(tuberia23[0]);
    close(tuberia32[0]);
    close(tuberia34[0]);
    close(tuberia43[0]);
    close(tuberia41[0]);
    close(tuberia14[0]);

    close(tuberia12[1]);
    close(tuberia21[1]);
    close(tuberia23[1]);
    close(tuberia32[1]);
    close(tuberia34[1]);
    close(tuberia43[1]);
    close(tuberia41[1]);
    close(tuberia14[1]);







/*
    int idH1 = fork();
    /*if (idH1 == 0)
    {
        /*Jugador 2
      /*  close(tuberia21[0]);//0 = leer, 1= escribir
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


        write(tuberia12[1],"hola papa",9);
    }
    else
    {
        Jugador 1
        close(tuberia21[1]);
        close(tuberia12[0]);
        //---------------------
        close(tuberia23[0]);
        close(tuberia32[0]);
        close(tuberia34[0]);
        close(tuberia43[0]);
        //--------------------
        close(tuberia14[0]);
        close(tuberia41[1]);

        int idH2 = fork();

        if(idH2!=0){
            int idH3 =fork();
        }
    

        char mensaje[10];
        
        printf("Hola soy  el padre");
        printf("%s",mensaje);
    }
    */


    return 0;
}

