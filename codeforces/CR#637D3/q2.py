def findNumbers(n):
	nums = []
	l = n//2
	ne = 2
	s = 0
	no = 1
	for i in range(l):
		nums.append(ne)
		s+=ne
		ne+=2
	for i in range(l-1):
		nums.append(no)
		s-=no
		no+=2
	nums.append(s)
	return nums



t = int(input())
while(t>0):
	n = int(input())
	if((n//2)%2!=0):
		print("NO")
	else:
		nums = findNumbers(n)
		print("YES")
		print(*nums)
	t-=1