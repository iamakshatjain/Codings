t = int(input())
while(t>0):

	a = list(map(int, input().split()))
	x = a[0]
	n = a[1]
	m = a[2]

	while(x>0 and n>0):
		if(x<=m*10):
			x-=(m*10)
			break
		x = x//2
		x+=10
		n-=1
	x-=(m*10)

	if(x<=0):
		print("YES")
	else:
		print("NO")

	t-=1