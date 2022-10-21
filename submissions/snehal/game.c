#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num, guess, diff, flag = 0, i;
    srand(time(0));
    num = rand() % 100 + 1;
    // printf("%d\n",num);
    printf("======Guess My Number Game=====\n");
    printf("H: Enter a guess between 1 and 100\nH: You have 10 chances to guess\n");
    // while (flag == 1)
    for (i = 0; i < 10; i++){
        printf("Your Guess: ");
        scanf("%d", &guess);
        diff = abs(num-guess);
        if(guess < 0 || guess > 100)
        {
            printf("H: Out of range\n");
            continue;
        }
        else if (diff == 0)
        {
            printf("yay! your guess is correct\n");
            flag =1;
            break;
        }
        else if (diff<3)
        {
            printf("H: Very close\n");
            //count++;
        }
        else if (diff >= 3 && diff < 15)
        {
            printf("H: Close\n");
            //count++;
        } 
        else if (diff >= 15 && diff < 50)
        {
            printf("H: Moderately close\n");
            //count++;
        }
        else if (diff >= 50 && diff < 65)
        {
            printf("H: Far\n");
            //count++;
        }
        else
        {
            printf("H: Too Far\n");
            //count++;
        }
    }

    
    if(flag == 0)
        printf("sorry, you lost the game\n");
    else
        printf("you guessed in %d trials\n", i + 1);
    
}