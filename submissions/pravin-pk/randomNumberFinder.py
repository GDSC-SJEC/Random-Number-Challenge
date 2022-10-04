import random

num = random.randint(1,100)

name = input("Enter player name : ")

for limit in range(9, -1, -1):
    n = int(input("Guess the number from 1 to 100 : "))

    if num == n:
        print(f"Hurray!! Congratulations {name}, you have guessed the number, good job.")
        exit()
    else:
        print("That wasnt the number!")
        print('Try guessing a greater number!' if n < num else 'Try guessing a smaller number!')
        print(f"You got {limit} attempts left!")

print(f"You Exhausted all your attempts! \nThe number was {num}")