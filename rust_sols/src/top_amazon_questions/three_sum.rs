pub struct Solution {}

impl Solution {
    pub fn three_sum(mut nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut result: Vec<Vec<i32>> = vec![];
        nums.sort();

        for i in 0..nums.len() {
            if i > 0 && nums[i - 1] == nums[i] {
                continue;
            }
            if nums[i] > 0 {
                break;
            }
            // make the current element the target
            let sub_target = -nums[i];
            let (mut l, mut r) = (i + 1, nums.len() - 1);

            while l < r {
                if nums[l] + nums[r] == sub_target {
                    result.push(vec![nums[l], nums[r], nums[i]]);
                    l += 1;
                    while l < r && nums[l] == nums[l - 1] {
                        l += 1;
                    }
                }

                if nums[l] + nums[r] > sub_target {
                    r -= 1;
                } else {
                    l += 1;
                }
            }
        }
        result
    }
}
