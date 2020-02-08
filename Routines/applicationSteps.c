//
// Created by SimonD on 2/5/2020.
//

#include "applicationSteps.h"
#include "../Utils/DynamicArray/dynamicArray.h"
#include "searchHelper.h"


/**
 * Step 0
 * This routine represent the step 0 aka Start Menu
 */
void startingMenu(){
    printf(STR_START_MENU);
    int userAnswer = getAnswerFromUser(2);

    // as per printed enumeration runs the routine based on selected user input
    // even if the following snippet might have been simplified with an if, it haven't been for conformity wih the rest
    switch (userAnswer){
        case 1:
            newProjectMenu();
            break;
        case 2:
            loadProjectMenu();
            break;
        default:
            // every other scenario must not happen, handling just in case
            handledError();
            break;
    }
}

/**
 *  Step 1.1
 *  This routine lets the user create a project from scratch,
 *  asks for a project name and create the file to work with.
 *
 *  This step will automatically lead to Step 2
 */
void newProjectMenu(){
    // declaring and then initializing the dynamic vector and filePath
    dynamicArray poiData;
    initDynamicVector(&poiData);
    char filePath[MEDIUM_STRING];

    // clean the console for better visualization and asking the user to type a file name
    cleanConsole();
    selectFile(STR_1_NEW_PROJECT, filePath);

    // redirecting to step 2 (Main Menu)
    mainMenu(filePath, poiData);
}

/**
 *  Step 1.2
 *  This routine lets the user load an existing project,
 *  prompts a list of existing files and then lets the user pick one.
 *
 *  This step will automatically lead to Step 2
 */
void loadProjectMenu(){
    // declaring the variables needed dynamic vector and filePath
    dynamicArray poiData;
    char filePath[MEDIUM_STRING];

    // prints a message to tell the user he is going to see the files already present on disk
    printf(STR_1_LOAD_PROJECT_LIST_ALL_FILES);
    // prints the files that are currently stored locally
    printFilesLocallyStored();

    // the user is asked to type the project to be loaded and filePath will be containing its path
    selectFile(STR_1_LOAD_PROJECT, filePath);
    // opening the stream and reading the data inside
    FILE* fileStream = openFile(filePath, "r");
    leggiDaFileBinario(&poiData, fileStream);

    // redirects to step 2 (Main Menu) and passing data to it
    mainMenu(filePath, poiData);

}

/**
 * Step 2
 * This Routine will route the user to the principal operation that the user will do with this program
 * A list of activities will be printed and the user will be able to call the enumerated subroutines
 * @param fileName
 * @param fileStream
 */
void mainMenu(char* fileName, dynamicArray poiData){
    // prints a message informing the user of the available options
    printf(STR_2_MAIN_MENU);

    // safely getting an answer from the user trough this (magic 6 is the number of available options)
    int userAnswer = getAnswerFromUser(6);
    // based on the operation typed run a subroutine
    switch (userAnswer){
        case mListAll:
            stampaElementi(poiData);
            break;
        case mSearch:
            searchMenuHandler(fileName, poiData);
            break;
        case mInsert:
            insertNewPoi(fileName, poiData);
            break;
        case mEdit:
            break;
        case mDelete:
            break;
        case mGoback:
            break;
        default:
            break;
    }
    //fclose(fileStream);
}

/**
 * Step 3
 *
 * This function prompts the available search options and redirects to the selected one 
 * @param fileName is the current file in use 
 * @param poiData is the data currently in use  
 */
void searchMenuHandler(char* fileName, dynamicArray poiData){
    int selectedOption;
    // prompt message
    printf(STR_3_SEARCH_MENU);
    printf(STR_CURSOR);
    // get selection from user
    selectedOption = getAnswerFromUser(5);

    // redirects the user to the selected type of search to be performed
    // the options are explicated by their enumerated names
    switch (selectedOption){
        case sByCategory:
            searchByCategory(fileName, poiData);
            break;
        case sByMunicipe:
            searchByMunicipe(fileName, poiData);
            break;
        case sByKeyword:
            searchByKeyword(fileName, poiData);
            break;
        case sByGeoLocation:
            searchByGeographicalLocation(fileName, poiData);
            break;
        case sByAltitude:
            searchByAltitude(fileName, poiData);
            break;
        default:
            handledError();
            break;
    }

}

/**
 * Since new project and load project are very similar, this function provides a common template to avoid
 * code repetitions.
 * @param message is the message is gonna be prompted to user
 * @param filePath is an output parameter used to return the filePath the user picked
 * @return the pointer to the file typed by the user
 */
void selectFile(char* message, char* filePath){
    // declaring the variable to hold the fileName that will be generated
    char fileName[SHORT_STRING];
    // prompt the awareness message asking for the filename
    printf(STR_1_NEW_PROJECT);
    // printing the cursor
    printf(STR_CURSOR);

    // read user input spaces included the getChar is intended to free the buffer
    // Todo: find a fancier way to free the buffer
    getchar();
    scanf("%[^\n]", fileName);

    // generating the file path (not only the name)
    generateFilePath(fileName, filePath);
}

