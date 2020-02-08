//
// Created by SimonD on 2/8/2020.
//

#ifndef PROGETTOFINALEPOI_SEARCHHELPER_H
#define PROGETTOFINALEPOI_SEARCHHELPER_H

#include "../Utils/DynamicArray/dynamicArray.h"

/*search menus*/
int searchByCategory(char* fileName, dynamicArray poiData);
int searchByMunicipe(char* fileName, dynamicArray poiData);
int searchByKeyword(char* fileName, dynamicArray poiData);
int searchByGeographicalLocation(char* fileName, dynamicArray poiData);
int searchByAltitude(char* fileName, dynamicArray poiData);

#endif //PROGETTOFINALEPOI_SEARCHHELPER_H
