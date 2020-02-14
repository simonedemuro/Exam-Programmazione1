//
// Created by SimonD on 2/8/2020.
//

#ifndef PROGETTOFINALEPOI_CRUDHELPER_H
#define PROGETTOFINALEPOI_CRUDHELPER_H

#include "../Utils/DynamicArray/dynamicArray.h"

void insertNewPoi(char* fileName, dynamicArray* poiData);
void editPoi(char* fileName, dynamicArray* poiData);
void deletePoi(char* fileName, dynamicArray* poiData);
void strToLowercase(char* src, char* dest);

#endif //PROGETTOFINALEPOI_CRUDHELPER_H
