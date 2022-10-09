//random number guessing game
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main(){
int number;
int lower = 100;
int upper = 999;
srand(time(NULL));
 number = (rand() % (upper - lower + 1)) + lower;

printf("have five chances to guess the number a three digit random number try your luck\n");
int count = 5;


//the find each digit of the rand number
int arr[3];
int temp = number;
for(int i=0; i<3 ;i++){
  int digit =  temp%10;
  temp = temp/10;
  arr[i] = digit;
}

// to take input from the user

while(count--){
int guess;
scanf("%d",&guess);
int arr_guess[3];
int temp1 =guess; 

for(int i=0 ; i<3 ;i++){
    int digit =  temp1%10;
  temp1 = temp1/10;
  arr_guess[i] = digit;
}

for(int i=0; i<3 ;i++){
    if(arr[i] == arr_guess[i]){
        printf("hint: the number %d is present in answer in the %d place!!!\n",arr[i],i+1);
    }
}

if(number == guess){
    printf("congratulations you have won the game!!!\n");
    exit(0);
}

if(number != guess){
    printf("sorry but is not the right number you have %d tries remaning\n",count);
}
}

printf("you loose the number is %d",number);





    return 0;
}