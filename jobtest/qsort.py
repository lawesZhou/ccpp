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

	while (left < right) :
		print "arr[", left, "] = ", arr[left], "arr[ ",right, "] = ", arr[right]
		while (left < right and key < arr[left]) :
			left += 1
		 
		while (left < right and key > arr[right]) :
		 	right -= 1

		if (right == left):
			break

		swap(arr, left, right)			
		left += 1
		right -= 1

	print "arr[", left, "] = ", arr[left], "arr[ ",right, "] = ", arr[right]
	if (right == left) : 
		if (arr[left] > key) :
			swap(arr,left, i)
			return left
		else :
			swap(arr,right - 1, i)
			return right - 1
	swap(arr, right, i)
	return right

def qsort(arr, left, right, n) :
	if (len(arr) == 1) :
		return arr;

	i = binary_part(arr)

	if (i + 1 == n) :
		print arr, "index = ", i, i + 1, "= ", n, "\n",arr[:n]
		return arr[:n]
	if (i + 1 < n) :
		print arr, "index = ", i, i + 1, "<", n, "\n",arr[:i + 1]
		return arr[:i + 1] + qsort(arr[i+1:], i + 1, right, n - i)
	else :
		print arr, "index = ", i, i + 1, ">", n, "\n",arr[:i]
		return qsort(arr[:i], left, i-1, n)

def find_bignums(nums, n):
	arr = qsort(nums, 0, len(nums) - 1, n)
	print nums[:n]

randnum = [random.randint(1, 20) for i in range(10)]

print randnum,len(randnum)
'''x = binary_part(randnum)

print randnum, randnum[:4]
print "index = ", x
'''
arr = qsort(randnum, 0, len(randnum) - 1, 2)
print arr
