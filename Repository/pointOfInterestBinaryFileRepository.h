//
// Created by SimonD on 2/5/2020.
//

#ifndef PROGETTOFINALEPOI_POINTOFINTERESTBINARYFILEREPOSITORY_H
#define PROGETTOFINALEPOI_POINTOFINTERESTBINARYFILEREPOSITORY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../Utils/UI/userInterfaceUtils.h"
#include "../Utils/DynamicArray/dynamicArray.h"

// Config Section:
#define CONF_WORKING_PATH "Saves/"
#define CONF_WORKING_PATH_FOLDER_NAME "Saves"

FILE * openStream(char *fileName);
void generateFilePath(const char *fileName, char* filePath);
void salvaSuFileBinario(dynamicArray *poiData, FILE *fp);
void leggiDaFileBinario(dynamicArray *vettore, FILE *fp);
FILE * openFile(char *nomeFile, char *mode);
FILE * chiudiFile(FILE * fp);

#endif //PROGETTOFINALEPOI_POINTOFINTERESTBINARYFILEREPOSITORY_H
