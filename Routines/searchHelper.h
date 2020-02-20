//
// Created by SimonD on 2/8/2020.
//

#ifndef PROGETTOFINALEPOI_SEARCHHELPER_H
#define PROGETTOFINALEPOI_SEARCHHELPER_H

#include <ctype.h>

#define MIN_SARDINIAN_LATITUDE 38.86444444

#define MAX_SARDINIAN_LATITUDE 41.26166667

#define MIN_SARDINIAN_LONGITUDE 8.13333333

#define MAX_SARDINIAN_LONGITUDE 9.83333333
#include "../Utils/DynamicArray/dynamicArray.h"
#include "../Resources/stringStatic.h"
#include "../Utils/UI/userInterfaceUtils.h"
#include "sortHelper.h"
#include "../Repository/pointOfInterestTextFileRepository.h"
#include "../Repository/pointOfInterestBinaryFileRepository.h"
#include "crudHelper.h"
#include <math.h>


/*search menus*/
int searchByCategory(char* fileName, dynamicArray poiData);
int searchByMunicipe(char* fileName, dynamicArray poiData);
int searchByKeyword(char* fileName, dynamicArray poiData);
int searchByGeographicalLocation(char* fileName, dynamicArray poiData);
int searchByAltitude(char* fileName, dynamicArray poiData);
altitudeEnum getPoiAltitudeEnumByPoi(PointOfInterest p);

_Bool equalsIgnoreCase(char* firstStr, char* secondStr);
double geoDistance (double latA, double lonA, double latB, double lonB);
_Bool isInSardinia(double lat, double lon);


#endif //PROGETTOFINALEPOI_SEARCHHELPER_H
