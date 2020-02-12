#find the duplicate in this array
array = ['a','b','c','d','d']

def doubles(array):
	dict = {}
	for i in range(len(array)):
		count = 1
		temp = array[i]
		if temp in dict:
			print(temp)
			return temp
		else:
			dict[temp] = count
	print("No doubles in here")
	return -1

doubles(array)

