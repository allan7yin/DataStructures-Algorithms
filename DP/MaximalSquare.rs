use std::cmp::{min, max};

pub struct Solution {}

impl Solution {
    pub fn maximal_square(matrix: Vec<Vec<char>>) -> i32 {
        let n = matrix.len();
        let m = matrix[0].len();
        let mut cache: Vec<Vec<i32>> = vec![vec![0;m+1];n+1];
        let mut maxDim = 0;

        for i in (0..n).rev() {
            for j in (0..m).rev() {
                if matrix[i][j] = 1 {
                    cache[i][j] = 1 + min(cache[i+1][j], 
                                      min(cache[i][j+1], cache[i+1][j+1]));
                    maxDim = max(maxDim, cache[i][j]);

                }
            }
        }
        maxDim * maxDim
    }
}
