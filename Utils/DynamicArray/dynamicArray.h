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
#include "../../Model/structures.h"

typedef struct{
    PointOfInterest *v;
    int nElementi;
} dynamicArray;

/** Prototipi subroutine **/
void initDynamicVector(dynamicArray *v);
void stampaElementi(dynamicArray d);
void stampaElemento(PointOfInterest e);
int dimensioneVettore(dynamicArray *vettore);
void aggiungiElemento(dynamicArray *vettore, PointOfInterest e);
void settaElemento(dynamicArray *vettore, int posizione, PointOfInterest e);
PointOfInterest recuperaElemento(dynamicArray *vettore, int posizione);
_Bool vettoreVuoto(dynamicArray *vettore);
void rimuoviElementoInCoda(dynamicArray *vettore);
void rimuoviInPosizione(dynamicArray *vettore, int indice);
void impostaVettore(dynamicArray *vettore, PointOfInterest value);
_Bool confrontaElemento(PointOfInterest e1, PointOfInterest e2);
int ricercaElemento(dynamicArray *vettore, PointOfInterest e);
int contaElemento(dynamicArray *vettore, PointOfInterest e);
void cercaElemento(dynamicArray *vettore, char *s);
void printPoiCategoryAsString(int category);

/* on disk operations */
void salvaSuFileBinario(dynamicArray *vettore, FILE *fp);
void leggiDaFileBinario(dynamicArray *vettore, FILE *fp);
FILE * openFile(char *nomeFile, char *mode);
FILE * chiudiFile(FILE * fp);

#endif //UNTITLED33_VETTOREDINAMICO_H
