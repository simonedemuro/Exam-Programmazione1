//
// Created by Alessandro Tola on 20/12/2019.
// (refactored to fit the project need)
//

#ifndef UNTITLED33_VETTOREDINAMICO_H
#define UNTITLED33_VETTOREDINAMICO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/** Definizione macro **/
#define DIM_NOME 20
#define DIM_COGNOME 20

/** Definizione strutture **/
typedef struct{
    char nome[DIM_NOME+1];
    char cognome[DIM_COGNOME+1];
    int eta;
} Elemento;

typedef struct{
    Elemento *v;
    int nElementi;
} dynamicArray;

/** Prototipi subroutine **/
void initDynamicVector(dynamicArray *v);
void stampaElemento(Elemento e);
int dimensioneVettore(dynamicArray *vettore);
void aggiungiElemento(dynamicArray *vettore, Elemento e);
void settaElemento(dynamicArray *vettore, int posizione, Elemento e);
Elemento recuperaElemento(dynamicArray *vettore, int posizione);
_Bool vettoreVuoto(dynamicArray *vettore);
void rimuoviElementoInCoda(dynamicArray *vettore);
void rimuoviInPosizione(dynamicArray *vettore, int indice);
void impostaVettore(dynamicArray *vettore, Elemento value);
_Bool confrontaElemento(Elemento e1, Elemento e2);
int ricercaElemento(dynamicArray *vettore, Elemento e);
int contaElemento(dynamicArray *vettore, Elemento e);
void cercaElemento(dynamicArray *vettore, char *s);

void salvaSuFileBinario(dynamicArray *vettore, FILE *fp);
void leggiDaFileBinario(dynamicArray *vettore, FILE *fp);
FILE * openFile(char *nomeFile, char *mode);
FILE * chiudiFile(FILE * fp);

#endif //UNTITLED33_VETTOREDINAMICO_H
