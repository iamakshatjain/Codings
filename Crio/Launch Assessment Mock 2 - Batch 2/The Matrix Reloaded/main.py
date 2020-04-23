#https://www.hackerrank.com/contests/launch-assessment-mock-2-batch-2/challenges/the-matrix-reloaded

t = int(input())
while(t):
    n = int(input())
    matrix = []
    for i in range(0,n):
        matrix.append(list(map(int, input().split())))

    center = matrix[n//2][n//2]
    start = matrix[0][0]
    
    if(center > start):
        print(-1)
        t-=1
        continue
    
    matrix = sum(matrix, [])
    matrix.sort()
    index_center = matrix.index(center)
    index_start = matrix.index(start)
    print(index_start - index_center)
    
    t-=1
