from sys import maxsize as inf


def prim(graph, v):
    visited = [False] * v
    n = 0
    visited[0] = True
    result = []

    while n < v - 1:
        least_cost = inf
        x, y = 0, 0
        for i in range(v):
            if visited[i]:
                for j in range(v):
                    if not visited[j]:
                        if graph[i][j] < least_cost:
                            least_cost, x, y = graph[i][j], i, j

        visited[y] = True
        result.append((x, y, graph[x][y]))
        n += 1

    return result


G = [
    [inf, 1, 3, 2],
    [1, inf, 1, 2],
    [3, 1, inf, 4],
    [2, 2, 4, inf]
]

print(prim(G, 4))
