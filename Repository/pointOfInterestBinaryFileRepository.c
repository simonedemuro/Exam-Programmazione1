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
 * This function is crucial to generate the file path given a file name by concatenating the path to the file
 * @param fileName is the file name passed
 * @param filePath represents an output like parameter containing the filePath
 */
void generateFilePath(const char *fileName, char* filePath) {
    strcpy(filePath, CONF_WORKING_PATH);
    strcat(filePath, fileName);
}
