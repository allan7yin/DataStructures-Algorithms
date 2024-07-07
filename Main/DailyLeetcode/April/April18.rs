use std::collections::HashSet;

impl Solution {
    pub fn island_perimeter(grid: Vec<Vec<i32>>) -> i32 {
        let mut result = 0;
        let mut visited: HashSet<(usize, usize)> = HashSet::new();
        for i in 0..grid.len() {
            for j in 0..grid[0].len() {
                if grid[i][j] == 1 {
                    result += dfs(&grid, i, j, &mut visited);
                }
            }
        }
        result
    }
}

// Define dfs outside the impl block
fn dfs(grid: &Vec<Vec<i32>>, x: usize, y: usize, visited: &mut HashSet<(usize, usize)>) -> i32 {
    if x >= grid.len() || y >= grid[0].len() || grid[x][y] == 0 {
        return 1;
    }
    let pos = (x, y);
    if visited.contains(&pos) {
        return 0;
    }

    visited.insert(pos);

    let mut result = 0;
    result += dfs(grid, x + 1, y, visited);
    result += dfs(grid, x - 1, y, visited);
    result += dfs(grid, x, y + 1, visited);
    result += dfs(grid, x, y - 1, visited);
    result
}
