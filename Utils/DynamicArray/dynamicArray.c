//
// Created by Alessandro Tola on 20/12/2019.
//

#include "dynamicArray.h"

/**
 * Inizializza un vettore vuoto. Il vettore non deve avere elementi
 * @param v Puntatore al vettore
 */
void initDynamicVector(dynamicArray *v){
    v->v = NULL;
    v->nElementi = 0;
}

/**
 * Funzione per la stampa di un elemento
 * @param e elemento da stampare
 */
void stampaElemento(Elemento e){
    char stringa[256]="";
    printf("Nome: %s\n", e.nome);
    printf("Cognome: %s\n", e.cognome);
    printf("Eta\': %d\n", e.eta);

    printf(stringa, "Nome: %s Cognome: %s Eta\': %d", e.nome, e.cognome, e.eta);
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
void aggiungiElemento(dynamicArray *vettore, Elemento e){
    vettore->nElementi++;

    if(vettore->v == NULL)
        vettore->v = (Elemento *) malloc(vettore->nElementi * sizeof(Elemento));
    else
        vettore->v = (Elemento *) realloc(vettore->v,vettore->nElementi * sizeof(Elemento));

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
void settaElemento(dynamicArray *vettore, int posizione, Elemento e){
    vettore->v[posizione] = e;
}

/**
 * Permette di ottenere un valore del vettore in una determinata posizione. Il controllo degli indici è lasciato al programmatore
 * @param vettore Puntatore al vettore
 * @param posizione Posizione del valore
 * @return Elemento
 */
Elemento recuperaElemento(dynamicArray *vettore, int posizione){
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
        vettore->v = (Elemento *) realloc(vettore->v, vettore->nElementi * sizeof(Elemento));
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
    vettore->v = (Elemento*) malloc(sizeof(Elemento) * numeroElementi);

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
void impostaVettore(dynamicArray *vettore, Elemento value){
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
_Bool confrontaElemento(Elemento e1, Elemento e2){

    if(strcmp(e1.nome, e2.nome) == 0)
        if(strcmp(e1.cognome, e2.cognome) == 0)
            if(e1.eta == e2.eta)
                return true;

    return false;
}

/**
 * Ricerca di un elemento all'interno del vettore
 * @param vettore vettore dinamico
 * @param e elemento da cercare
 * @return restituisce -1 se l'elemento non è presento o l'indice dell'elemento trovato
 */
int ricercaElemento(dynamicArray *vettore, Elemento e){

    int i, indiceTrovato = -1;

    for(i = 0; i < dimensioneVettore(vettore); i++){
        if(confrontaElemento(recuperaElemento(vettore, i), e))
            indiceTrovato=i;
    }

    return indiceTrovato;
}

/**
 * Conta il numero di occorrenze di un detterminato elemento all'interno del vettore
 * @param vettore puntatore al vettore
 * @param e elemento da cercare
 * @return numero di occorrenze dell'elemento
 */
int contaElemento(dynamicArray *vettore, Elemento e){

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
    Elemento aux;
    for(i = 0; i < dimensioneVettore(vettore); i++){
        aux = recuperaElemento(vettore, i);
        if(strstr(aux.nome, s) != NULL || strstr(aux.cognome, s) != NULL)
            stampaElemento(aux);
    }

}

/**
 * Leggo i dati di un vettore dinami e creo un file binario con i dati letti
 * @param vettore vettore dinamico
 * @param fp puntatore al file binario
 */
void salvaSuFileBinario(dynamicArray *vettore, FILE *fp){
    int nElementi = vettore->nElementi;
    fwrite(&nElementi, sizeof(int), 1, fp);
    fwrite(vettore->v, sizeof(Elemento), nElementi, fp);
}

/**
 * Leggo i dati di un file binario e creo un vettore dinamico con i dati del file
 * @param vettore vettore da popolare
 * @param fp puntatore al file binario
 */
void leggiDaFileBinario(dynamicArray *vettore, FILE *fp){
    fread(&vettore->nElementi, sizeof(int), 1, fp);

    vettore->v = (Elemento *) malloc(vettore->nElementi * sizeof(Elemento));

    if(vettore->v == NULL)
        exit(-1);

    fread(vettore->v, sizeof(Elemento), vettore->nElementi, fp);
}

/**
 * Apre ed esegue tutti i controlli quando si apre un file
 * @param nomeFile nome del file da aprire
 * @param mode modalità di apertura del file
 * @return puntatore al file aperto
 */
FILE * openFile(char *nomeFile, char *mode){
    FILE *fp = fopen(nomeFile, mode);

    if(fp == NULL)
        exit(-1);

    return fp;
}

/**
 * Chiude un file eseguendo i controlli sul file passato
 * @param fp puntatore al file da chiudere
 * @return NULL se tutto è andato a buon fine
 */
FILE * chiudiFile(FILE * fp){

    if(fp != NULL)
        fclose(fp);

    return NULL;
}