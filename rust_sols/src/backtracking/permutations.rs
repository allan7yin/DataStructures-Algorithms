use std::collections::VecDeque;
pub struct Solution {}

impl Solution {
    pub fn permute(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut result: Vec<Vec<i32>> = vec![];
        let mut queue: VecDeque<i32> = nums.into_iter().collect();

        fn dfs(queue: &mut VecDeque<i32>, result: &mut Vec<Vec<i32>>) {
            if queue.len() == 1 {
                if let Some(front) = queue.pop_front() {
                    return vec![vec![front]];
                }
            }

            for i in 0..queue.len() {
                if let Some(front) = queue.pop_front() {
                    let sub_perms: Vec<Vec<i32>> = dfs(queue, result);
                    for perm in &sub_perms {
                        perm.push(front);
                    }

                    result.extend(sub_perms);
                    queue.push_back(front);
                }
            }
        }
        dfs(&mut queue, &mut result);
        result
    }
}
