def Bfs(C, First, s, t): # C is the capacity matrix
n = len(C)
queue = []
queue.append(s)
global steps
steps = n * [0] # initialization
steps[s] = 1
while queue:
  k = queue.pop(0)
for i in range(n):
  if (First[k][i] < C[k][i]) and(steps[i] == 0): # not visited
steps[i] = steps[k] + 1
queue.append(i)
return steps[t] > 0

#search augmenting path by using DFS
def Dfs(C, F, k, cp):
  tmp = cp
if k == len(C) - 1:
  return cp
for i in range(len(C)):
  if (level[i] == level[k] + 1) and(F[k][i] < C[k][i]):
    f = Dfs(C, F, i, min(tmp, C[k][i] - F[k][i]))
F[k][i] = F[k][i] + f
F[i][k] = F[i][k] - f
tmp = tmp - f
return cp - tmp

#calculate max flow
#_ = float('inf')
def MaxFlow(C, s, t):
  n = len(C)
F = [n * [0]
  for i in range(n)] # F is the flow matrix
flow = 0
while (Bfs(C, F, s, t)):
  flow = flow + Dfs(C, F, s, 100000)
return flow
