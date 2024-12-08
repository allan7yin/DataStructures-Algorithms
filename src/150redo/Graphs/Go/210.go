package graphs

// same time complexity as course schedule 2 -> only diff. Now add to slice
func findOrder(numCourses int, prerequisites [][]int) []int {
	dep := make(map[int][]int)
	for _, pre := range prerequisites {
		dep[pre[0]] = append(dep[pre[0]], pre[1])
	}

	var s []int

	visited := make([]bool, numCourses)
	added := make([]bool, numCourses)
	cycle := false

	var f func(c int)
	f = func(c int) {
		if visited[c] {
			cycle = true
			return
		}

		if added[c] {
			return
		}

		visited[c] = true
		for _, neighbour := range dep[c] {
			f(neighbour)
		}
		visited[c] = false
		added[c] = true
		s = append(s, c)
	}

	for i := 0; i < numCourses; i++ {
		if !added[i] {
			f(i)
		}
	}

	if cycle {
		return []int{}
	}
	return s
}
