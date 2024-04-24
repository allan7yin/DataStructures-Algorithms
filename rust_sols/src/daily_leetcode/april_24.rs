use std::collections::VecDeque;
pub struct Solution {}
/*
Could do DP or Queue. Since this is an easy question, let's do both of them.
*/
impl Solution {
    // this is the tabulation dp method
    pub fn tribonacci_dp(n: i32) -> i32 {
        match n {
            0 => return 0,
            1 | 2 => return 1,
            _ => (),
        }
        let mut dp: Vec<i32> = vec![0; n as usize + 1];
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;

        for i in 3..dp.len() {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }
        dp[n as usize]
    }

    // this is the queue method
    pub fn tribonacci_queue(n: i32) -> i32 {
        match n {
            0 => return 0,
            1 | 2 => return 1,
            _ => (),
        }
        let mut queue: VecDeque<i32> = VecDeque::new();
        let mut val: i32 = 2;
        queue.push_back(0);
        queue.push_back(1);
        queue.push_back(1);
        for i in 3..n {
            queue.push_back(val);
            if let Some(first) = queue.pop_front() {
                val = val + (val - first);
            }
        }
        val
    }
}
