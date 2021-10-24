x = input('Enter an integer between 10 and 50: ')
x = int(x)
count = 1
value = 0
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
        print()
main()
        
while (x >= 10 and x <= 50) is False:
    print('The integer you entered is invalid ')
    print('Please enter a different integer\n')
    x = input('Enter an integer between 10 and 50: ')
    x = int(x)
    # Main Program
    if __name__ == "__main__":
    # Launch main menu
        main()

    


        
