
node = {
    'a':{'b':3, 'c':4, 'd':7},
    'b':{'c':1, 'f':5},
    'c':{'f':6, 'd':2},
    'd':{'e':3, 'g':6},
    'e':{'g':3, 'h':4},
    'f':{'e':1, 'h':8},
    'g':{'h':2},
    'h':{'g':2}
}

def dijkstra(node ,start ,end):
    shortest_node = {}
    track_covered = {}
    all_node = node
    infinity = 9999
    path = []
    
    for nodes in all_node:
        shortest_node[nodes] = infinity
    shortest_node[start] = 0
    
    while all_node:
        min_dist_node = None
        
        for nodes in all_node:
            if min_dist_node is None:
                min_dist_node = nodes
            elif shortest_node[nodes] < shortest_node[min_dist_node]:
                min_dist_node = nodes
        
        path_options = node[min_dist_node].items()
        
        for child_node,weight in path_options:
            if (weight + shortest_node[min_dist_node]) < shortest_node[child_node]:
                shortest_node[child_node] = weight + shortest_node[min_dist_node]
                track_covered[child_node] = min_dist_node
                
        all_node.pop(min_dist_node)
        
    current_node = end
        
    while current_node != start:
        try:
            path.insert(0 ,current_node)
            current_node = track_covered[current_node]
        except KeyError:
            print('PATH IS NOT RAECHABLE')
            break
        
    path.insert(0,start)
        
    if shortest_node[end] != infinity:
        print('SHORTEST DISTANCE IS ' + str(shortest_node[end]))
        print('OPTIMAL PATH IS ' + str(path))

dijkstra(node, 'a','h')

