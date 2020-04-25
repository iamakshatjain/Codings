t = int(input())
while(t>0):
    n,k = map(int, input().split())
    arr = list(map(int, input().split()))
    if(k == 1 or n == 1):
    	print("yes")
        t-=1
    	continue
    mp = {}
    for i in range(0, n):
        if(mp.get(arr[i],-1) == -1):
            mp[arr[i]] = [i]
        else:
            mp[arr[i]].append(i);
    flag = False;
    arr.sort()
    for i in range(0, n):
    	flag = False
    	v = arr[i] 
    	s = mp[v]
    	for j in range(0, len(s)):
    		if(s[j]!=-1 and (i - s[j])%k==0):
    			mp[v][j] = -1
    			flag = True
    			break
    	if(not flag): 
            break

    if(flag): 
        print("yes")
    else:
        print("no")
    t-=1
