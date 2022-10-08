import random

r = random.randint(1,10)
max_tries = 3
tries = 0

def checkNumber(number):
    global tries, max_tries
    if number == r:
        print(f'Awesome! You got it in {tries + 1} guesses!')
        return True
    
    tries += 1
    if number > r:
        print(f'Missed it.  Your number is too high.')
    else:
        print(f'Missed it.  Your number is too low.')

    if tries == max_tries:
        print(f'GAME OVER.  The number was {r}.')

    return False

def guess():
    global tries, max_tries
    while(tries < max_tries):
        n = int(input())
        
        if checkNumber(n):
            exit()


print('Welcome to the number guessing game.')
print('Guess a number between 1 - 10')
print('You will get three tries to guess the correct number.')

guess()
