x = input('Enter a positive, non-zero interger:')
x = int(x)
value = 1
y = 1
while (x > 0 and value <= 9):
	y = y * value
	value = value + 1

print(y)	
quit()
	