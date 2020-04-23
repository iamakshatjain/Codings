#WA

t = int(input())
while(t>0):
	n,k = map(int, input().split())
	a = list(map(int, input().split()))
	s = []
	mi = 1000000001
	miind = -1
	ma = -1000000001
	maind = -1
	for i in range(n//2):
		s.append(a[i]+a[n-i-1])
		if(a[i]+a[n-i-1] < mi):
			mi = a[i]+a[n-i-1]
			miind = i
		if(a[i]+a[n-i-1] > ma):
			ma = a[i]+a[n-i-1]
			maind = i
	r = [0,0]
	if(a[maind] < a[n-maind-1]):
		r[0] = a[maind]+1
	else:
		r[0] = a[n-maind-1]+1

	if(a[miind] < a[n-miind-1]):
		r[1] = k+a[n-miind-1]
	else:
		r[1] = k+a[miind]

	# print(r)
	m = {}
	mx = 0
	for i in s:
		if(i>=r[0] and i<=r[1]):
			# print("i",i)
			if(m.get(i, -1) == -1):
				m[i] = 1
			else:
				m[i]+=1
			mx = max(mx, m[i])
	print(n//2 - mx)


	t-=1
