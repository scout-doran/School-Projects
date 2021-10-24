#Scout Doran November 17, 2017
#This program takes a set of integers entered by the user and computes the integers, that are divisible by 5, to find the mean

x = input('Enter a  positive integer (negative integer if you want to stop): ')
x = float(x)
Sum = 0
Count = 0
#Take the integer and if it's divisible by 5 add it to your sum
#Once the user enters a negative number calculate the mean
while x >= 0:
    if x % 5 == 0:
        Sum += x
        Count += 1
    else:
        pass
    x = input('Enter a  positive integer (negative integer if you want to stop): ')
    x = float(x)

#Calculate the mean of the integers that are evenly divisible by 5
Average = (Sum)/(Count)
print('The mean of the integers that are divisible by 5 is: ',Average)
    
