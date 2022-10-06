#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

short easy();
short medium();
short hard();

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
    int score;
    char difficulty;
    printf("Choose difficulty: Easy | Medium | Hard\n");
    while(1){
        printf("(E/M/H): ");
        scanf("\n%c", &difficulty);
        difficulty = toupper(difficulty);
        if (difficulty == 'E'){
            score = easy();
            break;
        }
        if (difficulty == 'M'){
            score = medium();
            break;
        }
        if (difficulty == 'H'){
            score = hard();
            break;
        }
    }

    // Printing results
    if (score > 0){

        // Got it on the first try!
        if ( (score == 1000 && difficulty == 'E') || (score == 10000 && difficulty == 'H')){
            printf("\n##########\nYou got it on the first try! %s!\n", name);
            printf("Your score is %i\n#########\n\n", score);
            goto printscore;
        }

        // Default results
        printf("\n##########\nGreat job %s!\n", name);
        printf("Your score is %i\n#########\n\n", score);
        
        // Update scores.csv
        printscore:
        if (scores_opened){
            fprintf(scores, "\"%s\",\"%c\",%i\n", name, difficulty, score);
        }
    }
    else{
        printf("Try again!\n");
    }

    // Closing this
    fclose(scores);
    return 0;
}

short easy(){
    short secret = rand() % 100 + 1;
    short score = 1000, guess, difference;
    char temp[20];
    printf("======EASY=MODE=====\n");
    printf("Hint: Guess the number between 1 and 100 (inclusive).\n");
    printf("Hint: Press 'q' to quit.\n");
    while(score){
        printf("Guess: ");
        scanf("%s", temp);
        if (tolower(temp[0]) == 'q'){
            exit(0);
        }
        if (!atoi(temp)){
            printf("Not a number!\n");
            continue;
        }
        guess = atoi(temp);
        if (guess < 1 || guess > 100){
            printf("Not in range!\n");
            continue;
        }
        // Checking and reducing score
        if (guess == secret){
            return score;
        }
        else{
            difference = abs(secret - guess);
            // Affect score negatively
            score -= 6.28 * difference;
            if (score > 0){
                // Hint messages
                if (difference <= 10)
                    printf(">>> Score %i\n>>> Super Hot!\n", score);
                else if (difference <= 25)
                    printf(">>> Score %i\n>>> Mildly Hot!\n", score);
                else if (difference <= 50)
                    printf(">>> Score %i\n>>> Moderately Cold!\n", score);
                else
                    printf(">>> Score %i\n>>> Super Cold!\n", score);
            }
            else{
                return -1;
            }
        }
    }
}

short medium(){
    // Starting score can be 2000 to guess between 1 and 250 (inclusive).
    printf("Under construction\n");
    exit(0);
}

short hard(){
    short range_offset = rand() % 10000 + 1;
    short range = rand() % 1234 + 1024;
    short secret = (rand() % range + 1) + range_offset;
    short score = 10000, guess, difference, counter = 0;
    float deviation;
    char temp[20];
    printf("======HARD=MODE=====\n");
    printf("Hint: Guess the number between %i and %i (inclusive).\n", range_offset + 1, range_offset + range);
    printf("Hint: Press 'q' to quit.\n");
    printf("Hint: Press 'r' to see the range again.\n");
    while(score){
        if (counter = 10){
            printf("Hint: Try guessing the number using the binary search technique!\n");
            printf("Hint: It is between %i and %i (inclusive).\n", range_offset + 1, range_offset + range);
        }
        if (counter = 25){
            printf("Hint: Your guess is \"Super Hot!\" when you are within 2%% of the answer\n");
        }
        printf("Guess: ");
        scanf("%s", temp);
        if (tolower(temp[0] == 'q')){
            exit(0);
        }
        if (tolower(temp[0]) == 'r'){
            printf("The number is between %i and %i (inclusive).\n", range_offset + 1, range_offset + range);
            continue;
        }
        if (!atoi(temp)){
            printf("Not a number!\n");
            continue;
        }
        guess = atoi(temp);
        if (guess < range_offset + 1 || guess > range_offset + range){
            printf("Not in range!\n");
            continue;
        }
        // Checking and reducing score
        counter++;
        if (guess == secret){
            return score;
        }
        else{
            difference = abs(secret - guess);
            deviation = (float) guess / secret;
            // Affect score negatively
            score -= deviation * difference;
            if (score > 0){
                // Hint messages
                if (deviation < 1.002 && deviation > 0.998)
                    printf(">>> Score %i\n>>> Super Hot!\n", score);
                else if (deviation < 1.01 && deviation > 0.99)
                    printf(">>> Score %i\n>>> Mildly Hot!\n", score);
                else if (deviation < 1.02 && deviation > 0.98)
                    printf(">>> Score %i\n>>> Moderately Cold!\n", score);
                else 
                    printf(">>> Score %i\n>>> Super Cold!\n", score);
            }
            else{
                return -1;
            }
        }
    }
}
