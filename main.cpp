//
//  main.cpp
//  Les9
//
//  Created by Florent Boutin on 17/11/12.
//  Copyright (c) 2012 Florent Boutin. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <cstring>

#define NB_VAL 9

using namespace std;

typedef struct nombre {
    int nb;
    struct nombre* suiv;
} NOMBRE;

void ajouter(int N, NOMBRE** tete) {
    NOMBRE* nouv=(NOMBRE*)malloc(sizeof(NOMBRE));
    nouv->nb=N;
    
    if(*tete==NULL) {
        *tete=nouv;
        (*tete)->suiv=NULL;
    }
    else {
        nouv->suiv=*tete;
        *tete=nouv;
    }
    
    //cout << *tete << endl;
    
}

NOMBRE* trouver(int N, NOMBRE* tete) {
    NOMBRE* tmp=(NOMBRE*)malloc(sizeof(NOMBRE));
    tmp=tete;
    while (tmp != NULL) {
        if(tmp->nb == N) {
            return tmp;
        }
        else
            tmp = tmp->suiv;
    }
    return NULL;
}

void supprimer(int N, NOMBRE** tete) {
    NOMBRE* tmp=(NOMBRE*)malloc(sizeof(NOMBRE));
    NOMBRE* prec=(NOMBRE*)malloc(sizeof(NOMBRE));
    if(*tete==NULL) {
        cout << "la non pus \n";
        return;
    }
    if((*tete)->nb == N) {
        *tete=(*tete)->suiv;
    }
    else {
        tmp=(*tete)->suiv;
        prec=*tete;
        while(tmp != NULL) {
            if(tmp->nb == N) {
                prec->suiv=tmp->suiv;
                return;
            }
            prec=tmp;
            tmp=tmp->suiv;
        }
    }
}

void afficher(int N, NOMBRE* tete) {
    NOMBRE* tmp=(NOMBRE*)malloc(sizeof(NOMBRE));
    tmp=trouver(N, tete);
    if(tmp!=NULL)
        cout << "Ce nombre est :" << tmp->nb << "\n";
    else
        cout<<"existe pas\n";
}


void display(int array[], NOMBRE** tete)
{
    int i; int num(0);
    for ( i = 0; i < NB_VAL; ++i ) {
        num += array[i]*pow(10, NB_VAL-1-i);
    }
    cout << num << endl;
    ajouter(num, tete);
    
}

void permutation( int array[], int num, int index , NOMBRE** tete)
{
    int i;
    array[++index] = ++num;
    if ( num == NB_VAL ) display(array, tete);
    for ( i = 0; i < NB_VAL; ++i )
        if ( !array[i] )
            permutation(array, num,  i-1 , tete);
    array[index] = 0;
    --num;
}

int facto(int x) {
    if(x==1) {
        return 1;
    }
    else {
        return x*facto(x-1);
    }
}


// DEBUT DU MAIN
int main(int argc, const char * argv[])
{
    NOMBRE* tete;
    tete = NULL;
    
    int array[NB_VAL] = { 0 };
    int num = 0;
    
    for ( int i = -1; i < NB_VAL-1; ++i )
        permutation( array, num, i , &tete);
    
    cout << "c'est ok : " << facto(NB_VAL) <<endl;
    
    NOMBRE *tmp = tete;
    while (tmp != NULL) {
        int nb = tmp->nb;
        int N = nb;
        for(int i=9; i>0; i--) {
            if(nb%i != 0){
                supprimer(N, &tete);
                cout << N << " -> " << nb << " : " << i << endl;
                break;
            }
            nb/=10;
        }
        tmp = tmp->suiv;
    }
    
    tmp = tete;
    while(tmp != NULL) {
        cout << tmp->nb << endl;
        tmp = tmp->suiv;
    }
    
    return 0;
}
