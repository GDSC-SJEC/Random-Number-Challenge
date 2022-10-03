#include <iostream>
using namespace std;

int main()
{ 
    int attempts = 10; //number of attemps the player can make

    srand(time(NULL)); //generates a seed based on the system internal clock , making the seed unique for each attempt
    int randomInteger = rand() % 100; //limits range to be within 100

    while (attempts--)
    {
        cout << "------------- TRY GUESSING THE NUMBER RANGING FROM 1 to 100 ------------------" << endl;
        int input;
        cin >> input;

        if ((int)input == randomInteger)
        {
            cout << "You have successfully guessed the Number , Good Job!!";
            break;
        }
        else
        {
            if (attempts == 0) //break once all attempts reached
            {
                cout << "You Exhausted all your attempts! \nThe number was " << randomInteger << "!";
                break;
            }

            cout << "That wasn't the number!" << endl;
            cout << (input < randomInteger ? "Try guessing a greater number!" : "Try guessing a smaller number!")<<endl;
            cout << "You got " << attempts << " attempts left!" << "\n\n";
        }
    }
    
   
}


