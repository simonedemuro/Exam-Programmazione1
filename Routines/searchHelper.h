//
// Created by SimonD on 2/8/2020.
//

#ifndef PROGETTOFINALEPOI_SEARCHHELPER_H
#define PROGETTOFINALEPOI_SEARCHHELPER_H

#include <ctype.h>
#include "../Utils/DynamicArray/dynamicArray.h"
#include "../Resources/stringStatic.h"
#include "../Utils/UI/userInterfaceUtils.h"
#include "sortHelper.h"
#include "../Repository/pointOfInterestTextFileRepository.h"
#include "../Repository/pointOfInterestBinaryFileRepository.h"


/*search menus*/
int searchByCategory(char* fileName, dynamicArray poiData);
int searchByMunicipe(char* fileName, dynamicArray poiData);
int searchByKeyword(char* fileName, dynamicArray poiData);
int searchByGeographicalLocation(char* fileName, dynamicArray poiData);
int searchByAltitude(char* fileName, dynamicArray poiData);
altitudeEnum getPoiAltitudeEnumByPoi(PointOfInterest p);
_Bool equalsIgnoreCase(char* firstStr, char* secondStr);


#endif //PROGETTOFINALEPOI_SEARCHHELPER_H
