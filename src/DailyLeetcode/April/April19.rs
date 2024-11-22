pub struct Solution {}

impl Solution {
    pub fn num_islands(mut grid: Vec<Vec<char>>) -> i32 {
        let mut result = 0;
        for i in 0..grid.len() {
            for j in 0..grid[0].len() {
                if grid[i][j] == '1' {
                    result += 1;
                    Self::dfs(&mut grid, i, j);
                }
            }
        }
        result
    }

    fn dfs(grid: &mut Vec<Vec<char>>, i: usize, j: usize) {
        if i < 0 || i >= grid.len() || j < 0 || j >= grid[0].len() || grid[i][j] != '1' {
            return;
        }

        grid[i][j] = '#';
        Self::dfs(grid, i + 1, j);
        Self::dfs(grid, i - 1, j);
        Self::dfs(grid, i, j - 1);
        Self::dfs(grid, i, j + 1);
    }
}
