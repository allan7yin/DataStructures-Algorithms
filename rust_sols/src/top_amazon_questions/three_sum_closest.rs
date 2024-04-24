use std::cmp::min;

pub struct Solution {}

impl Solution {
    pub fn three_sum_closest(mut nums: Vec<i32>, target: i32) -> i32 {
        let mut sum = 0;
        let mut min_distance: i32 = i32::MAX;
        // basically the same idea as 3Sum
        nums.sort();
        for i in 0..nums.len() {
            let (mut l, mut r) = (i + 1, nums.len() - 1);
            while l < r {
                let temp = (target - nums[i] - nums[l] - nums[r]).abs();
                if temp < min_distance {
                    min_distance = temp;
                    sum = nums[i] + nums[l] + nums[r];
                }
                
                if nums[l] + nums[r] + nums[i] > target {
                    r-=1;
                } else {
                    l+=1;
                }
            }
        }
        sum
    }
}

