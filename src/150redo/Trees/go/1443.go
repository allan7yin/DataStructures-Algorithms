package trees

// dfs from map -> O(N) time where n is number of nodes
func minTime(n int, edges [][]int, hasApple []bool) int {
	adj := make(map[int][]int)
	for _, edge := range edges {
		u := edge[0]
		v := edge[1]
		adj[u] = append(adj[u], v)
		adj[v] = append(adj[v], u)
	}

	visited := make([]bool, n)
	var dfs func(node int) bool
	count := 0

	dfs = func(node int) bool {
		visited[node] = true
		contains := hasApple[node]

		for _, nei := range adj[node] {
			if !visited[nei] && dfs(nei) {
				count += 2
				contains = true
			}
		}

		return contains
	}

	dfs(0)
	return count
}
