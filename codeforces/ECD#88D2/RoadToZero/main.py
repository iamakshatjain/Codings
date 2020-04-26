t = int(input())
while(t>0):
	x,y = map(int, input().split())
	a,b = map(int, input().split())
	m = min(x,y)
	print(min((x+y)*a, (m*b) + ((x+y-(2*m))*a)))
	t-=1
