#Scout Doran, November 7
#This program prints the range of integers from 1 to the integer that the user entered and computes the running sum of a set of integers
x = input('Enter an integer between 10 and 50: ')
x = int(x)
count = 1
value = 0

#Main program that computes for the given integer
def main():
    count = 1
    value = 0
    if(x >= 10 and x <= 50):
        value = value + count
        print('Count: ',count,' Value: ',value)
        while count < x:
            count += 1  
            value += count
            print('Count: ',count,' Value: ',value)
            
    else:
        pass
main()

#if the user enters an invalid integer, ask for a different integer       
while (x >= 10 and x <= 50) is False:
    print('The integer you entered is invalid ')
    print('Please enter a different integer\n')
    x = input('Enter an integer between 10 and 50: ')
    x = int(x)
main()
    

