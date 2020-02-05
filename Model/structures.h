//
// Created by SimonD on 2/3/2020.
//

#ifndef PROGETTOFINALEPOI_STRUCTURES_H
#define PROGETTOFINALEPOI_STRUCTURES_H

#define SHORT_STRING 64
#define MEDIUM_STRING 256

/**
 * Declaring the enumerator used to store the POI categories
 */
typedef enum  {
    beach,
    Mountain,
    Park,
    Lake,
    Cave,
    Museum,
    ViewPoint,
    Other
} CategoryPoi;

/**
 *  most important Structure of the project (POI)
 */
typedef struct {
    char name[SHORT_STRING];
    double latitude;
    double longitude;
    double altitude;
    char municipality[SHORT_STRING];
    char description[MEDIUM_STRING];
    CategoryPoi category;
} PointOfInterest;


#endif //PROGETTOFINALEPOI_STRUCTURES_H
