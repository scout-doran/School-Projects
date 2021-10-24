import random

randomList = []
while (len(randomList) <= 50):
    myList = random.randint(1, 100)
    randomList.append(myList)

def main():    
    print('I have made a list of 50 numbers from 1 to 100.')
    guess = int(input('Enter an integer to guess if the number is in a randomly generated list: '))
    if guess in range (0, 100):
        if (guess in randomList):
            print('The number you guessed is in the list')
            print(randomList)
        else:
            print('The number you guessed is NOT in the list')
            print(randomList)
    else:
        guess = int(input('Please enter an integer in the range 1 to 100'))

    

