import math
#WA
t = int(input())
MOD = 998244353
while(t>0):
	n = int(input())
	arr = list(map(int, input().split()))
	arr.sort()
	n = len(arr)
	count = 0;
	v = -1
	inter = []
	for i in arr:
		if(i!=v):
			if(v!=-1):
				inter.append([v, count])
			v = i
			count = 1
			
		else:
			count+=1	

	if(count!=0):
		inter.append([v, count])

	if(n == 0):
		print(1)
		t-=1
		continue

	if(inter[0][0]>1):
		print((1*(2**n))%MOD)
	else:
	    tot = 1
	    others = 0
	    required_int = 1
	    for i in inter:
	        if(i[0] >= required_int):
	            tot+=(((2**n)-1)%MOD-((2**i[1])-1)%MOD)*required_int
	            others+=((2**n) - (2**i[1]))
	            tot%=MOD
                required_int+=1
                
        tot+=((2**n)-others)%MOD
        print(tot)

	t-=1