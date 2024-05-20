from typing import List


class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        result = 0

        def dfs(grid, i, j):
            if (
                i < 0
                or i == len(grid)
                or j < 0
                or j == len(grid[0])
                or grid[i][j] != "1"
            ):
                return

            # means the grid is fine here
            grid[i][j] = "#"  # mark as visited
            dfs(grid, i + 1, j)
            dfs(grid, i - 1, j)
            dfs(grid, i, j + 1)
            dfs(grid, i, j - 1)

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == "1":
                    result += 1
                    dfs(grid, i, j)

        return result
