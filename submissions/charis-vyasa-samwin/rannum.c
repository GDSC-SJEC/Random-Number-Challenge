#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    char *name = malloc(30 * sizeof(char));
    printf("Enter your playername: ");
    scanf("%[^\n]%*c", name);

    // Setting Difficulty
    printf("Choose difficulty: Easy | Medium | Hard\n");
    bool difficulty_set = false;
    do {
        printf("(E/M/H): ");
        char difficulty;
        scanf("\n%c", &difficulty);
        if (toupper(difficulty) == 'E' || toupper(difficulty) == 'M' || toupper(difficulty) == 'H')
            difficulty_set = true;   
    } while (!difficulty_set);



    fclose(scores);
    free(name);
    return 0;
}
