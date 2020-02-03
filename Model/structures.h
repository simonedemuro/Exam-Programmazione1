//
// Created by SimonD on 2/3/2020.
//

#ifndef PROGETTOFINALEPOI_STRUCTURES_H
#define PROGETTOFINALEPOI_STRUCTURES_H
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

typedef struct {
    char name[64];
    double latitude;
    double longitude;
    double altitude;
    char municipality[64];
    char description[256];
    CategoryPoi category;
}
        PointOfInterest;
#endif //PROGETTOFINALEPOI_STRUCTURES_H
