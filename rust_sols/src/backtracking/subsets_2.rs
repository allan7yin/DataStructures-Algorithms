use std::collections::HashSet;
pub struct Solution {}

/*
 * This problem should be eaiser to do than the Subets 1, as we are now allowed
 * to have duplicte values in a subset.
 *
 * To solve this, we just follow the standard backtracking techniques
 */
impl Solution {
    pub fn subsets_with_dup(mut nums: Vec<i32>) -> Vec<Vec<i32>> {
        nums.sort();
        let mut added: HashSet<Vec<i32>> = HashSet::new();
        let mut result: Vec<Vec<i32>> = vec![];
        let mut buffer: Vec<i32> = vec![];

        fn dfs(
            index: usize,
            nums: &Vec<i32>,
            buffer: &mut Vec<i32>,
            result: &mut Vec<Vec<i32>>,
            added: &mut HashSet<Vec<i32>>,
        ) {
            if index == nums.len() {
                if !added.contains(buffer) {
                    // push the buffer into the result
                    result.push(buffer.clone());
                    added.insert(buffer.clone());
                }
                return;
            }

            buffer.push(nums[index]);
            dfs(index + 1, nums, buffer, result, added);

            buffer.pop();
            dfs(index + 1, nums, buffer, result, added);
        }

        dfs(0, &nums, &mut buffer, &mut result, &mut added);
        result
    }
}
