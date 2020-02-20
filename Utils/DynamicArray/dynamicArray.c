//
// Created by Alessandro Tola on 20/12/2019.
// (refactored to fit the project need)
//

#include "dynamicArray.h"
#include "../UI/userInterfaceUtils.h"

/**
 * Inizializza un vettore vuoto. Il vettore non deve avere elementi
 * @param v Puntatore al vettore
 */
void initDynamicVector(dynamicArray *v){
    v->v = NULL;
    v->nElementi = 0;
}

/**
 * Prints all the elements inside of a Dynamic vector of POIs
 * @param d
 */
void printPoiArray(dynamicArray d){
    // clears console from previous outputs
    cleanConsole();

    // in case the array is empty prints a message
    if(d.nElementi == 0){
        printf(STR_NO_DATA_AVAILABLE);
    }

    // going trough dynamicArray printing everything
    int i = 0;
    for (i = 0; i < d.nElementi; ++i) {
        printf("INDEX: %d", i);
        printElement(d.v[i]);
        printf("\n");
    }
    // prints a new line in order to make the next menu easier to read
    printf("\n");
}

/**
 * This function prints an element
 * the white spaces before the names are for formatting purposes
 * @param e element to be printed
 */
void printElement(PointOfInterest e){
    printf("  Name: %s\n", e.name);
    printf("  Latitude: %f\n", e.latitude);
    printf("  Longitude: %f\n", e.longitude);
    printf("  altitude\': %f\n", e.altitude);
    printf("  Municipality: %s\n", e.municipality);
    printf("  Description: %s\n  ", e.description);
    // the category needs to be treated apart
    printf("Category: ");
    printPoiCategoryAsString(e.category);
    printf("\n");
}

/**
 * gets an integer and prints the corresponding category
 * @param category
 */
void printPoiCategoryAsString(int category){
    switch (category){
        case beach:
            printf("beach");
            break;
        case Mountain:
            printf("Mountain");
            break;
        case Park:
            printf("Park");
            break;
        case Lake:
            printf("Lake");
            break;
        case Cave:
            printf("Cave");
            break;
        case Museum:
            printf("Museum");
            break;
        case ViewPoint:
            printf("ViewPoint");
            break;
        case Other:
            printf("Other");
            break;
        default:
            printf("error");
            break;
    }
}

/**
 * Enqueues a point of interest to the array
 * @param vettore vector pointer
 * @param e item to be inserted
 */
void addItem(dynamicArray *vettore, PointOfInterest e){
    vettore->nElementi++;

    if(vettore->v == NULL)
        vettore->v = (PointOfInterest *) malloc(vettore->nElementi * sizeof(PointOfInterest));
    else
        vettore->v = (PointOfInterest *) realloc(vettore->v,vettore->nElementi * sizeof(PointOfInterest));

    if(vettore->v == NULL)
        exit(-1);

    vettore->v[vettore->nElementi-1] = e;
}

/**
 * Removes last item
 * @param array pointer
 */
void removeLast(dynamicArray *vettore){
    if(vettore->v != NULL) {
        vettore->nElementi--;
        vettore->v = (PointOfInterest *) realloc(vettore->v, vettore->nElementi * sizeof(PointOfInterest));
    }
}

/**
 * Rimuove l'elemento in una posizione indice del vettore
 * @param vettore Puntatore al vettore
 * @param indice indice dell'elemento da rimuovere
 */
void deletePoiAt(dynamicArray *vettore, int indice){
    int i;
    for(i=indice; i<(vettore->nElementi-1); i++){
        vettore->v[i] = vettore->v[i+1];
    }
    removeLast(vettore);
}