t = int(input())
while(t>0):
	n = int(input())
	k = 2
	x = -1
	v = 2**k-1
	while(v <= n):
		if(n%v == 0):
			x = n//v
			break
		k+=1
		v+=1
		v*=2
		v-=1
		v = v
	print(x)
	t-=1