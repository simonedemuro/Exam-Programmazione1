//
// Created by SimonD on 2/8/2020.
//

#include "searchHelper.h"
#include "../Repository/pointOfInterestTextFileRepository.h"
#include "../Repository/pointOfInterestBinaryFileRepository.h"


int searchByCategory(char* fileName, dynamicArray poiData){
    /* declarative space, the variable names in use are long and self-explaintory */
    int categoryToSearchFrom = 0;
    int i = 0; // for loop index
    dynamicArray searchResult;

    // initializing the vector
    initDynamicVector(&searchResult);

    // writes a message and recaps the categories from which you can chose form
    printf(STR_LIST_CATEGORIES_ENUM);

    // gets the category from the user using the usual integer acquisition procedure
    categoryToSearchFrom = getNumericAnswerFromUser(8);

    // performing the search, iterating over the whole POI collection
    for (i = 0; i < poiData.nElementi; ++i) {
        // whenever a point belongs to a Category it is added to the result collection that will be shown next
        if(poiData.v[i].category == categoryToSearchFrom){
            aggiungiElemento(&searchResult, poiData.v[i]);
        }
    }

    // if the query didn't retrieved the data prints a message and skips the next statements by returning back
    if(searchResult.nElementi <= 0){
        printf(STR_NO_DATA_FOUND);
        return searchResult.nElementi;
    }

    // Since this function is common for all of the searches that can be performed
    // it will take care to display the fetched data, sort and export accordingly to the user's will
    searchOutputCommonHandler(&poiData, &searchResult);

    return searchResult.nElementi;
}

/**
 *  Case insensitive, Matching Municipality
 *  This function makes use of strcasecmp see https://www.ibm.com/support/knowledgecenter/SSLTBW_2.2.0/com.ibm.zos.v2r2.bpxbd00/rsrccm.htm
 * @param fileName
 * @param poiData
 * @return
 */
int searchByMunicipe(char* fileName, dynamicArray poiData){
    /* declarative space, the variable names in use are long and self-explaintory */
    char municipeToChoseFrom[MEDIUM_STRING];
    int i = 0; // for loop index
    dynamicArray searchResult;

    // initializing the vector
    initDynamicVector(&searchResult);

    // Prompting a message and asking for the Municipality to search for
    printf("Type the municipality you want to search for:\n");
    printf(STR_CURSOR);
    freeTheBuffer();
    scanf("%[^\n]", municipeToChoseFrom);

    // performing the search, iterating over the whole POI collection
    for (i = 0; i < poiData.nElementi; ++i) {
        // whenever a point matches a Municipe (Case insensitive) it is added to the result collection that will be shown next
        if( strcasecmp(poiData.v[i].municipality, municipeToChoseFrom) == 0){
            aggiungiElemento(&searchResult, poiData.v[i]);
        }
    }

    // if the query didn't retrieved the data prints a message and skips the next statements by returning back
    if(searchResult.nElementi <= 0){
        printf(STR_NO_DATA_FOUND);
        return searchResult.nElementi;
    }

    // Since this function is common for all of the searches that can be performed
    // it will take care to display the fetched data, sort and export accordingly to the user's will
    searchOutputCommonHandler(&poiData, &searchResult);

    return searchResult.nElementi;
}
int searchByKeyword(char* fileName, dynamicArray poiData){
    /* declarative space, the variable names in use are long and self-explaintory */
    char descriptionKeyword[MEDIUM_STRING];
    int i = 0; // for loop index
    dynamicArray searchResult;

    // initializing the vector
    initDynamicVector(&searchResult);

    // Prompting a message and asking for the descriprion keyword to search for
    printf("Type the Description you want to search for:\n");
    printf(STR_CURSOR);
    freeTheBuffer();
    scanf("%[^\n]", descriptionKeyword);

    // performing the search, iterating over the whole POI collection
    for (i = 0; i < poiData.nElementi; ++i) {
        // whenever a point's description contains the given keyword it is added to the result
        // the following command is a contains (string.h)
        if( strstr(strlwr(poiData.v[i].description), strlwr(descriptionKeyword)) != NULL ){
            aggiungiElemento(&searchResult, poiData.v[i]);
        }
    }

    // if the query didn't retrieved the data prints a message and skips the next statements by returning back
    if(searchResult.nElementi <= 0){
        printf(STR_NO_DATA_FOUND);
        return searchResult.nElementi;
    }

    // Since this function is common for all of the searches that can be performed
    // it will take care to display the fetched data, sort and export accordingly to the user's will
    searchOutputCommonHandler(&poiData, &searchResult);

    return searchResult.nElementi;
}


int searchByGeographicalLocation(char* fileName, dynamicArray poiData){
    return -1;
}

/**
 * This function returns the enumerated altitude for a given Point of interest
 * @param p is the point of interest tested
 * @return the relative altitudeEnum
 */
altitudeEnum getPoiAltitudeEnumByPoi(PointOfInterest p){
    // Plane are between 0 and 50 by specifications
    if(p.altitude <= 50 )
        return plane;
    // Hill between 51 and 800 (if instead of else if in this scenario is a personal style preference)
    if(p.altitude>=51 && p.altitude <= 800)
        return hill;
    // Otherwise (it is bigger unless the data is corrupted) it is a Mountain
    return mountain;
}

int searchByAltitude(char* fileName, dynamicArray poiData){
    /* declarative space, the variable names in use are long and self-explaintory */
    altitudeEnum selectedAltitude;
    int i = 0; // for loop index
    dynamicArray searchResult;

    // initializing the vector
    initDynamicVector(&searchResult);

    // Prompting a message and asking for the descriprion keyword to search for
    printf("Select the altitude you want to search for:\n0. Plane\n1. Hill\n2. Mountain\n");
    selectedAltitude = getNumericAnswerFromUser(2);

    // performing the search, iterating over the whole POI collection
    for (i = 0; i < poiData.nElementi; ++i) {
        // If the poi's altitude is equal to the user's selected one add it to the result output
        if( getPoiAltitudeEnumByPoi(poiData.v[i]) == selectedAltitude ){
            aggiungiElemento(&searchResult, poiData.v[i]);
        }
    }

    // if the query didn't retrieved the data prints a message and skips the next statements by returning back
    if(searchResult.nElementi <= 0){
        printf(STR_NO_DATA_FOUND);
        return searchResult.nElementi;
    }

    // Since this function is common for all of the searches that can be performed
    // it will take care to display the fetched data, sort and export accordingly to the user's will
    searchOutputCommonHandler(&poiData, &searchResult);

    return searchResult.nElementi;
}

void searchOutputCommonHandler(dynamicArray *poiData, dynamicArray *searchResult) {
    // for counter
    int i = 0;
    // this variables will hold the file name and related automatically generated working path
    char fileName[MEDIUM_STRING];
    char filePath[MEDIUM_STRING];
    // user willness to save
    _Bool exportData;
    // asc or desc?
    sortTypeEnum sortType;
    _Bool sortOutput;


    // showing the fetched data
    printf("Here is the list of Point of Interests filtered by your criteria\n");
    for (i = 0; i < (*searchResult).nElementi; ++i) {
        printf("INDEX: %d", i);
        printElement((*searchResult).v[i]);
    }

    // asking if the user wants to sort the data
    printf("Do you want to sort the data shown? (Y/N)\n");
    sortOutput = getYesNoAnswerFromUser();

    // If the user wants to sort the data is asked to decide to sort ascending or descending
    if(sortOutput){
        printf("Do you want to order Ascending or Descending?\n0. Ascending\n1. Descending\n");
        sortType = getNumericAnswerFromUser(1);
        // Calls the sort subroutine
        sortPoiData(poiData, sortType);

        // Showing the data after has been sorted (if so)
        for(i = 0; i < (*searchResult).nElementi; ++i){
            printf("INDEX: %d", i);
            printElement((*searchResult).v[i]);
        }
    }


    // Asks if the user wants to export the data to file
    printf("Do you want to save this output to file? (Y/N)\n");
    exportData = getYesNoAnswerFromUser();

    // If the user wants to export the fetched data
    if(exportData){
        // Getting the file name to save into
        printf("Type the file name you want export to (Tip: naming the file .txt will help the OS to find an appropriate program to open the file )\n");
        printf(STR_CURSOR);
        freeTheBuffer();
        scanf("%[^\n]", fileName);

        // create the file path based on the provided file name by adding the working directory to the name
        generateFilePath(fileName, filePath);

        // Actually writing the previously presented data to file
        writePoisToFile(filePath, searchResult);
    }
    cleanConsole();
}

/*
 * If the compiler doesn't support strlwr uncomment
 * #include <string.h>
#include<ctype.h>

char *strlwr(char *str)
{
  unsigned char *p = (unsigned char *)str;

  while (*p) {
     *p = tolower((unsigned char)*p);
      p++;
  }

  return str;
}
 * */