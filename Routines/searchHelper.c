//
// Created by SimonD on 2/8/2020.
//

#include "searchHelper.h"

/**
 * Performs a search by category meaning
 * Given a category to search for, returns every Poi in the array that matches the category
 *
 * @param fileName is the filename in use
 * @param poiData is the data in which to search
 * @return the number of matching POIs
 */
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
    categoryToSearchFrom = getNumericAnswerFromUser(7);

    // performing the search, iterating over the whole POI collection
    for (i = 0; i < poiData.nElementi; ++i) {
        // whenever a point belongs to a Category it is added to the result collection that will be shown next
        if(poiData.v[i].category == categoryToSearchFrom){
            addItem(&searchResult, poiData.v[i]);
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
 * @return the number of matching POIs
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
    scanf("%[^\n]", municipeToChoseFrom);
    freeTheBuffer();

    // performing the search, iterating over the whole POI collection
    for (i = 0; i < poiData.nElementi; ++i) {
        // whenever a point matches a Municipe (Case insensitive) it is added to the result collection that will be shown next
        if( strcasecmp(poiData.v[i].municipality, municipeToChoseFrom) == 0){
            addItem(&searchResult, poiData.v[i]);
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
 * This routine performs a search inside of the Poi's description,
 * It matches every POI that contains the given word inside of the description ignoring casing
 * @param fileName is the file name actually in use
 * @param poiData is the data in use
 * @return the number of matching POIs
 */
int searchByKeyword(char* fileName, dynamicArray poiData){
    /* declarative space, the variable names in use are long and self-explaintory */
    char descriptionKeywordToSearchFor[MEDIUM_STRING];
    int i = 0; // for loop index
    dynamicArray searchResult;
    // arguments but lowercase
    char currentPoiDescriptionLowercase[MEDIUM_STRING];
    char descriptionKeywordToSearchForLowercase[MEDIUM_STRING];


    // initializing the vector
    initDynamicVector(&searchResult);

    // Prompting a message and asking for the descriprion keyword to search for
    printf("Type the Description you want to search for:\n");
    printf(STR_CURSOR);
    scanf("%[^\n]", descriptionKeywordToSearchFor);
    freeTheBuffer();

    // performing the search, iterating over the whole POI collection
    for (i = 0; i < poiData.nElementi; ++i) {
        // lowercasing the search arguments given
        strToLowercase(descriptionKeywordToSearchFor, descriptionKeywordToSearchForLowercase);
        strToLowercase(poiData.v[i].description, currentPoiDescriptionLowercase);
        // whenever a point's description contains the given keyword it is added to the result
        // the following command is a contains (string.h) different than NULL means it is contained 1
        if( strstr(currentPoiDescriptionLowercase, descriptionKeywordToSearchForLowercase) != NULL ){
            addItem(&searchResult, poiData.v[i]);
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
 * Assuming the earth as a perfect sphere, the radius is also approssimate
 * @param fileName
 * @param poiData
 * @return
 */
int searchByGeographicalLocation(char* fileName, dynamicArray poiData){
    /* declarative space, the variable names in use are long and self-explaintory */
    double latitudeToSearchFor, longitudeToSearchFor, radiusOfTheSearch, calculatedDistance;
    int i = 0; // for loop index
    dynamicArray searchResult;

    // initializing the result vector
    initDynamicVector(&searchResult);

    // Asks the user to point define the center point he wants to search near by
    printf("Type the point's latitude you want search for: \n");
    latitudeToSearchFor = getLatitudeAnswerFromUser();
    printf("Type the point's longitude you want search for: \n");
    longitudeToSearchFor = getLongitudeAnswerFromUser();
    
    // Asks for the radious of the search to be performed
    printf("Type the radious you want use to circumscribe your search: \n");
    scanf("%lf", &radiusOfTheSearch);
    freeTheBuffer();

    // performing the search, iterating over the whole POI collection
    for (i = 0; i < poiData.nElementi; ++i) {
        // calculating the distance using the geoDistance function, providing the two points
        calculatedDistance =
                geoDistance(poiData.v[i].latitude, poiData.v[i].longitude, latitudeToSearchFor, longitudeToSearchFor);

        // whenever a point's distance is lower or equal to the given radius (is close enough) it is added to results
        if( calculatedDistance <= radiusOfTheSearch ){
            addItem(&searchResult, poiData.v[i]);
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
 * This funciton calculates the distance between two points <(latA, lonA),(latB, lonB)>
 * This functions is a refactored version of the following:
 * Further lectures: https://www.geeksforgeeks.org/program-distance-two-points-earth/
 * @param latA first point latitude
 * @param lonA first point longitude
 * @param latB second point latitude
 * @param lonB second point longitude
 * @return the distance in Km between two points
 */
double geoDistance (double latA, double lonA, double latB, double lonB)
{
    // Defining the Constants
    double radiantLatA, radiantLatB, radiantLonA, radiantLonB;
    double fi;
    double angleIncluded, distance;

    // Degrees to radiants
    radiantLatA = M_PI * latA / 180;
    radiantLatB = M_PI * latB / 180;
    radiantLonA = M_PI * lonA / 180;
    radiantLonB = M_PI * lonB / 180;
    // Calculating the angle between the axes
    fi = fabs(radiantLonA - radiantLonB);
    // Calcola il terzo lato del triangolo sferico
    angleIncluded = acos(sin(radiantLatB) * sin(radiantLatA) +
                         cos(radiantLatB) * cos(radiantLatA) * cos(fi));
    // Calculating the actual distance
    distance = angleIncluded * EARTH_RADIOUS;

    return distance;
}

/**
 * compresa tra i 38° 51' 52" (38.86444444) e i 41° 15' 42" (41.26166667) di latitudine Nord e
 *          tra gli 8° 8' (8.13333333) e 9° 50' (9.83333333) di longitudine Est
 * @param lat the point's latitude
 * @param lon the point's longitude
 * @return true if the point belongs to sardinia, false otherwise
 */
_Bool isInSardinia(double lat, double lon){
    // checking the latitude
    _Bool isSardinianLatitude = (lat >= MIN_SARDINIAN_LATITUDE && lat <= MAX_SARDINIAN_LATITUDE);
    // checking the longitude
    _Bool isSardinianLongitude = (lon >= MIN_SARDINIAN_LONGITUDE &&  lon <= MAX_SARDINIAN_LONGITUDE);

    // if it matches both, the point belong to motherland
    if(isSardinianLatitude && isSardinianLongitude)
        return true;
    // otherwise it does not
    return false;
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

/**
 * This routine compares the altitudes of the pois and returns the one with the
 * altitude the user is searching for
 * @param fileName
 * @param poiData
 * @return
 */
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
            addItem(&searchResult, poiData.v[i]);
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
 * This routine is common to all search procedures and is the one responsible for
 * @param poiData
 * @param searchResult
 */
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
    printf("Here is the list of Point of Interests filtered by your criteria\n\n");
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
        sortPoiData(searchResult, sortType);

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
        scanf("%[^\n]", fileName);
        freeTheBuffer();

        // create the file path based on the provided file name by adding the working directory to the name
        generateFilePath(fileName, filePath);

        // Actually writing the previously presented data to file
        writePoisToFile(filePath, searchResult);
    }
    cleanConsole();
}


/**
 * compares two strings ignoring the casing
 * @param firstStr string to be compared to the next given
 * @param secondStr string to be compared to the previous one
 * @return true if they are the same, false otherwise
 */
_Bool equalsIgnoreCase(char* firstStr, char* secondStr){
    int i = 0;
    // if they are not the same length they can't be the equal, returning false avoiding loop check
    if( strlen(firstStr) != strlen(secondStr) )
        return false;

    // Assuming the strings to be the same length, checking them character by character ignoring the casing
    for (i = 0; i < strlen(firstStr); ++i) {
        if ( tolower(firstStr[i]) != tolower(secondStr[i]) )
            return false;
    }
    // if this the code have been reached the strings are equal
    return true;
}

/**
 *  This function given two strings writes the second one with the first one content to lowercase
 * @param src source string
 * @param dest is the result (src) to lowercase
 */
void strToLowercase(char* src, char* dest){
    int i;
    for (i = 0; i < strlen(src) ; ++i) {
        dest[i] = (char)tolower(src[i]);
    }
    // adding string terminator
    dest[i+1] = '\0';
}