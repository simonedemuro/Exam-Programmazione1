//
// Created by SimonD on 2/10/2020.
//

#include "sortHelper.h"

// this functions are here because they shouldn't be exposed to other files
void _poiDataSortAsc(dynamicArray* poiData);
void _poiDataSortDesc(dynamicArray* poiData);

/**
 * This is the function used by the application to sort the given Poi Data
 * It makes use of two private functions behind the scenes.
 * Note that the function will sort the argument passed as input
 * @param poiData
 * @param sortType Can be Asc or Desc
 */
void sortPoiData(dynamicArray* poiData, sortTypeEnum sortType){
    // sorting ascending
    if(sortType == ASC){
        _poiDataSortAsc(poiData);
    }
    // Sorting decreasing
    else if( sortType == DESC){
        _poiDataSortDesc(poiData);
    }
}

void _poiDataSortAsc(dynamicArray* poiData){
    int i, j, idxMin;
    PointOfInterest min;

    for (i = 0; i < poiData->nElementi - 1 ; ++i) {
        idxMin = i;
        min = poiData->v[i];

        for (j = i+1; j < poiData->nElementi; ++j) {
            // Smaller found
            if( strcmp(poiData->v[j].name, min.name) < 0 ){
                idxMin = j;
                min = poiData->v[j];
            }
        }
        // Swapping actual with min found
        PointOfInterest tmp = poiData->v[i];
        poiData->v[i] = poiData->v[idxMin];
        poiData->v[idxMin] = tmp;
    }
}

void _poiDataSortDesc(dynamicArray* poiData){
    int i, j, idxMax;
    PointOfInterest min;

    for (i = 0; i < poiData->nElementi - 1 ; ++i) {
        idxMax = i;
        min = poiData->v[i];

        for (j = i+1; j < poiData->nElementi; ++j) {
            // Smaller found
            if( strcmp(poiData->v[j].name, min.name) > 0 ){
                idxMax = j;
                min = poiData->v[j];
            }
        }
        // Swapping actual with max found
        PointOfInterest tmp = poiData->v[i];
        poiData->v[i] = poiData->v[idxMax];
        poiData->v[idxMax] = tmp;
    }
}