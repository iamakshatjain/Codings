#https://www.hackerrank.com/challenges/interval-selection/problem
#!/bin/python3

import os
import sys

def findCount(arr):
    proc = [-1]*2
    count = 0
    for i in arr:
        s = i[0]
        e = i[1]

        if(s > proc[0]):
            count+=1
            proc[0] = e
        elif(s > proc[1]):
            count+=1
            proc[1] = proc[0]
            proc[0] = e
        
    return count

def intervalSelection(intervals):
    return findCount(sorted(intervals, key=lambda x:x[1]))

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = int(input())

    for s_itr in range(s):
        n = int(input())

        intervals = []

        for _ in range(n):
            intervals.append(list(map(int, input().rstrip().split())))

        result = intervalSelection(intervals)

        fptr.write(str(result) + '\n')

    fptr.close()
