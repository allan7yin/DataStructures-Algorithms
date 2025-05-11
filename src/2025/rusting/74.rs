struct Solution;

impl Solution {
    pub fn search_matrix(matrix: Vec<Vec<i32>>, target: i32) -> bool {
        let rows = matrix.len();
        let cols = matrix[0].len();
        let mut l: i32 = 0;
        let mut r: i32 = rows as i32 * cols as i32 - 1;

        while l <= r {
            let m = (l + (r  - l) / 2) as usize;
            let (m_x, m_y) = (m / cols, m % cols);

            if matrix[m_x][m_y] == target {
                return true;
            } else if target < matrix[m_x][m_y] {
                r = m as i32 - 1;
            } else {
                l = m as i32 + 1;
            }
        }
        false
    }
}