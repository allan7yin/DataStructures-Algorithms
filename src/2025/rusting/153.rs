struct Solution;

impl Solution {
    pub fn find_min(nums: Vec<i32>) -> i32 {
        let (mut l, mut r) = (0, (nums.len() - 1) as i32);
        
        while l < r {
            let m = l + (r - l) / 2;
            let middle = nums[m as usize];

            if middle > nums[r as usize] {
                l = m + 1;
            } else {
                r = m;
            }
        }

        nums[l as usize]
    }
}