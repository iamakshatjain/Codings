#WA
t = int(input())
while(t>0):
	s = list(map(int, input().split()))
	a = s[0]
	b = s[1]
	c = s[2]
	d = s[3]

	#we need to find x,y,z
	x = (a + b)//2
	y = (b + c)//2
	z = (c + d)//2

	while(x+y<=z or y+z<=x or z+x<=y):
		if(x+y<=z):
			x = (x+b)/2
			y = (y+c)/2

		if(y+z<=x):
			z = (z+d)/2
			y = (y+c)/2

		if(x+z<=y):
			x = (x+b)/2
			z = (z+d)/2
		x = int(x)
		y = int(y)
		z = int(z)

		print(x, y, z)

	t-=1
