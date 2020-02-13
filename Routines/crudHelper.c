//
// Created by SimonD on 2/8/2020.
//

#include "crudHelper.h"
#include "../Utils/UI/userInterfaceUtils.h"
#include "../Repository/pointOfInterestBinaryFileRepository.h"

/**
 * This is the function responsible to add new point of interest
 * @param fileName
 * @param poiData
 */
void insertNewPoi(char* fileName, dynamicArray* poiData){
    // declaration of the point to be added
    PointOfInterest pointToBeAdded;
    _Bool wantsToSave = false;

    // printing an instructional message
    printf(STR_INSERT_HOME);

    // gaining attribute by attribute all the information mandatory for a new Poi to be added
    printf("Name: ");
    scanf("%[^\n]", pointToBeAdded.name);
    // asking for latitude until the user enters a valid number (belonging to sardinia)
    printf("Latitude: ");
    pointToBeAdded.latitude = getLatitudeAnswerFromUser();
    // asking for longitude until the user enters a valid number (belonging to sardinia)
    printf("Longitude: ");
    pointToBeAdded.longitude = getLongitudeAnswerFromUser();
    printf("Altitude: ");
    scanf("%lf", &pointToBeAdded.altitude);
    printf("Municipality: ");
    getchar();
    scanf("%[^\n]", pointToBeAdded.municipality);
    printf("Description: ");
    getchar();
    scanf("%[^\n]", pointToBeAdded.description);
    // The category enmumerative type is handled as a number,
    // printing a category enumerator resume to make him able to chose one by number
    printf(STR_LIST_CATEGORIES_ENUM);
    pointToBeAdded.category = getNumericAnswerFromUser(8);

    // adding the newly generated Poi in memory
    aggiungiElemento(poiData, pointToBeAdded);

    // ask if the user wants to save and acts accordingly
    printf(STR_SAVE_WARNING);
    wantsToSave = getYesNoAnswerFromUser();
    if(wantsToSave){
        // opens the stream, saves to disk (eventually overriding), then closes the stream
        FILE* filePointer = openFile(fileName, "wb");
        salvaSuFileBinario(poiData, filePointer);
        filePointer = chiudiFile(filePointer);
    }
    //cleans the console to leave the output clean for the next window
    cleanConsole();
}

/**
 * This is the function responsible to edit a Point of Interest
 * 1. asks for the Poi's index that the user wants to edit
 * 2. asks for the field that the user wants to modify
 * 3. asks if the user wants to save the changes applied to file accordingly
 * @param fileName
 * @param poiData is the array of data currently in use
 */
void editPoi(char* fileName, dynamicArray* poiData){
    // user's will to save changes, by default is no
    _Bool wantsToSave = false;
    // this will contain the Poi's index that will be modified
    int poiToBeEditedIndex = 0;
    // this will contain the operation's value (editMenuEnumeration)
    editMenuEnumeration selectedOperation = 0;

    // Lists the Pois available and asks the user which Poi wants to edit
    printPoiArray(*poiData);
    printf("\nType the index of the Point you want to edit:\n");

    // Gets the index that the user wants to edit (checking if it is in a valid range)
    poiToBeEditedIndex = getNumericAnswerFromUser(poiData->nElementi);

    // printing a menu asking for the field that the user wants to edit
    printf(STR_EDIT_POI_MENU);
    // based on the field that the user wants to edit the program is going to expect a different type here is the selection
    selectedOperation = getNumericAnswerFromUser(6);

    switch (selectedOperation)
    {
        case editName:
            printf("Type the new Name:\n");
            printf(STR_CURSOR);
            scanf("%[^\n]", poiData->v[poiToBeEditedIndex].name );
            freeTheBuffer();
            break;
        case editLatitude:
            printf("Type the new Latitude:\n");
            printf(STR_CURSOR);
            poiData->v[poiToBeEditedIndex].latitude = getLatitudeAnswerFromUser();
            break;
        case editLongitude:
            printf("Type the new Longitude:\n");
            printf(STR_CURSOR);
            poiData->v[poiToBeEditedIndex].longitude = getLongitudeAnswerFromUser();
            break;
        case editAltitude:
            printf("Type the new Altitude:\n");
            printf(STR_CURSOR);
            scanf("%lf", &poiData->v[poiToBeEditedIndex].altitude );
            break;
        case editMunicipality:
            printf("Type the new Municipality:\n");
            printf(STR_CURSOR);
            scanf("%[^\n]", poiData->v[poiToBeEditedIndex].municipality );
            freeTheBuffer();
            break;
        case editDescription:
            printf("Type the new Description:\n");
            printf(STR_CURSOR);
            scanf("%[^\n]", poiData->v[poiToBeEditedIndex].description );
            freeTheBuffer();
            break;
        case editCategory:
            printf(STR_LIST_CATEGORIES_ENUM);
            poiData->v[poiToBeEditedIndex].category = getNumericAnswerFromUser(8);
            break;
        default:
            handledError();
    }

    // ask if the user wants to save and acts accordingly by using the usual util
    printf(STR_SAVE_WARNING);
    wantsToSave = getYesNoAnswerFromUser();
    // if save has been selected saves to disk.
    if(wantsToSave){
        // opens the stream, saves to disk (eventually overriding), then closes the stream
        FILE* filePointer = openFile(fileName, "wb");
        salvaSuFileBinario(poiData, filePointer);
        filePointer = chiudiFile(filePointer);
    }

    // boyscout clean before leaving :D
    cleanConsole();
}

/**
 * This is the function responsible to delete a Point of Interest from the list of available POIs
 * 1. asks for the Poi's index that the user wants to delete
 * 3. asks if the user wants to save the changes applied to file accordingly
 * @param fileName
 * @param poiData is the array of data currently in use
 */
void deletePoi(char* fileName, dynamicArray* poiData){
    // user's will to save changes, by default is no
    _Bool wantsToSave = false;
    // this will contain the Poi's index that will be deleted
    int poiToBeDeletedIndex = 0;

    // Lists the Pois available and asks the user which Poi wants to edit
    printPoiArray(*poiData);
    printf("\nType the index of the Point you want to delete:\n");

    // Gets the index that the user wants to delete (checking if it is in a valid range)
    poiToBeDeletedIndex = getNumericAnswerFromUser(poiData->nElementi);

    // Actually deleting
    deletePoiAt(poiData, poiToBeDeletedIndex);

    // ask if the user wants to save and acts accordingly by using the usual util
    printf(STR_SAVE_WARNING);
    wantsToSave = getYesNoAnswerFromUser();
    // if save has been selected saves to disk.
    if(wantsToSave){
        // opens the stream, saves to disk (eventually overriding), then closes the stream
        FILE* filePointer = openFile(fileName, "wb");
        salvaSuFileBinario(poiData, filePointer);
        filePointer = chiudiFile(filePointer);
    }

    // boyscout clean before leaving :D
    cleanConsole();

}
