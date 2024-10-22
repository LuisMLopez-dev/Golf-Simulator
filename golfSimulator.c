//Header Files
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "golfClubs.h"

//Macros used to alter the color of text
#define COLOR_BOLD "\e[1m"
#define COLOR_OFF "\e[m"

//Global Variables
int swingsTaken = 0;
int distanceTraveledByBall = 0;

//Function Prototypes
bool holes(int swingDistance, int holeLocation, int par);
void distanceTraveled(int swingDistance, int holeLocation);
bool inHole(int holeLocation, int par);
bool maxStrokes(int par);
void getScore(int par);
void finalScore(int courseScore, bool print);
void resetGlobalVariables(void);

//Main Function
int main(void){
    int userChoice, swingDistance = 0; 
    int holeNumber = 1;
    int currentParOfHole = 3;
    bool inHole = false;
    
    //An array of pointers to functions; the functions are the golf clubs functions in golfClubs.h
    int (*ptrClubs[8])(void) = {putter, wedge, nineIron, sevenIron, fiveIron, threeIron, threeWood, driver};
    //Randomizes the seeds that are used to select random values for the ranges of each golf club
    srand(time(NULL)); 

    printf(COLOR_BOLD "Welcome to Golf Simulator for beginners!\n\n" COLOR_OFF);
    holesInfo();
    printf(COLOR_BOLD "\nNote: This information will be displayed again upon completion of each hole!\n" COLOR_OFF);

    //Loops through each hole
    while(holeNumber < 5){
        //Checks to see if user went over the max amount of strokes within the main function
        if(maxStrokes(currentParOfHole) && !inHole){
            holeNumber++;
            resetGlobalVariables();

            if(holeNumber == 5){
                break;
            }
        }

        //Asks the user to pick a club
        if(!inHole){
            clubsInfo();
            do{
                printf("\nPlease input the corresponding number for the club you want to select: ");
                scanf("%d", &userChoice);
            }while(userChoice < 0 || userChoice > 7);
            puts("");
            swingDistance = (*ptrClubs[userChoice])();
        }

        if(!inHole){ //If the ball is not in the hole, increase swings by one, and pass the information of the current hole to functions
            switch(holeNumber){
            case 1:
                swingsTaken++;
                inHole = holes(swingDistance, 300, currentParOfHole); //First Hole
                break;

            case 2:
                swingsTaken++;
                currentParOfHole = 4;
                inHole = holes(swingDistance, 500, currentParOfHole); //Second Hole
                break;

            case 3:
                swingsTaken++;
                currentParOfHole = 3;
                inHole = holes(swingDistance, 200, currentParOfHole); //Third Hole
                break;

            case 4:
                swingsTaken++;
                currentParOfHole = 5;
                inHole = holes(swingDistance, 700, currentParOfHole); //Fourth Hole
                break;
            }
        }
        else if(inHole){ //If the ball is in the hole, change the hole number and par to the next one, as well as reset the global variables using functions
            switch(holeNumber){
            case 1:
                holeNumber = 2;
                inHole = false;
                resetGlobalVariables();
                holesInfo();
                puts("");
                break;
                
            case 2:
                holeNumber = 3;
                inHole = false;
                resetGlobalVariables();
                holesInfo();
                puts("");
                break;

            case 3:
                holeNumber = 4;
                inHole = false;
                resetGlobalVariables();
                holesInfo();
                puts("");
                break;

            case 4:
                holeNumber = 5;
                break;
            }
        }
    }
    finalScore(0, true); //0 is passed to not add anything to the final score, and true is passed to signify the end of the game
    printf("Thanks for playing!\n");
    return 0;
}

//Prints the number of strokes and the distance the ball traveled due to the swing for each hole.
bool holes(int swingDistance, int holeLocation, int par){
    printf(COLOR_BOLD"\nStroke: %d\nThe golf ball traveled %d yards\n", swingsTaken, swingDistance); 
    printf(COLOR_OFF);
    distanceTraveled(swingDistance, holeLocation);
    return inHole(holeLocation, par); //Calls inHole functions to return a boolean value to determine if the ball is in the hole
}

//Obtains the total distance the ball has traveled in relation to the hole position
void distanceTraveled(int swingDistance, int holeLocation){
    if(distanceTraveledByBall < holeLocation){
        distanceTraveledByBall += swingDistance;
    }

    else{
        distanceTraveledByBall -= swingDistance;
    }
}

//Determines if the ball is in the hole. If not, then how far the ball is from the hole
bool inHole(int holeLocation, int par){    
    if(distanceTraveledByBall < holeLocation){ 
        printf(COLOR_BOLD "You are %d yard(s) away from the hole\n", holeLocation - distanceTraveledByBall);
        printf(COLOR_OFF);
        return false;
    }

    if(distanceTraveledByBall > holeLocation){
        printf(COLOR_BOLD "You are %d yard(s) away from the hole\n", distanceTraveledByBall - holeLocation);
        printf(COLOR_OFF);
        return false;
    }

    if(distanceTraveledByBall == holeLocation){
        printf(COLOR_BOLD "\nThe golf ball went into the hole!\n");
        printf("Good job!\n\n" COLOR_OFF);
        getScore(par);
        return true;
    }
    return false;
}

//Checks if the user has swung too many times for the current hole. If so, obtains and prints the score for the current hole
bool maxStrokes(int par){
    if(swingsTaken == (par + 5)){
        getScore(par);
        printf(COLOR_BOLD "YOU HAVE REACHED MAX STROKES ON THIS HOLE.\nBEGINNING NEXT HOLE:\n\n\n" COLOR_OFF);
        return true;
    }
    return false;
}

//Obtains and prints the score for the current hole
void getScore(int par){
    int courseScore = swingsTaken - par;
    printf(COLOR_BOLD "Your score for this course is %d\n\n", courseScore);
    printf(COLOR_OFF);
    finalScore(courseScore, false); //finalScore is called to add the current score to the finalScore, and false is passed to not print the final score
}

//Sums the scores for each course to print the final score
void finalScore(int courseScore, bool print){
    static int finalScore;
    finalScore += courseScore;

    if(print){
        printf(COLOR_BOLD "Your final score is: %d\n", finalScore);
        printf(COLOR_OFF);
    }
}

//Helper function for the global variables
void resetGlobalVariables(void){ 
    swingsTaken = 0;
    distanceTraveledByBall = 0;
}
