use std::cmp::max;

pub struct Solution {}

impl Solution {
    pub fn longest_common_subsequence(text1: String, text2: String) -> i32 {
        let text1: &[u8] = text1.as_bytes();
        let text2: &[u8] = text2.as_bytes();
        let n = text1.len();
        let m = text2.len();
        let mut dp: Vec<Vec<i32>> = vec![vec![0; m + 1]; n + 1];

        for i in (0..n).rev() {
            for j in (0..m).rev() {
                if text1[i] == text2[j] {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }
        dp[0][0]
    }
}
