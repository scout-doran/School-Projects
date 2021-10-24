x = input('Enter an interger: ')
x = int(x)	

while (x % 5 == 0):
	print(x, 'is evenly divisible by 5')

	print('Do you want to try again Y or N?')
	answer = input()
	if answer == 'Y':
		x = input('Enter an interger: ')
		x = int(x)	

		if (x % 5) == 0:
			print (x, 'is evenly divisible by 5')
		
		else:
			print (x, 'is not evenly divisible by 5')
	else:
		print('Goodbye')
		quit()
while (x % 5 != 0):
	print (x, 'is not evenly divisible by 5')

	print('Do you want to try again Y or N?')
	answer = input()
	if answer == Y or y:
		x = input('Enter an interger: ')
		x = int(x)	

		if (x % 5) == 0:
			print (x, 'is evenly divisible by 5')
		
		else:
			print (x, 'is not evenly divisible by 5')
	else:
		print('Goodbye')
		quit()