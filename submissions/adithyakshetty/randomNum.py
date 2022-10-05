import random
from welcome_logo import welcome_image


print(welcome_image)
print()
print("Hello, This is game to guess numbers ranging from 0-10")
lives_counter = "♥♥♥"
print("Player Got Three Lives(",lives_counter,")")
comp_guessed_number = random.randint(0,10)
counter = 0
guessed = False
while counter < 3:
    user_guessed_number = int(input("Guess The Number : "))
    if user_guessed_number == comp_guessed_number:
        print("Lesssss goooo, U guessed it 🔥🔥🔥")
        guessed = True
        break
    else:
        temp_lst = list(lives_counter)
        temp_lst.pop()
        lives_counter = "".join(temp_lst)
        
    counter += 1
    if counter != 3:
        print("Your left with ",lives_counter)

if not guessed:
    print("Sadge, Better luck next time 👍")
    print("The Number Is : ",comp_guessed_number)



