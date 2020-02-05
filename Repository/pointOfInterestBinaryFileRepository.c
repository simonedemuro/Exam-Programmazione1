//
// Created by SimonD on 2/5/2020.
//

#include "pointOfInterestBinaryFileRepository.h"

/**
 * Open a fileStream
 * @param nomeFile is the fileName you wish to open
 * @return file pointer (open stream)
 */
FILE * openStream(char *nomeFile){
    // attempt to open a stream to nomeFile
    FILE *fp = fopen(nomeFile, "w");

    // if case of error alert the user
    if(fp == NULL){
        printf("An error occurred opening the file %s (File Pointer Exception)", nomeFile);
        getchar();
        handledError();
    }

    // returning the stream just opened
    return fp;
}