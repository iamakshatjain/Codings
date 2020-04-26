def createString(s):
	res = s[0]
	v = '0'
	if(s[0] == '0'):
		v = '1'
	i = 1
	while(i<len(s)):
		e = s[i]
		if(v == e):
			i+=1	
		res+=v
		if(v == '0'):
			v = '1'
		else:
			v = '0'

	return res


t = int(input())
while(t>0):
	s = input()
	c1=0
	c0=0
	for i in s:
		if i == '0':
			c0+=1
		else:
			c1+=1
	if(0 in (c0,c1)):
		print(s)
	else:
		print(createString(s))

	t-=1