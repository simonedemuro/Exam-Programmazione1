//
// Created by SimonD on 2/5/2020.
//

#include "applicationSteps.h"


/**
 * Step 0
 * This routine represent the step 0 aka Start Menu
 */
void startingMenu(){
    printf(STR_MAIN_MENU);
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
    // clean the console for better visualization
    cleanConsole();
    // Ask the file name
    FILE* fileStream = printMessageAndOpenStream(STR_1_NEW_PROJECT);
}

/**
 *  Step 1.2
 *  This routine lets the user load an existing project,
 *  prompts a list of existing files and then lets the user pick one.
 *
 *  This step will automatically lead to Step 2
 */
void loadProjectMenu(){
    printf(STR_1_LOAD_PROJECT_LIST_ALL_FILES);
    printFilesLocallyStored();
    FILE* fileStream = printMessageAndOpenStream(STR_1_LOAD_PROJECT);
}

void mainMenu(char* fileName, FILE* fileStream){
    printf("-.m,òplnb3");
}

/**
 * Since new project and load project are very similar, this function provides a common template to avoid
 * code repetitions.
 * @param message is the message is gonna be prompted to user
 * @return the pointer to the file typed by the user
 */
FILE* printMessageAndOpenStream(char* message){
    // declaring the variable to hold the fileName that will be generated
    char fileName[SHORT_STRING];
    // prompt the awareness message asking for the filename
    printf(STR_1_NEW_PROJECT);

    // read user input spaces included the getChar is intended to free the buffer
    // Todo: find a fancier way to free the buffer
    getchar();
    scanf("%[^\n]", fileName);
    // opens a stream to the file
    FILE * fileStream = openStream(fileName);
    return fileStream;
}

