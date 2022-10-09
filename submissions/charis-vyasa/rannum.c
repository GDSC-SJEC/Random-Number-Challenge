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
        printf("##########\nGreat job %s!\n", name);
        printf("Your score is: %i\n#########\n", score);
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
    printf("Hint: Guess a number between 1 and 100 (inclusive).\n");
    printf("Hint: Press 'q' to quit.\n");
    while(score){
        printf("Guess: ");
        scanf("%s", temp);
        if (temp[0] == 'q')
            exit(0);
        if (!atoi(temp)){
            printf("Not a number!\n");
            continue;
        }
        guess = atoi(temp);

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
    return score;
}

short medium(){
    short score = 1000, i, guess, difference;
    char temp[20];
    char prime[150] =   [101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179
                   ,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269
                   ,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367
                   ,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461
                   ,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571
                   ,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661
                   ,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773
                   ,787,797,809,811,821,823,827,829,839,853,857,859,863,877,881,883
                   ,887,907,911,919,929,937,941,947,953,967,971];
    printf("======MEDIUM=MODE=====\n");
    printf("Type a number between 1 and 140");
    printf("Hint: Press 'q' to quit.\n");
    printf("Number: ");
    scanf("%s", temp);
    if (temp[0] == 'q')
        exit(0);
    if (!atoi(temp)){
        printf("Not a number!\n");
        continue;
    }
    i = atoi(temp);
    secret = char prime[i];
    while(score){
        printf("Guess: ");
        scanf("%s", temp);
        if (temp[0] == 'q')
            exit(0);
        if (!atoi(temp)){
            printf("Not a number!\n");
            continue;
        }
        guess = atoi(temp);

        // Checking and reducing score
        if (guess == secret){
            return score;
        }
        else {
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
return score;    
}

short hard(){
    printf("Under construction\n");
    exit(0);
}
