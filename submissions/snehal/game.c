#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num, guess, count = 0,diff,flag=0;
    srand(time(0));
    num = rand() % 100 + 1;
    printf("%d\n",num);
    //printf("Guess My Number Game\n\n");
    printf("Enter a guess between 1 and 100\nYou have 10 chances to guess\n");
    //while (flag == 1)
    do
    {
        printf("Your Guess: ");
        scanf("%d", &guess);
        diff=abs(num-guess);
        

        if (diff == 0)
        {
            printf("yay! your guess is correct\n");
            flag =1;
            break;
        }
        else if (diff<3)
        {
            printf("Too close\n");
            //count++;
        }
        else if (diff>=3 && diff<15)
        {
            printf("close\n");
            //count++;
        } 
        else if (diff>=15 && diff<50)
        {
            printf(" moderately close\n");
            //count++;
        }
        else if (diff>=50 && diff<65)
        {
            printf("Far\n");
            //count++;
        }
        else if (diff>=65 && diff<100)
        {
            printf("too Far\n");
            //count++;
        }
        else if(diff<0 || diff>100)
        {
            printf("out of range\n");
        }
        count++;
    }
    while (count<=10);
    
    if(flag == 0 && count == 10)
        printf("sorry, you lost the game\n");
    else if(flag ==1) 
        printf("you guessed in %d trials\n",count);
    
}