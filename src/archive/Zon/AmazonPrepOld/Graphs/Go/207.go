package graphs

// this is topo sort question with cycle detection
// if cycle detected, return false

// Runtime: O(V + E) -> we visit every node AND every edge, which is why its not a simple O(n)
func canFinish(numCourses int, prerequisites [][]int) bool {
	dep := make(map[int][]int)
	for _, p := range prerequisites {
		dep[p[0]] = append(dep[p[0]], p[1])
	}

	visit := make([]bool, numCourses)
	added := make([]bool, numCourses)
	cond := true

	var f func(c int)
	f = func(c int) {
		if visit[c] {
			cond = false
			return
		}
		if added[c] {
			return
		}
		added[c] = true
		visit[c] = true
		for _, neighbor := range dep[c] {
			f(neighbor)
		}
		visit[c] = false
	}

	for i := 0; i < numCourses; i++ {
		if !added[i] {
			f(i)
		}
	}
	return cond
}
