package graphs

func wallsAndGates(rooms [][]int) {
	for i := 0; i < len(rooms); i++ {
		for j := 0; j < len(rooms[0]); j++ {
			if rooms[i][j] == 0 {
				dfs2(rooms, i+1, j, 1)
				dfs2(rooms, i-1, j, 1)
				dfs2(rooms, i, j+1, 1)
				dfs2(rooms, i, j-1, 1)
			}
		}
	}
}

func dfs2(rooms [][]int, r, c, d int) {
	if r < 0 || r >= len(rooms) || c < 0 || c >= len(rooms[0]) || rooms[r][c] == -1 || rooms[r][c] == 0 {
		return
	}

	if d < rooms[r][c] {
		rooms[r][c] = d
		dfs2(rooms, r+1, c, d+1)
		dfs2(rooms, r-1, c, d+1)
		dfs2(rooms, r, c+1, d+1)
		dfs2(rooms, r, c-1, d+1)
	}
}
