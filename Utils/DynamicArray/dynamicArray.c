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
 * Restituisce la dimensione dell'array
 * @param vettore Puntatore al vettore
 * @return Attuale dimensione del vettore dinamico
 */
int dimensioneVettore(dynamicArray *vettore){
    return vettore->nElementi;
}

/**
 * Aggiunge un elemento in coda al vettore
 * @param vettore Puntatore al vettore
 * @param e Valore da inserire
 */
void aggiungiElemento(dynamicArray *vettore, PointOfInterest e){
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
 * Setta il valore di una posizione di un vettore. Il controllo degli indici è lasciato al programmatore
 * @param vettore Puntatore al vettore
 * @param posizione Posizione in cui settare il valore
 * @param e Valore
 */
void settaElemento(dynamicArray *vettore, int posizione, PointOfInterest e){
    vettore->v[posizione] = e;
}

/**
 * Permette di ottenere un valore del vettore in una determinata posizione. Il controllo degli indici è lasciato al programmatore
 * @param vettore Puntatore al vettore
 * @param posizione Posizione del valore
 * @return Elemento
 */
PointOfInterest recuperaElemento(dynamicArray *vettore, int posizione){
    return vettore->v[posizione];
}

/**
 * Controlla se il vettore è vuoto
 * @param vettore Puntatore al vettore
 * @return True se il vettore è vuoto, false altrimenti
 */

_Bool vettoreVuoto(dynamicArray *vettore){
    if(dimensioneVettore(vettore) == 0)
        return true;

    return false;
}

/**
 * Rimuove l'elemento in coda del vettore
 * @param vettore Puntatore al vettore
 */
void rimuoviElementoInCoda(dynamicArray *vettore){
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
void rimuoviInPosizione(dynamicArray *vettore, int indice){
    int i;
    for(i=indice; i<(vettore->nElementi-1); i++){
        vettore->v[i] = vettore->v[i+1];
    }
    rimuoviElementoInCoda(vettore);
}

/**
 * Inizializza un vettore con un numero specificato di elementi.
 * @param vettore Puntatore a vettore
 * @param numeroElementi Numero di elementi del vettore
 */
void inizializzaIndefiniti(dynamicArray *vettore, int numeroElementi) {
    vettore->v = (PointOfInterest*) malloc(sizeof(PointOfInterest) * numeroElementi);

    if (vettore->v == NULL) {
        exit(-1);
    }

    vettore->nElementi = numeroElementi;
}

/**
 * Impostato l'intero vettore ad un valove scelto
 * @param vettore puntatore al vettore
 * @param value valore da settare nel vettore
 */
void impostaVettore(dynamicArray *vettore, PointOfInterest value){
    int i;
    for(i = 0; i < dimensioneVettore(vettore); i++)
        settaElemento(vettore, i, value);
}

/**
 * Esegue un confronto campo per campo di due elementi, restituisce true se sono uguali
 * @param e1 elemento 1
 * @param e2 elemento 2
 * @return true se sono uguali, false altrimenti
 */
_Bool confrontaPointOfInterests(PointOfInterest e1, PointOfInterest e2){
    if(true)
        return true;
    return false;
}

/**
 * Ricerca di un elemento all'interno del vettore
 * @param vettore vettore dinamico
 * @param e elemento da cercare
 * @return restituisce -1 se l'elemento non è presento o l'indice dell'elemento trovato
 */
int ricercaElemento(dynamicArray *vettore, PointOfInterest e){

    int i, indiceTrovato = -1;

    for(i = 0; i < dimensioneVettore(vettore); i++){
        if(confrontaElemento(recuperaElemento(vettore, i), e))
            indiceTrovato=i;
    }

    return indiceTrovato;
}
_Bool confrontaElemento(PointOfInterest e1, PointOfInterest e2){
    // Todo: Fare qualcosa
    return false;
}
/**
 * Conta il numero di occorrenze di un detterminato elemento all'interno del vettore
 * @param vettore puntatore al vettore
 * @param e elemento da cercare
 * @return numero di occorrenze dell'elemento
 */
int contaElemento(dynamicArray *vettore, PointOfInterest e){

    int i, contatore = 0;

    for(i = 0; i < dimensioneVettore(vettore); i++){
        if(confrontaElemento(recuperaElemento(vettore, i), e))
            contatore++;
    }

    return contatore;
}

/**
 * Cerca e stampa gli elementi che contento nel nome o cognome la stringa s
 * @param vettore vettore dinamico
 * @param s stringa da cercare
 */
void cercaElemento(dynamicArray *vettore, char *s){

    int i;
    PointOfInterest aux;
    for(i = 0; i < dimensioneVettore(vettore); i++){
        aux = recuperaElemento(vettore, i);
        if(strstr(aux.name, s) != NULL || strstr(aux.description, s) != NULL)
            printElement(aux);
    }

}