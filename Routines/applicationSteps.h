//
// Created by SimonD on 2/5/2020.
//

#ifndef PROGETTOFINALEPOI_APPLICATIONSTEPS_H
#define PROGETTOFINALEPOI_APPLICATIONSTEPS_H

#include "applicationSteps.h"
#include "../Resources/stringStatic.h"
#include "../Utils/UI/userInterfaceUtils.h"
#include "../Model/structures.h"
#include "../Repository/pointOfInterestBinaryFileRepository.h"

#include <stdio.h>
#include <stdlib.h>

void startingMenu();
void newProjectMenu();
void loadProjectMenu();
FILE* printMessageAndOpenStream(char* message);
void mainMenu(char* fileName, FILE* fileStream);

#endif //PROGETTOFINALEPOI_APPLICATIONSTEPS_H
