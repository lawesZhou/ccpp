import random

def swap(arr, i, j):
	temp = arr[i]
	arr[i] = arr[j]
	arr[j] = temp

def binary_part(arr):
	i = 0
	key = arr[i]
	left = 1
	right = len(arr) -1

	while (left < right):
		while (left < right and key < arr[left]):
			left += 1
		 
		while (left < right and key > arr[right]):
		 	right -= 1

		if (right == left):
			break

		swap(arr, left, right)			
		left += 1
		right -= 1

##	print "arr[", left, "] = ", arr[left], "arr[",right, "] = ", arr[right]

	if (right == left): 
		if (arr[left] > key):
			swap(arr,left, i)
			return left
		else:
			swap(arr,right - 1, i)
			return right - 1
	swap(arr, right, i)
	return right

def selection(arr, left, right, n):
	if (len(arr) == 1):
		return arr;

	i = binary_part(arr)

	if (i + 1 == n):
#		print arr, "index = ", i, i + 1, "= ", n, "\nall n:",arr[:n]
		return arr[:n]

	if (i + 1 < n):
#		print arr, "index = ", i, i + 1, "<", n, "\nformer",arr[:i + 1]
		return arr[:i + 1] + selection(arr[i+1:], i + 1, right, n - (i + 1))

	else:
#		print arr, "index = ", i, i + 1, ">", n, "\n",arr[:i]
		return selection(arr[:i], left, i-1, n)

def find_bignums(N, random_range, n):
	randnums = [random.randint(0, random_range) for i in range(N)]

	arr = selection(randnums, 0, len(randnums) - 1, n)
	return arr

if __name__ == "__main__":
	N = 10000
	random_range_max = 100*1000
	numbers_biggest = 100

	arr = find_bignums(N, random_range_max, numbers_biggest)
	print "your answer is below:"
	print arr

