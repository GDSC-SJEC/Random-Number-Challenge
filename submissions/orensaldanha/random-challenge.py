import random

num = random.randint(1, 100)
guesses = 5

print('Random number challenge (1 - 100)\n')

for guess_no in range(1, guesses + 1):
    print('Guess the number: ', end='')
    guess = int(input())
    

    if guess == num:
        print('You have successfully guessed the number in ' + str(guess_no) +  ' guesses')
        exit(0)
    elif guess > num:
        print('Oh no! Your guess is too high')
    else:
        print('Oh no! Your guess is too low')

    print('You have ' + str(guesses - guess_no) + ' guesses remaining\n')


print('You have run out of guesses. The number is ' + str(num) +'. Try again!')