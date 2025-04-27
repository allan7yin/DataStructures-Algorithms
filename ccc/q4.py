def node(room, i, num_temps):
    return (room - 1) * num_temps + i

def min_cost_path():
    import sys
    import heapq

    data = sys.stdin.read().strip().split()
    num_rooms = int(data[0])
    num_tunnels = int(data[1])
    
    edges = []
    i = 2
    temps = {0}
    for _ in range(num_tunnels):
        a = int(data[i])
        b = int(data[i+1])
        c = int(data[i+2])

        i += 3
        edges.append((a, b, c))
        temps.add(c)
    
    sorted_temps = sorted(temps)
    index_mp = {t: i for i, t in enumerate(sorted_temps)}
    num_temps = len(sorted_temps)
    
    graph = [[] for _ in range(num_rooms * num_temps)]
    
    # construct graph representation
    for r in range(1, num_rooms + 1):
        base = (r - 1) * num_temps
        for i in range(num_temps - 1):
            cost = sorted_temps[i+1] - sorted_temps[i]
            graph[base + i].append((base + i + 1, cost))
            graph[base + i + 1].append((base + i, cost))
    
    for (a, b, c) in edges:
        i = index_mp[c]
        graph[node(a, i, num_temps)].append((node(b, i, num_temps), 0))
        graph[node(b, i, num_temps)].append((node(a, i, num_temps), 0))
    
    s = node(1, index_mp[0], num_temps)
    
    INF = 10**15
    dist = [INF] * (num_rooms * num_temps)
    dist[s] = 0
    
    # run djkstras
    pq = [(0, s)]  # (cost so far, node)
    while pq:
        cur_dist, u = heapq.heappop(pq)
        if cur_dist > dist[u]:
            continue
        
        room_id = u // num_temps # integer division
        if room_id == (num_rooms - 1):
            print(cur_dist)
            return
        
        for (v, cost) in graph[u]:
            new_dist = cur_dist + cost
            if new_dist < dist[v]:
                dist[v] = new_dist
                heapq.heappush(pq, (new_dist, v))

# compute min cost path from s to t in floor is lava graph
min_cost_path()