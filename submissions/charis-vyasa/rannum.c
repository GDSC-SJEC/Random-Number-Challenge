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
        if ( (score == 1000 && difficulty == 'E') || (score == 10000 && difficulty == 'H') || (score == 1500 && difficulty == 'M')){
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

/*short medium(){
    short score = 1000, i, guess, difference;
    int secret;
    char temp[20];
    short prime[140] =   {101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179
                   ,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269
                   ,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367
                   ,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461
                   ,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571
                   ,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661
                   ,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773
                   ,787,797,809,811,821,823,827,829,839,853,857,859,863,877,881,883
                   ,887,907,911,919,929,937,941,947,953,967,971};
    printf("======MEDIUM=MODE=====\n");
    printf("Type a number between 1 and 140");
    printf("Hint: Press 'q' to quit.\n");
    printf("Number: ");
    scanf("%s", temp);
    if (temp[0] == 'q')
        exit(0);
    if (!atoi(temp)){
        printf("Not a number!\n");
        exit(0);
    }
    i = atoi(temp);
    secret = prime[i];*/

short primegen() {
    short secret;
    short counter;
    do {
    secret = rand() % 1000 + 1;
    counter = 0;
    for(int i = 1; i <= secret; i++ )
        if(!(secret % i)) counter++;        
    }
    while(counter != 2);
    return secret;
}
    



short medium(){
    short secret = primegen();
    short score = 1500, guess, difference, counts;
    char temp[20];
    printf("======MEDIUM=MODE=====\n");
    printf("Hint: Guess the number between 1 and 1000 (inclusive).\n");
    printf("Hint: Press 'q' to quit.\n");
    while(score){
        counts++;
        printf("Guess: ");
        scanf("%s", temp);
        if (temp[0] == 'q')
            exit(0);
        if (!atoi(temp)){
            printf("Not a number!\n");
            continue;
        }
        guess = atoi(temp);
        //hint
        if (counts == 10) 
            printf("Hint: Number is prime");
            
        // Checking and reducing score
        if (guess == secret){
            return score;
        }
        else {
            difference = abs(secret - guess);

            // Affect score negatively
            score -= 2.28 * difference;
            if (score > 0){
                // Hint messages
                if (difference <= 25)
                    printf(">>> Score %i\n>>> Super Hot!\n", score);
                else if (difference <= 50)
                    printf(">>> Score %i\n>>> Mildly Hot!\n", score);
                else if (difference <= 100)
                    printf(">>> Score %i\n>>> Moderately Cold!\n", score);
                else
                    printf(">>> Score %i\n>>> Super Cold!\n", score);
            }
            else{
                return -1;
            }
        }
    }
return score;    
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
        if (counter == 10){
            printf("Hint: Try guessing the number using the binary search technique!\n");
            printf("Hint: It is between %i and %i (inclusive).\n", range_offset + 1, range_offset + range);
        }
        if (counter == 25){
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
