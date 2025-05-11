struct Solution;

impl Solution {
    pub fn search(nums: Vec<i32>, target: i32) -> i32 {
        if nums.is_empty() {
            return -1;
        }
        
        let mut l = 0;
        let mut r = nums.len() as i32 - 1;

        while l <= r {
            let m = l + (r - l) / 2;
            match nums[m as usize].cmp(&target) {
                std::cmp::Ordering::Equal => return m,
                std::cmp::Ordering::Less => l = m + 1,
                std::cmp::Ordering::Greater => r = m - 1,
            }
        }

        -1
    }
}