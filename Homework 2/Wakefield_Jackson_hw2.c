#include<stdio.h>

int main(){

    start();
    return 0;
}

void start(){
    int valid = -1; // 0 = valid character, -1 = invalid character
    //while(valid == -1){
        //valid = menu(); // sets to -1 if invalid, user-option if valid

        //gameManager();
    valid = RandomInRange(5, 10);
    printf("%d", valid);
    //}    

    
}

//controls main menu
int menu(){
    int decision = -1;

    printf("Welcome to the CSE240 Assignment 2! \n Menu: \n");
    printf("1 - CSE240 Mini-Game Collection\n");
    printf("2 - Macros vs Functions Throw-down\n");
    printf("0 - Exit\n");
    printf("Choose an option: ");
    scanf("%d", &decision);

    //invalid case, run the loop
    if(decision < 0 && decision > 2){
        return -1;
    }

    return decision;
}

void gameManager(){

    
    int numRounds = -1;

    //first loop, controls input
    while(numRounds == -1){
        printf("How many rounds should we play? (Choose an odd number) \n");

        scanf("%d", &numRounds);
        //loop again if invalid input
        if(isEven(numRounds) == 0 || numRounds < 1){
            numRounds = -1;
        }
    }
    

    

    //-loop until the number of rounds is 0
    while(numRounds > 0){
        int decision = 0;
        switch(decision){
            case 1:
                evensOrOdds();
            break;
            case 2:
                printf("not done yet");
            break;
        }
        numRounds = numRounds -1;
    }
}

void evensOrOdds(){
    printf("success!");
}

//for simplicity returns 0 for even, 1 for odd instead
int isEven(int number){
    return (number % 2);
}

int RandomInRange(int min, int max){
    return ((rand() % max) - min);
}