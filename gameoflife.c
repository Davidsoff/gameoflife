/*
 ============================================================================
 Name        : game.c
 Author      : David
 Version     :
 Copyright   : Dit is van mij
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Wereld.h"
#include <time.h>

FILE *fp;

int** createArray(int x, int y);

int checkBuren(Schepping w, int x, int y);


int main ( )
{
  Schepping Genesis, Wereld;
  int leeftijd;
  init ( &Wereld, &Genesis );
  for ( leeftijd=1; leeftijd<=MaxLeeftijd; leeftijd++ ){
    toon ( Wereld, leeftijd );
    sleep(1);

    jarig ( Wereld );
     //if ( stop ( ) ) break;
 }
  dood ( Genesis );
  dood ( Wereld );
 return 0;
}

void init(Schepping *w, Schepping *g){

    fp = fopen("/home/user/workspace/game of life/settings.ini", "r");
    printf("\n leeftijd: %d\n",l);

    for(j=0;j<w.maxKol;j++){

        printf("--");

    }
    printf("\n");
    for(i=0;i<w.maxRij;i++){
        for(j=0;j<w.maxKol;j++){
            if(w.Populatie[i][j]){
                printf("X ");
            }
            else{
                printf("- ");

            }
        }
        printf("\n");
    }
    for(j=0;j<w.maxKol;j++){
        printf("--");
    }
    printf("\n");

}

void jarig(Schepping w){
    int **nieuw=w.Populatie;

    Schepping temp;
    temp.maxKol=w.maxKol;
    temp.maxRij=w.maxRij;
    temp.Populatie=createArray(w.maxRij,w.maxKol);
    for(int i=0; i<w.maxKol;i++){
        for(int j=0;j<w.maxRij;j++){
            temp.Populatie[j][i]=w.Populatie[j][i];

        }
    }

    int i,j;


    for(i=0;i<w.maxRij;i++){
        for(j=0;j<w.maxKol;j++){
            nieuw[i][j]=checkBuren(temp,i,j);
        }
    }

    //w.Populatie=nieuw;


}


int checkBuren(Schepping w, int i, int j){
    int count=0,self,buur,x,y;
    self=w.Populatie[i][j];

    for(y=(i-1);y<=(i+1);y++){
        for(x=(j-1);x<=(j+1);x++){
            if(x!=j||y!=i){
                if(x>=0&&x<w.maxKol&&y>=0&&y<w.maxRij){

                    buur=w.Populatie[y][x];

                    if(buur){
                        count++;
                    }
                }
            }
        }
    }

    if(count<2){
        return 0;
    }
    if(count==3){
        return 1;
    }
    if(count>3){
        return 0;
    }
    return self;
}

void dood(Schepping w){
    free(w.Populatie);
}

int stop(){
    return 0;
}

int** createArray(int kol, int rij){
    int i, **A;

    A= (int**) malloc(rij* sizeof(int*));

    for(i=0;i<rij;i++){

        A[i]=(int*) malloc(kol * sizeof(int));
    }

    return A;

