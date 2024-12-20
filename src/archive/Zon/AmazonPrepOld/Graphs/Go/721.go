package graphs

import "sort"

func accountsMerge(accounts [][]string) [][]string {
	name := make(map[string]string)
	parent := make(map[string]string)

	var find func(x string) string

	// first time, worst case O(n) -> subsequent calls are O(1)
	// this is worst case αO(n) -> where αO(n) <= 5 -> amortzied, find is O(1)
	find = func(x string) string {
		if parent[x] != x {
			parent[x] = find(parent[x])
		}
		return parent[x]
	}

	// this is O(1)
	var union func(s1, s2 string)
	union = func(s1, s2 string) {
		parent[find(s2)] = find(s1)
	}

	for _, account := range accounts {
		accountName := account[0]
		firstEmail := account[1]

		for i := 1; i < len(account); i++ {
			email := account[i]

			if _, ok := parent[email]; !ok {
				parent[email] = email
				name[email] = accountName
			}

			union(firstEmail, email)
		}
	}

	merged := make(map[string][]string)
	for email := range parent {
		root := find(email)
		merged[root] = append(merged[root], email)
	}

	// convert this map to slice of slices
	var result [][]string

	for root, emails := range merged {
		sort.Strings(emails)
		account := append([]string{name[root]}, emails...)
		result = append(result, account)
	}

	return result
}
