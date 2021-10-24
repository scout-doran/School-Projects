Average = 0
Counter = 1
Number = 0
x = input('Enter an interger: ')
x = int(x)

if (x % 4) == 0:
	Number = 1
	print()
	Average = x
	Counter = (Counter + 1)
else:
	print()
	Counter = (Counter + 1)
while (Counter != 11):
	print('Counter: ')
	print(Counter)
	x = input('Enter an interger:')
	x = int(x)
	if (x % 4) == 0:
		Number = (Number + 1)
		print()
		Average = (Average + x)
		Counter = (Counter + 1)
	else:
		print()
		Counter = (Counter + 1)
Average = (Average/Number)
print('Average: ')
print(Average)