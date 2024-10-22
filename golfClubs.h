//Header Files
#include <stdio.h>
#include <stdlib.h>

//Prints the info for the clubs
void clubsInfo(void){
    const char *clubs[] = {
        "0 --> Putter(max. 25yd)", 
        "1 --> Wedge(max. 35yd)", 
        "2 --> 9 Iron(max. 71yd)", 
        "3 --> 7 Iron(max. 108yd)", 
        "4 --> 5 Iron(max. 145yd)", 
        "5 --> 3 Iron(max. 182yd)", 
        "6 --> 3 Wood(max. 219yd)", 
        "7 --> Driver(max. 255yd)"
    };

    int numClubs = sizeof(clubs) / sizeof(clubs[0]);
    for(int i = 0; i < numClubs; i++){
        printf("%s\n", clubs[i]);
    }
}

//Prints the info for the holes
void holesInfo(void){
        const char *holes[] = {
        "HOLE INFORMATION:", 
        "Hole One: Hole Location: 300 yards Par: 3",
        "Hole Two: Hole Location: 500 yards Par: 4", 
        "Hole Three: Hole Location: 200 yards Par: 3", 
        "Hole Four: Hole Location: 700 yards Par: 5"
    };

    int numHoles = sizeof(holes) / sizeof(holes[0]);
    for(int i = 0; i < numHoles; i++){
        printf("%s\n", holes[i]);
    }
}

/* Comments for the functions below:
1. The following functions below use randomized seeds to obtain the swing values.
2. Each function is for a specific club, and each club has a range for the swing values.
3. These clubs have strength settings to split the total range, into smaller subranges for the swing values.
4. In total there are 8 clubs, and the total range is between 1-255 yards.
*/

int putter(void){
    int userNumber;
    int swingValue;
    const char *putter[] = {
        "Specify the strength of your swing:\n",
        "1 --> Very Light (1 - 2yd)\n",
        "2 --> Light (3 - 5yd)\n",
        "3 -- > Medium (6 - 10yd)\n",
        "4 --> Hard (11 - 16yd)\n",
        "5 --> Very Hard (17 - 25yd)\n\n"
    };

    int putterStrength = sizeof(putter) / sizeof(putter[0]);
    for(int i = 0; i < putterStrength; i++){
        printf("%s\n", putter[i]);
    }

    do{
        printf("\nEnter one of the numbers listed\nYour number: ");
        scanf("%d", &userNumber);
    }while(userNumber < 1 || userNumber > 5);

    switch(userNumber){
        case 1:
            swingValue = 1 + (rand() % 2);
            break;

        case 2:
            swingValue = 3 + (rand() % 3);
            break;

        case 3:
            swingValue = 6 + (rand() % 5);
            break;

        case 4:
            swingValue = 11 + (rand() % 6);
            break;

        case 5:
            swingValue = 17 + (rand() % 9);
            break;
    }
    return swingValue;
}

int wedge(void){
    int userNumber;
    int swingValue;
    const char *wedge[] = {
    "Specify the strength of your swing:\n",
    "1 --> Light (3 - 13yd)\n",
    "2 -- > Medium (14 - 24yd)\n",
    "3 --> Hard (25 - 35yd)\n"
    };

    int wedgeStrength = sizeof(wedge) / sizeof(wedge[0]);
    for(int i = 0; i < wedgeStrength; i++){
        printf("%s\n", wedge[i]);
    }
    
    do{
        printf("\nEnter one of the numbers listed\nYour number: ");
        scanf("%d", &userNumber);
    }while(userNumber < 1 || userNumber > 3);

    switch(userNumber){
        case 1:
            swingValue = 3 + (rand() % 11);
            break;

        case 2:
            swingValue = 14 + (rand() % 11);
            break;

        case 3:
            swingValue = 25 + (rand() % 11);
            break;
    }
    return swingValue;
}

int nineIron(void){
    int userNumber;
    int swingValue;
    const char *nineIron[] = {
        "Specify the strength of your swing:\n",
        "1 --> Light (35 - 47yd)\n",
        "2 -- > Medium (47 - 59yd)\n",
        "3 --> Hard (59 - 71yd)\n"
    };

    int nineIronStrength = sizeof(nineIron) / sizeof(nineIron[0]);
    for(int i = 0; i < nineIronStrength; i++){
        printf("%s\n", nineIron[i]);
    }
    
    do{
        printf("\nEnter one of the numbers listed\nYour number: ");
        scanf("%d", &userNumber);
    }while(userNumber < 1 || userNumber > 3);

    switch(userNumber){
        case 1:
            swingValue = 35 + (rand() % 13);
            break;

        case 2:
            swingValue = 47 + (rand() % 13);
            break;

        case 3:
            swingValue = 59 + (rand() % 13);
            break;
    }
    return swingValue;
}

int sevenIron(void){
    int userNumber;
    int swingValue;
    const char *sevenIron[] = {
        "Specify the strength of your swing:\n",
        "1 --> Light (72 - 84yd)\n",
        "2 -- > Medium (84 - 96yd)\n",
        "3 --> Hard (96 - 108yd)\n"
    };

    int sevenIronStrength = sizeof(sevenIron) / sizeof(sevenIron[0]);
    for(int i = 0; i < sevenIronStrength; i++){
        printf("%s\n", sevenIron[i]);
    }

    do{
        printf("\nEnter one of the numbers listed\nYour number: ");
        scanf("%d", &userNumber);
    }while(userNumber < 1 || userNumber > 3);

    switch(userNumber){
        case 1:
            swingValue = 72 + (rand() % 13);
            break;

        case 2:
            swingValue = 84 + (rand() % 13);
            break;

        case 3:
            swingValue = 96 + (rand() % 13);
            break;
    }
    return swingValue;
}

int fiveIron(void){
    int userNumber;
    int swingValue;
    const char *fiveIron[] = {
        "Specify the strength of your swing:\n",
        "1 --> Light (109 - 121yd)\n",
        "2 -- > Medium (121 - 133yd)\n",
        "3 --> Hard (133 - 145yd)\n"
    };

    int fiveIronStrength = sizeof(fiveIron) / sizeof(fiveIron[0]);
    for(int i = 0; i < fiveIronStrength; i++){
        printf("%s\n", fiveIron[i]);
    }
    
    do{
        printf("\nEnter one of the numbers listed\nYour number: ");
        scanf("%d", &userNumber);
    }while(userNumber < 1 || userNumber > 3);

    switch(userNumber){
        case 1:
            swingValue = 109 + (rand() % 13);
            break;

        case 2:
            swingValue = 121 + (rand() % 13);
            break;

        case 3:
            swingValue = 133 + (rand() % 13);
            break;
    }
    return swingValue;
}

int threeIron(void){
    int userNumber;
    int swingValue;
    const char *threeIron[] = {
        "Specify the strength of your swing:\n",
        "1 --> Light (146 - 158yd)\n",
        "2 -- > Medium (158 - 170yd)\n",
        "3 --> Hard (170 - 182yd)\n"
    };

    int threeIronStrength = sizeof(threeIron) / sizeof(threeIron[0]);
    for(int i = 0; i < threeIronStrength; i++){
        printf("%s\n", threeIron[i]);
    }
    
    do{
        printf("\nEnter one of the numbers listed\nYour number: ");
        scanf("%d", &userNumber);
    }while(userNumber < 1 || userNumber > 3);

    switch(userNumber){
        case 1:
            swingValue = 146 + (rand() % 13);
            break;

        case 2:
            swingValue = 158 + (rand() % 13);
            break;

        case 3:
            swingValue = 170 + (rand() % 13);
            break;
    }
    return swingValue;
}

int threeWood(void){
    int userNumber;
    int swingValue;
    const char *threeWood[] = {
        "Specify the strength of your swing:\n",
        "1 --> Light (183 - 195yd)\n",
        "2 -- > Medium (195 - 207yd)\n",
        "3 --> Hard (207 - 219yd)\n"
    };

    int threeWoodStrength = sizeof(threeWood) / sizeof(threeWood[0]);
    for(int i = 0; i < threeWoodStrength; i++){
        printf("%s\n", threeWood[i]);
    }
    
    do{
        printf("\nEnter one of the numbers listed\nYour number: ");
        scanf("%d", &userNumber);
    }while(userNumber < 1 || userNumber > 3);

    switch(userNumber){
        case 1:
            swingValue = 183 + (rand() % 13);
            break;

        case 2:
            swingValue = 195 + (rand() % 13);
            break;

        case 3:
            swingValue = 207 + (rand() % 13);
            break;
    }
    return swingValue;
}

int driver(void){
    int userNumber;
    int swingValue;
    const char *driver[] = {
        "Specify the strength of your swing:\n",
        "1 --> Light (220 - 232yd)\n",
        "2 -- > Medium (232 - 244yd)\n",
        "3 --> Hard (244 - 255y)"
    };

    int driverStrength = sizeof(driver) / sizeof(driver[0]);
    for(int i = 0; i < driverStrength; i++){
        printf("%s\n", driver[i]);
    }
    
    do{
        printf("\nEnter one of the numbers listed\nYour number: ");
        scanf("%d", &userNumber);
    }while(userNumber < 1 || userNumber > 3);

    switch(userNumber){
        case 1:
            swingValue = 220 + (rand() % 13);
            break;

        case 2:
            swingValue = 232 + (rand() % 13);
            break;

        case 3:
            swingValue = 244 + (rand() % 12);
            break;
    }
    return swingValue;
}
