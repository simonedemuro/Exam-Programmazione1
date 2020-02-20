//
// Created by Alessandro Tola on 20/12/2019.
// (refactored to fit the project's need)
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
void printPoiArray(dynamicArray d);
void printElement(PointOfInterest e);
void addItem(dynamicArray *vettore, PointOfInterest e);
void removeLast(dynamicArray *vettore);
void deletePoiAt(dynamicArray *vettore, int indice);
void printPoiCategoryAsString(int category);

#endif //UNTITLED33_VETTOREDINAMICO_H
