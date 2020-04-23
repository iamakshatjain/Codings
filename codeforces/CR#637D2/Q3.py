#WA
def dfs(g, d, vis, n, l):
	if(vis[n]==0):
		d[n] = l
		vis[n] = 1
	else:
		return
	for i in g[n]:
		if(vis[i] == 0):
			dfs(g, d, vis, i, l+1)

i = list(map(int, input().split()))
n,k = i[0], i[1]
g = {}

for i in range(1, n+1):
	g[i] = []

for i in range(1, n):
	x = list(map(int, input().split()))
	a,b = x[0], x[1]
	g[a].append(b)
	g[b].append(a)

d = [0]*(n+1)
vis = [0]*(n+1)
	

print(g)

# print(g)

# for i in g.keys():
# 	# for j in g[i]:
# 	# 	if(i == 1):
# 	# 		d[j] = 1
# 	# 	else:
# 	# 		d[j] = d[i]+1
dfs(g, d, vis, 1, 0)
print(d)
print(vis)

d.sort(reverse=True)
s = 0
for i in range(k):
	s+=d[i]

print(s)
