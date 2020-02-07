//
// Created by SimonD on 2/3/2020.
//

#include <stdlib.h> // used to call system calls
#include "userInterfaceUtils.h"
#include "../../Routines/applicationSteps.h"

/**
 * This function provides a fast and higly reusable way to get the the input from the user.
 * This function is used as a standard way to ask for an input in the whole project
 * @param maxOptionAvailable represents the Maximum included enumeration number selectable by the user
 * @return returns a valid enumeration from the user input (between 0 and maxOptionAvailable)
 */
int getAnswerFromUser(int maxOptionAvailable){
    int userAnswer = -1; //Todo: ask if it might be changed to unsigned int
    _Bool invalidInputEntered;

    // Asks for an option until it gets entered correctly
    do {
        printf(STR_CURSOR);
        scanf("%d", &userAnswer);
        // checks if the value is between 1 and the maximum option available for this command
        invalidInputEntered = userAnswer < 0 || userAnswer > maxOptionAvailable;
        if(invalidInputEntered){
            printf(STR_INVALID_INPUT_WARNING);
        }
    } while(invalidInputEntered);
    //than returns a certainly valid input
    return userAnswer;
}


//Todo: refactor this mess and conditionally compile the functions you want to have depending on the operative system
//instead of repeating the condition inside them

/**
 * Clear the console with the right system call based on the OS currently in use at compile time
 */
void cleanConsole(){
    // see https://stackoverflow.com/questions/6649936/c-compiling-on-windows-and-linux-ifdef-switch
    //pick the right command based on the os under use
#ifdef __linux__
    system("clear ");
#elif _WIN32
    system("cls");
#else
    // otherwise we are under mac
    // https://stackoverflow.com/questions/2198377/how-to-clear-previous-output-in-terminal-in-mac-os-x
    system("clear");
#endif
}

/**
 *
 */
void printFilesLocallyStored(){
    char command[100];

    // set the correct syscall for the os in use
#ifdef __linux__
    strcpy(command, "ls ");
#elif _WIN32
    strcpy(command, "DIR ");
#else
    // todo: not sure how to list on mac
    // otherwise we are under mac
    strcpy(command, "ls ");
#endif

    // passes the saving path to the command as an argument
    strcat(command, CONF_WORKING_PATH_FOLDER_NAME);

    printf(command);
    // runs the system command
    system(command);
}


/**
 *  This function prints a message to inform the user that the worst happened and kindly invites the user to
 *  run the application again from the entry point
 */
void handledError(){
    cleanConsole();
    printf("An Error or unexpected condition happened, please press a key to restart the application, if the error persists contact the support");
    getchar();
    startingMenu();
}