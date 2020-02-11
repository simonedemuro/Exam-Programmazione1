cmake_minimum_required(VERSION 3.15)
project(ProgettoFinalePOI C)

set(CMAKE_C_STANDARD 90)

add_executable(ProgettoFinalePOI main.c Utils/UI/userInterfaceUtils.c Utils/UI/userInterfaceUtils.h Resources/stringStatic.h Model/structures.h Routines/applicationSteps.c Routines/applicationSteps.h Repository/pointOfInterestBinaryFileRepository.c Repository/pointOfInterestBinaryFileRepository.h Utils/DynamicArray/dynamicArray.c Utils/DynamicArray/dynamicArray.h Routines/searchHelper.c Routines/searchHelper.h Routines/crudHelper.c Routines/crudHelper.h Routines/sortHelper.c Routines/sortHelper.h Repository/pointOfInterestTextFileRepository.c Repository/pointOfInterestTextFileRepository.h)