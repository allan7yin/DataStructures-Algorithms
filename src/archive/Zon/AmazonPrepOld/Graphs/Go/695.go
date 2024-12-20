package graphs

func maxAreaOfIsland(grid [][]int) int {
	maxVal := 0
	for i := 0; i < len(grid); i++ {
		for j := 0; j < len(grid[0]); j++ {
			if grid[i][j] == 1 {
				area := dfs3(grid, i, j)
				if area > maxVal {
					maxVal = area
				}
			}
		}
	}
	return maxVal
}

func dfs3(grid [][]int, r int, c int) int {
	if r < 0 || r >= len(grid) || c < 0 || c >= len(grid[0]) || grid[r][c] == 0 {
		return 0
	}

	grid[r][c] = 0
	area := 1
	area += dfs3(grid, r+1, c)
	area += dfs3(grid, r-1, c)
	area += dfs3(grid, r, c+1)
	area += dfs3(grid, r, c-1)
	return area
}
