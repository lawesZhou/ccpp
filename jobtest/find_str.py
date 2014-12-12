def find_str(n):
	letters = ['c','e','i','a','r','w','u','s','p']
	s = []

	while n > 37:
		s.insert(0, letters[n % 37])
	        n /= 37

	return ''.join(s)


if __name__ == '__main__':
	n = 25267566250558
	str_ = find_str(n)
	print "\nyour answer of first questiong is: ",
	print str_
