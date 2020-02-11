//
// Created by SimonD on 2/10/2020.
//

#ifndef PROGETTOFINALEPOI_SORTHELPER_H
#define PROGETTOFINALEPOI_SORTHELPER_H

#include "../Model/structures.h"
#include "../Utils/DynamicArray/dynamicArray.h"
#include <math.h>

#define EARTH_RADIOUS 6371

void sortPoiData(dynamicArray* poiData, sortTypeEnum sortType);
void searchOutputCommonHandler(dynamicArray *poiData, dynamicArray *searchResult);

#endif //PROGETTOFINALEPOI_SORTHELPER_H
