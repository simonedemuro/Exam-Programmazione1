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
#include "../Utils/DynamicArray/dynamicArray.h"

#include <stdio.h>
#include <stdlib.h>

void startingMenu();
void newProjectMenu();
void loadProjectMenu();
void selectFile(char* message, char* filePath);
void mainMenu(char* fileName, dynamicArray poiData);
void searchMenuHandler(char* fileName, dynamicArray poiData);

/*CRUD operations */


#endif //PROGETTOFINALEPOI_APPLICATIONSTEPS_H
