//
// Created by SimonD on 2/11/2020.
//

#include <stdio.h>
#include "pointOfInterestTextFileRepository.h"


/**
 * This function prints to file the PoiData with the same format as the console output
 * this function is used after searches has been performed to export them to file.
 * @param fileName
 * @param poiData
 */
void writePoisToFile(char fileName[], dynamicArray* poiData){
    // for loop var
    int i = 0;
    // declare a File Pointer and initialize to Null in order to let me check for the correct opening
    FILE *filePointer = NULL;
    // open in write mode
    filePointer = fopen(fileName, "w");
    // in case it is null something went wrong, writing an error
    if (filePointer == NULL)
        handledError();

    // writing Points to file
    for(i = 0; i < poiData->nElementi; ++i){
        // writing the index
        fprintf(filePointer, "INDEX: %d", i);

        // writing the properties
        fprintf(filePointer, "  Name: %s\n", poiData->v[i].name);
        fprintf(filePointer, "  Latitude: %f\n", poiData->v[i].latitude);
        fprintf(filePointer, "  Longitude: %f\n", poiData->v[i].longitude);
        fprintf(filePointer, "  altitude\': %f\n", poiData->v[i].altitude);
        fprintf(filePointer, "  Municipality: %s\n", poiData->v[i].municipality);
        fprintf(filePointer, "  Description: %s\n  ", poiData->v[i].description);

        // printing the category
        fprintf(filePointer, "Category: ");
        switch (poiData->v[i].category){
            case beach:
                fprintf(filePointer, "beach");
                break;
            case Mountain:
                fprintf(filePointer, "Mountain");
                break;
            case Park:
                fprintf(filePointer, "Park");
                break;
            case Lake:
                fprintf(filePointer, "Lake");
                break;
            case Cave:
                fprintf(filePointer, "Cave");
                break;
            case Museum:
                fprintf(filePointer, "Museum");
                break;
            case ViewPoint:
                fprintf(filePointer, "ViewPoint");
                break;
            case Other:
                fprintf(filePointer, "Other");
                break;
            default:
                fprintf(filePointer, "error");
                break;
        }

        // new line accordingly also to the front end output
        fprintf(filePointer, "\n");
    }

    // free buffer and close file
    free(filePointer);
    fclose(filePointer);
}