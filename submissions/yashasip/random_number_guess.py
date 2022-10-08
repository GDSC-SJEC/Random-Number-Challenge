import random

random_num = random.randint(1, 64)

def is_number(number): # checks if guess is right and prints message
    if number == random_num:
        print("Yep, you guessed it right! That's the number.")
        print("---------------------------------------------")
        return True
    
    print("Oh no, that wasn't the number :(")
    if number > random_num:
        print(f'The number is < {number}.')
    else:
        print(f'The number is > {number}.')
    
    return False


def guess_number():
    attempts_count = 5
    while(attempts_count):
        print("------- GUESS THE NUMBER RANGING FROM 1-64 -------")
        number = int(input())

        right_guess = is_number(number)
        
        if right_guess: # when guess is right player wins, exit game
            return

        attempts_count -= 1
        if attempts_count == 1: # for last attempt, print different message
            print("1 attempt left. Think.")
        else:
            print(f'{attempts_count} attempts left')

    print(f'Ah, you ran out of attempts.\nThe number was {random_num}.\nBetter luck next time!')

guess_number()

    
