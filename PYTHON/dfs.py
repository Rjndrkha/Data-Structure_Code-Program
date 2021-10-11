graph = {
  'V' : ['V2','V1'],
  'V2' : ['V1', 'V3', 'V4', 'V'],
  'V1' : ['V3', 'V5', 'V2', 'V'],
  'V3' : ['V4', 'V5', 'V1', 'V2'],
  'V4' : ['V3', 'V2'],
  'V5' : ['V3', 'V1']
}

visited = set() # Set to keep track of visited nodes of graph.

def dfs(visited, graph, node):  #function for dfs 
    if node not in visited:
        print (node)
        visited.add(node)
        for neighbour in graph[node]:
            dfs(visited, graph, neighbour)

# Driver Code
print("Following is the Depth-First Search")
dfs(visited, graph, 'V')
