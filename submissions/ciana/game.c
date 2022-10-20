#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
 {
     int n, g;
     printf("welcome to the game");
     const int lower = 1;
     const int upper = 500;
     srand(time(0));
     n = rand() % upper + lower;
     do { 
         printf("guess a number between %d to %d: ", lower, upper);
         scanf("%d", &g);
            if (g > 500 || g < 1){
		printf("out of range!\n");
		exit(0);
	    }
            else if (g > n) printf("try with lower value\n");
            else if (g < n) printf("try with higher value\n");
        }
     while(g != n);
     printf("You got it\n");	
        return 0;
}

