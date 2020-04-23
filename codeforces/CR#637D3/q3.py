def getPol(n):
	if(n<0):
		pol = -1
	else:
		pol = 1
	return pol

t = int(input())
while(t>0):
	n = int(input())
	a = list(map(int, input().split()))
	i = 0
	s = 0
	m = -1000000001
	while(i<n):
		pol = getPol(a[i])
		j = i
		m = -1000000001
		while(j<n):
			if(getPol(a[j])!=pol):
				break
			else:
				m = max(a[j],m)
			j+=1
		i = j
		# print("m",m)
		s+=m
	# s+=m
	print(s)

	t-=1