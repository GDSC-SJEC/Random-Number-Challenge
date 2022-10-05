#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

short easy();
void medium();
void hard();

int main(){
    
    // Seeding the random number generator
    srand(time(NULL));

    // Keeping track of scores in a file
    bool scores_opened = true;
    FILE *scores = fopen("scores.csv","a+");
    if (scores == NULL){
        scores_opened = false;
    }
    
    // Reading player name
    char name[25];
    printf("Enter your playername: ");
    scanf("%[^\n]%*c", name);

    // Setting Difficulty
    printf("Choose difficulty: Easy | Medium | Hard\n");
    while(1){
        printf("(E/M/H): ");
        char difficulty;
        scanf("\n%c", &difficulty);
        difficulty = toupper(difficulty);
        if (difficulty == 'E'){
            easy();
            break;
        }
        if (difficulty == 'M'){
            medium();
            break;
        }
        if (difficulty == 'H'){
            hard();
            break;
        }
    }

    fclose(scores);
    return 0;
}

short easy(){
    short secret = rand() % 250 + 1;
    short score = 1000, guess;
    char temp[20]; 
    printf("Hint: Guess a number between 1 and 250 (inclusive).\n");
    printf("Hint: Press 'q' to quit.\n");
    while(score){
        scanf("%s", temp);
        if (temp[0] == 'q')
            exit(0);
        if (!atoi(temp)){
            printf("Not a number!\n");
            continue;
        }
        guess = atoi(temp);
        // Checking and reducing score
    }
    return score;
}

void medium(){
    return;
}

void hard(){
    return;
}
