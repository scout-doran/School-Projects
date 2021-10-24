#This program will take a users input of an object's mass and claculate it's weight.
mass = input('Enter mass:')
weight = (int(mass)*9.8)

#Take the weight and based on its position is determine if the object is too light or heavy
if weight > 1000:
    print('Weight: ',weight,' Newtons')
    print('This object is too heavy!')
elif 0 < weight < 10:
    print('Weight: ',weight,' Newtons')
    print('This object is too light!')
elif weight < 0:
    print('ERROR MASS CANNOT BE A NEGATIVE NUMBER')
else:
    print('Weight: ',weight,' Newtons')
    
#If user wants to enter another mass, repeat^^^
print('Do you want to enter another mass? yes or no?')
answer = input()
while answer == 'yes':
    count = 0
    x = range(0,3)
    for count in x: 
        mass = input('Enter mass:')
        weight = (int(mass)*9.8)
        if weight > 1000:
            print('Weight: ',weight,' Newtons')
            print('This object is too heavy!')
        elif weight < 10 and weight > 0:
            print('Weight: ',weight,' Newtons')
            print('This object is too light!')
        elif weight < 0:
            print('ERROR MASS CANNOT BE A NEGATIVE NUMBER')
        else:
            print('Weight: ',weight,' Newtons')
    break
    

    

