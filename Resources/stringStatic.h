//
// Created by SimonD on 2/3/2020.
// this file contains the static string resources used in the whole project
// it might be useful in order to change the strings in one centralized place and helps in order to avoid
// repeating them directly in the code
//
// Todo: ask if this is a good idea

#ifndef PROGETTOFINALEPOI_STRINGSTATIC_H
#define PROGETTOFINALEPOI_STRINGSTATIC_H

#define STR_INVALID_INPUT_WARNING "please enter a valid input\n"
#define STR_CURSOR "__>"
#define STR_START_MENU "Welcome to Point Of Interest Handler, please chose an option\n\
0. New Project\n\
1. Load existing project\n"

#define STR_1_NEW_PROJECT "Type the project name you want to create\n"

#define STR_1_LOAD_PROJECT "Type the project name you want to load:\n"
#define STR_1_LOAD_PROJECT_LIST_ALL_FILES "Here is the list of the projects in your local storage: "

#define STR_2_MAIN_MENU "Type the operation number you want to perform:\n\
0. List All\n1. Search\n2. Insert New\n3. Edit an already existing\n4. Delete an already existing\n5. Go back Home\n"

#define STR_3_SEARCH_MENU "Type the type of search you want to perform:\
\n0. By Category\n1. By Municipe\n2. By Keyword\n3. By Geographical location\n4. By Altitude"

#define STR_INSERT_HOME "Welcome to guided point of interest insertion,\
 please type attribute by attribute the requested information\n"

#define STR_LIST_CATEGORIES_ENUM "Type the Category number:\
\n0. beach\n1. Mountain\n2. Park\n3. Lake\n4. Cave\n5. Museum\n6. ViewPoint\n7.Other\n"

#define STR_SAVE_WARNING "Do you want to save the modifications made to file?\
\nWarning: eventual modifications done previously will also be saved\ndo you want to proceed? (Y/N)\n"

#define STR_NO_DATA_AVAILABLE "There is no data to be shown\n"

#define STR_EDIT_POI_MENU "\nType the number corresponding to the desired field you want to to edit\n0. Name\n1. Latitude\n2. Longitude\n3. Altitude\n4. Municipality\n5. Description\n6. Category\n"

#endif //PROGETTOFINALEPOI_STRINGSTATIC_H
