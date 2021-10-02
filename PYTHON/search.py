
def search(list,n):

	for i in range(len(list)):
		if list[i] == n:
			return True
	return False

# list 
list = [1, 2, 'apple', 4,'Grapes', 6]

# Driver Code
n = 'Grapes'

if search(list, n):
	print("Found")
else:
	print("Not Found")
