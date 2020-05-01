# WA
import math

t = int(input())
while(t>0):
	n = int(input())
	count = 0
	i = 1
	s1 = 0
	s2 = 0
	while(i+1<=n-2):
		mn = math.pow(2,i)
		mx = math.pow(2,i+1)
		s1+=mn
		s2+=mx

		i+=2

	mn = math.pow(2,i)
	mx = math.pow(2,i+1)
	s1+=mx
	s2+=mn

	print(abs(int(s1-s2)))

	t-=1