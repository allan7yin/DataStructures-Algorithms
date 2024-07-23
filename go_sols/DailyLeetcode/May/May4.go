package May

import (
	"sort"
)

func numRescueBoats(people []int, limit int) int {
	result := 0
	sort.Ints(people)
	l, r := 0, len(people)-1

	// 1 2 2 3
	for l < r {
		if people[l]+people[r] <= limit {
			l++
		}
		r--
		result++

		if l == r {
			result++
		}
	}
	return result
}
