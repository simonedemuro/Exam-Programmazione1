//
// Created by SimonD on 2/3/2020.
//

#include <stdlib.h> // used to call system calls
#include <time.h>
#include "userInterfaceUtils.h"
#include "../../Routines/applicationSteps.h"
#include "../../Routines/searchHelper.h"

/**
 * This function provides a fast and higly reusable way to get the the input from the user.
 * This function is used as a standard way to ask for a numeric input in the whole project
 * @param maxOptionAvailable represents the Maximum included enumeration number selectable by the user
 * @return returns a valid enumeration from the user input (between 0 and maxOptionAvailable)
 */
int getNumericAnswerFromUser(int maxOptionAvailable){
    int userAnswer = -1;
    _Bool invalidInputEntered;

    // Asks for an option until it gets entered correctly
    do {
        printf(STR_CURSOR);
        scanf("%d", &userAnswer);
        freeTheBuffer();

        // checks if the value is between 1 and the maximum option available for this command
        invalidInputEntered = userAnswer < 0 || userAnswer > maxOptionAvailable;
        if(invalidInputEntered){
            printf(STR_INVALID_INPUT_WARNING);
        }
    } while(invalidInputEntered);
    //than returns a certainly valid input
    return userAnswer;
}


/**
 * This function helps to get a valid latitude from the user (between MIN_SARDINIAN_LATITUDE, MAX_SARDINIAN_LATITUDE)
 * and prints a hint in case the user inadvisedly inserts a wrong Latitude
 *
 * @return a valid Sardinian DOC latitude
 */
double getLatitudeAnswerFromUser(){
    double userAnswer = -1;
    _Bool isSardinianLatitude;

    // Asks for an option until it gets entered correctly
    do {
        printf(STR_CURSOR);
        scanf("%lf", &userAnswer);
        freeTheBuffer();
        // checks if the value is between 1 and the maximum option available for this command
        isSardinianLatitude = (userAnswer >= MIN_SARDINIAN_LATITUDE && userAnswer <= MAX_SARDINIAN_LATITUDE);

        if(!isSardinianLatitude){
            printf("The longitude you entered does not belong to Sardinia, please enter a value between %f and %f",
                    MIN_SARDINIAN_LATITUDE, MAX_SARDINIAN_LATITUDE);
        }
    } while(!isSardinianLatitude);
    //than returns a certainly valid input
    return userAnswer;
}

/**
 * This function helps to get a valid Longitude from the user (between  MIN_SARDINIAN_LONGITUDE, MAX_SARDINIAN_LONGITUDE)
 * and prints a hint in case the user inadvisedly inserts a wrong Longitude
 *
 * @return a valid Sardinian DOC Longitude
 */
double getLongitudeAnswerFromUser(){
    double userAnswer = -1;
    _Bool isSardinianLingitude;

    // Asks for an option until it gets entered correctly
    do {
        printf(STR_CURSOR);
        scanf("%lf", &userAnswer);
        freeTheBuffer();
        // checks if the value is between 1 and the maximum option available for this command
        isSardinianLingitude = (userAnswer >= MIN_SARDINIAN_LONGITUDE && userAnswer <= MAX_SARDINIAN_LONGITUDE);

        if(!isSardinianLingitude){
            printf("The longitude you entered does not belong to Sardinia, please enter a value between %f and %f",
                   MIN_SARDINIAN_LONGITUDE, MAX_SARDINIAN_LONGITUDE);
        }
    } while(!isSardinianLingitude);
    //than returns a certainly valid input
    return userAnswer;
}

/**
 *  This function provides a fast and higly reusable way to get the the input from the user.
 *  This function is used as a standard way to ask for <YES/NO> input in the whole project
 * @return converts the user answer to a boolean
 */
_Bool getYesNoAnswerFromUser(){
    // variable to hold the answer, and two flags to check resp. the input validity and the result
    char c;
    _Bool isInputValid = false;
    _Bool result = false;

    // until the user types something valid
    do {
        // prints the cursor and wait for an input from the user
        printf(STR_CURSOR);
        scanf("%c", &c);
        freeTheBuffer();

        /*converting the letter to boolean*/
        // yes leads to true
        if (c == 'y' || c == 'Y'){
            isInputValid = true;
            result = true;
        }
        // no leads to false
        else if (c == 'N' || c == 'n') {
            isInputValid = true;
            result = false;
        }
    } while (!isInputValid);

    return result;
}


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

    // Dealy of 150 Milli seconds to avoid weird behavior with the Clion console that seems to perform
    // system calls asynchronously

    clock_t startTime = clock();
    // looping till required time is not achieved
    while (clock() < startTime + 150 )
        ;
}

/**
 * This Routine prints the file present on the disk in order to make easier for the user to pick a file
 * This Routin makes use of a system call based on the OS currently in use at compile time
 */
void printFilesLocallyStored(){
    char command[100];

    // set the correct syscall for the os in use by copying a string into the command that will be sent to OS
#ifdef __linux__
    strcpy(command, "ls ");
#elif _WIN32
    strcpy(command, "DIR ");
#else
    // otherwise we are under mac or smething misterious like a BSD
    strcpy(command, "ls ");
#endif

    // passes the saving path to the command as an argument
    strcat(command, CONF_WORKING_PATH_FOLDER_NAME);

    // the command just sent to the os will be prompted to make it more transparent
    printf("\n");
    printf("%s", command);
    printf("\n");
    // runs the system command (DIR under windows or ls under linux and Mac)
    // the effect in both will be to print a list of the available file on the save folder.
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

/**
 * Usage: put this function after scanf so that the next one will have a clean stream
 * in particular the invisible enemies.. the "\n"
 */
void freeTheBuffer(){
    while ( getchar() != '\n' );
}