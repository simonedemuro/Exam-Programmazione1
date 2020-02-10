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
typedef enum {
    beach, Mountain, Park, Lake, Cave, Museum, ViewPoint, Other
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

/**
 * This enum is used to avoid magic numbers in the
 * application main menu aka Step 2.
 */
typedef enum {
    mListAll, mSearch, mInsert, mEdit, mDelete, mGoback
} mainMenuEnumeration;

/**
 * This enum is used to avoid magic numbers in the
 * applications's search menu
 */
typedef enum {
    sByCategory, sByMunicipe, sByKeyword, sByGeoLocation, sByAltitude
} searchMenuEnumeration;

/**
 * This enum is used to avoid magic numbers in the
 * applications's edit menu
 */
typedef enum {
    editName, editLatitude, editLongitude, editAltitude, editMunicipality, editDescription, editCategory
} editMenuEnumeration;

/**
 * This enum is used to avoid magic numbers in the
 * applications's starting menu aka Step 0
 */
 typedef enum {
     newProjectFromScratch, editAlreadyExistingProject
 }startMenuEnum;
#endif //PROGETTOFINALEPOI_STRUCTURES_H
