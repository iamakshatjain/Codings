# 0.99sec
t = int(input())
while(t>0):
    s = input()
    N = len(s)
    total_count = 0
    for i in range(1, N//2):
        i4 = (2*i + N-1)//2 + 1

        # the second string is not even sized
        if (N- 2*i)%2!=0 :
            continue
        
        if(s[0:i] == s[i:2*i] and s[2*i : i4] == s[i4:N]):
            total_count+=1
    print(total_count)

    t-=1