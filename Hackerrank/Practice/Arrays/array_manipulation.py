#!/bin/python

import math
import os
import random
import re
import sys

# Complete the arrayManipulation function below.
def arrayManipulation(n, queries):
    curr = 0
    m = len(queries)
    q = {}
    for i in range(0,m):#O(m)
        a = queries[i][0]
        b = queries[i][1]
        k = queries[i][2]
        q[a] = q.get(a,0) + k
        q[b+1] = q.get(b+1,0) - k

    max = -1
    for i in range(1,n+1):#O(n)
        curr+=q.get(i,0)
        if(curr > max):
            max = curr
    
    return max

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nm = raw_input().split()

    n = int(nm[0])

    m = int(nm[1])

    queries = []

    for _ in xrange(m):
        queries.append(map(int, raw_input().rstrip().split()))

    result = arrayManipulation(n, queries)

    fptr.write(str(result) + '\n')

    fptr.close()
