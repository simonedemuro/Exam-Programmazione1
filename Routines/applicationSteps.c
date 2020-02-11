//
// Created by SimonD on 2/5/2020.
//

#include "applicationSteps.h"
#include "../Utils/DynamicArray/dynamicArray.h"
#include "searchHelper.h"
#include "crudHelper.h"
#include <unistd.h>


/**
 * Step 0
 * This routine represent the step 0 aka Start Menu
 */
void startingMenu(){
    // clean the console to give a fresh start wherever we come from (reach this entry-point).
    cleanConsole();
    printf(STR_START_MENU);
    int userAnswer = getNumericAnswerFromUser(2);

    // as per printed enumeration runs the routine based on selected user input
    // even if the following snippet might have been simplified with an if, it haven't been for conformity wih the rest
    switch (userAnswer){
        case newProjectFromScratch:
            cleanConsole();
            newProjectMenu();
            break;
        case editAlreadyExistingProject:
            cleanConsole();
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

    // clean the console for better visualization and asking the user to type a file name and clears again
    cleanConsole();
    selectFile(STR_1_NEW_PROJECT, filePath);
    cleanConsole();

    // redirecting to step 2 (Main Menu)
    mainMenu(filePath, poiData);
}

/**
 *  Step 1.2
 *  This routine lets the user load an existing project,
 *  prompts a list of existing files and then lets the user pick one from the list.
 *  The user is asked to type the name and it will be considered a relative path from the Savings folder
 *  if the user will write a non valid or not existing name the request will be prompted again
 *  https://pubs.opengroup.org/onlinepubs/007904975/functions/access.html
 *
 *  This step will automatically lead to Step 2
 */
void loadProjectMenu(){
    // dynmic vector that will contain the data
    dynamicArray poiData;
    // file path will contain the directory and the file to be written
    char filePath[MEDIUM_STRING];
    // this flag is used to verify if the file input provided by the user exists or not
    _Bool fileExists = false;

    // clean the console for better visualization and asking the user to type a file name and clears again
    cleanConsole();
    // prints a message to tell the user he is going to see the files already present on disk
    printf(STR_1_LOAD_PROJECT_LIST_ALL_FILES);
    // prints the files that are currently stored locally
    printFilesLocallyStored();

    // runs until a valid RELATIVE path is entered
    do{
        // the user is asked to type the project to be loaded and filePath will be containing its path
        selectFile(STR_1_LOAD_PROJECT, filePath);
        // access is a unistd util used to check for the existence of a file, since it returns 0 for success converting
        // to a boolean by this ternary statement:
        fileExists = access(filePath, F_OK) == 0 ? true : false;

        // if the file does not exists print a warning and ask again
        if(!fileExists){
            printf("The file selected does not exists, please type a valid one from the list above:\n");
            printf(STR_CURSOR);
        }
    } while(!fileExists);

    // make some space around to receive the user
    cleanConsole();

    // opening the stream and reading the data inside
    FILE* fileStream = openFile(filePath, "rb");
    leggiDaFileBinario(&poiData, fileStream);

    // redirects to step 2 (Main Menu) and passing data to it
    mainMenu(filePath, poiData);
}

/**
 * Step 2
 * This Routine will route the user to the principal operation that the user will do with this program
 * A list of activities will be printed and the user will be able to call the enumerated subroutines
 * @param filePath
 * @param fileStream
 */
void mainMenu(char* filePath, dynamicArray poiData){
    // declaring and initializing the user's selection
    int userAnswer = -1;

    // this menu will be prompted at the end of each operation until the user will manually decide to go back
    // or press ctrl-c to end the program (it would be safe since at this stage the streams are closed)
    while (userAnswer != mGoback) {
        // prints a message informing the user of the available options
        printf(STR_2_MAIN_MENU);

        // safely getting an answer from the user trough this (magic 6 is the number of available options)
        userAnswer = getNumericAnswerFromUser(6);

        // based on the operation typed run a subroutine
        switch (userAnswer) {
            case mListAll:
                printPoiArray(poiData);
                break;
            case mSearch:
                searchMenuHandler(filePath, poiData);
                break;
            case mInsert:
                insertNewPoi(filePath, &poiData);
                break;
            case mEdit:
                editPoi(filePath, &poiData);
                break;
            case mDelete:
                deletePoi(filePath, &poiData);
                break;
            case mGoback:
                startingMenu();
                break;
            default:
                break;
        }
    }
}

/**
 * Step 3
 *
 * This function prompts the available search options and redirects to the selected one 
 * @param filePath is the current file in use
 * @param poiData is the data currently in use  
 */
void searchMenuHandler(char* filePath, dynamicArray poiData){
    cleanConsole();
    // option selected by the user
    CategoryPoi selectedOption;

    // prompt message
    printf(STR_3_SEARCH_MENU);
    // get selection from user
    selectedOption = getNumericAnswerFromUser(5);

    // redirects the user to the selected type of search to be performed
    // the options are explicated by their enumerated names
    switch (selectedOption){
        case sByCategory:
            searchByCategory(filePath, poiData);
            break;
        case sByMunicipe:
            searchByMunicipe(filePath, poiData);
            break;
        case sByKeyword:
            searchByKeyword(filePath, poiData);
            break;
        case sByGeoLocation:
            searchByGeographicalLocation(filePath, poiData);
            break;
        case sByAltitude:
            searchByAltitude(filePath, poiData);
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
    printf("%s", message);
    // printing the cursor
    printf(STR_CURSOR);

    // read user input spaces included the getChar is intended to free the buffer
    // Todo: find a fancier way to free the buffer
    getchar();
    scanf("%[^\n]", fileName);

    // generating the file path (not only the name)
    generateFilePath(fileName, filePath);
}

