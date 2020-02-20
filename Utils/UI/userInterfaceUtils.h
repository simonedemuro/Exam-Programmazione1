//
// Created by SimonD on 2/3/2020.
//

#ifndef PROGETTOFINALEPOI_USERINTERFACEUTILS_H
#define PROGETTOFINALEPOI_USERINTERFACEUTILS_H

#include <stdio.h>
#include <stdbool.h>
#include "../../Resources/stringStatic.h"


int getNumericAnswerFromUser(int maxOptionAvailable);
void handledError();
void cleanConsole();
void printFilesLocallyStored();
_Bool getYesNoAnswerFromUser();
void freeTheBuffer();
double getLongitudeAnswerFromUser();
double getLatitudeAnswerFromUser();

#endif //PROGETTOFINALEPOI_USERINTERFACEUTILS_H
