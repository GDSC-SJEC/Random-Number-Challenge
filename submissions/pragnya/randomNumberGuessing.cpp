//C++ program to implement random number guessing game 
#include <iostream> 
#include<ctime> //for using time() function 
#include<cstdlib> //for using rand() function 
using namespace std; 

int num = 1,guess ,tries=0; //declaring and initializing variables 

int game(string level, int ran0, int ran1)
{
    cout<<"\t"<<level<<endl; 
    cout<<"You have "<<(5-tries)<<" lives remaining\n"; 
    tries++; //updating tries for each wrong guesses 
    cout<<"Guess a number between 1 and 100: "; 
    cin>>guess; 

    srand(time(0)); 
    //providing players hints according to their difficulty level 
    if(num>guess)  
        cout<<"TOO LOW!!!\nHINT: The number is between "<<(num-ran0)<<" and "<<(num+ran1)<<endl<<endl; 
    else if(num<guess)   
        cout<<"TOO HIGH!!!\nHINT: The number is between "<<(num-ran0)<<" and "<<(num+ran1)<<endl<<endl; 

    else //if guessed number is equal to the generated number 
    { 
        cout<<"CORRECT!!!\n       You got it in "<<tries<<" guesses"<<endl; 
        cout<<"Congratulations!! You WIN\n\n"; 
    } 

    if(tries==5)//if the player inputs 5 wrong guesses 
    { 
        cout<<"YOU LOSE!!\n"; 
        cout<<"The answer is "<<num<<"\n\n";
        guess=num; //to end the while loop 
    }
}
int main() 
{ 
  char x; //character variable which is used for ending or continuing the game 
  int opt;
  srand(time(0)); 
  num=rand()%100+1; //random numbers are generated within the limit 0 to 100 

  do //using do while loop till the player doesn’t want to continue the game 
  { 
    string level="";
    int dif;
    cout<<"\n       THE GUESSING GAME\n\n"; //creating menu 
    cout<<"Difficulty level\n"; 
    cout<<"1.Noobie\n"; 
    cout<<"2.Regular\n"; 
    cout<<"3.Advanced\n"; 
    cout<<"4.Godlike\n"; 

    cout<<"choose your level: "; 
    cin>>opt; 
    cout<<endl;

    while(guess!=num) //while loop, ends when the player guesses the correct number  
    { 
        int ran0=rand()%3; //to create difference
        int ran1 =rand()%3;
        switch(opt) //creating switch statement for different difficulty level 
        { 
        case 1:
            level="Noobie"; 
            ran0 += 5;
            ran1 += 5;
            game(level,ran0,ran1);
        break; 

        case 2: 
            level = "Regular";
            ran0 += 15;
            ran1 += 15;
            game(level,ran0,ran1);
        break; 

        case 3: 
            level = "Advanced";
            ran0 += 25;
            ran1 += 25;
            game(level,ran0,ran1);
        break; 

        case 4: 
            cout<<"\n\tGodlike\n"; 
            cout<<"You have "<<(5-tries)<<" lives remaining\n"; 
            tries++;//updating for each wrong guess 

            cout<<"Guess a number between 1 and 100: "; 
            cin>>guess; 

            if(num>guess) 
                cout<<"TOO LOW!!!"<<endl; 

            else if(num<guess) 
                cout<<"TOO HIGH!!!"<<endl; 

            else //correct guess 
            { 
                cout<<"CORRECT!!!\n       You got it in "<<tries<<" guesses"<<endl; 
                cout<<"Congratulations!! You WIN\n\n"; 
            } 

            if(tries>=5) //losing all the 5 chances 
            { 
                cout<<"YOU LOSE!!\n\n"; 
                cout<<"The answer is " <<num<<"\n\n";
                guess=num; //to exit the while loop 
            } 
        break; 

        default: //if player chooses invalid levels 
            cout<<"Sorry!! There's no such choice\n"; 
            guess=num; //to exit the while loop 
        break; 
        } 
    } 

    tries=0; //re-declaring for new game  
    guess=4567; //assigning guess some random number outside the limit(0-100) 
    //making sure the generated random number is not ‘guess’, if player chooses to continue the game 
    num=rand()%100+1;
    cout<<"Do you want to play again??[Y/N]: "; //choice for the player to continue or end the game 
    cin>>x; 

  }while(x=='y' || x=='Y'); //end of do-while loop 
  cout<<"Thank you for playing:)\n"; 
} 
//end of the program 