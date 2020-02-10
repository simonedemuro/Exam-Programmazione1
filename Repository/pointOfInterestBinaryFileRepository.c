//
// Created by SimonD on 2/5/2020.
//

#include "pointOfInterestBinaryFileRepository.h"

/**
 * Open a fileStream
 * @param fileName is the fileName you wish to open
 * @return file pointer (open stream)
 */
FILE * openStream(char *fileName){
    // Filepath is the concatenation of the working directory and the file name provided by the user
    char filePath[100];
    generateFilePath(fileName, filePath);

    printf("%s", filePath);
    FILE *fp = fopen(filePath, "w");

    // if case of error alert the user
    if(fp == NULL){
        printf("An error occurred opening the file %s (File Pointer Exception)", filePath);
        getchar();
        handledError();
    }

    // returning the stream just opened
    return fp;
}

/**
 * opens a file performing consistency checks
 * @param nomeFile file name to be opened
 * @param mode mode
 * @return file pointer
 */
FILE * openFile(char *nomeFile, char *mode){
    FILE *fp = fopen(nomeFile, mode);

    if(fp == NULL)
        exit(-1);

    return fp;
}

/**
 * closes a stream and performs controls
 * @param fp file pointer
 * @return NULL if the stream was closed smootly.
 */
FILE * chiudiFile(FILE * fp){
    if(fp != NULL)
        fclose(fp);
    return NULL;
}


/**
 * This function is crucial to generate the file path given a file name by concatenating the path to the file
 * @param fileName is the file name passed
 * @param filePath represents an output like parameter containing the filePath
 */
void generateFilePath(const char *fileName, char* filePath) {
    strcpy(filePath, CONF_WORKING_PATH);
    strcat(filePath, fileName);
}

/**
 * Leggo i dati di un vettore dinami e creo un file binario con i dati letti
 * @param poiData vettore dinamico
 * @param fp puntatore al file binario
 */
void salvaSuFileBinario(dynamicArray *poiData, FILE *fp){
    dynamicArray* tmpData = poiData;
    int nElementi = tmpData->nElementi;
    fwrite(&nElementi, sizeof(int), 1, fp);
    fwrite(tmpData->v, sizeof(PointOfInterest), nElementi, fp);
}

/**
 * Leggo i dati di un file binario e creo un vettore dinamico con i dati del file
 * @param vettore vettore da popolare
 * @param fp puntatore al file binario
 */
void leggiDaFileBinario(dynamicArray *vettore, FILE *fp){
    fread(&vettore->nElementi, sizeof(int), 1, fp);

    vettore->v = (PointOfInterest *) malloc(vettore->nElementi * sizeof(PointOfInterest));

    if(vettore->v == NULL)
        exit(-1);

    fread(vettore->v, sizeof(PointOfInterest), vettore->nElementi, fp);
}