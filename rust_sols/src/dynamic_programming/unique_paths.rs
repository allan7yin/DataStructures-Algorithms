pub struct Solution {}
/*
Review DP - this is classic instance of tabulation
*/
impl Solution {
    pub fn unique_paths(m: i32, n: i32) -> i32 {
        let m: usize = m as usize;
        let n: usize = n as usize;
        let mut dp: Vec<Vec<i32>> = vec![vec![0; n + 1]; m + 1];
        for i in 1..=m {
            for j in 1..=n {
                if i == 1 && j == 1 {
                    // base case
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        dp[m][n]
    }
}
