use core::cmp::max

struct Solution {}

impl Solution {
    pub fn trap(height: Vec<i32>) -> i32 {
        let (mut l, mut r) = (0, height.len() - 1);
        let (mut leftMax, mut rightMax) = (height[l], height[r]);
        let mut count = 0;

        while l < r {
            if leftMax < rightMax {
                l += 1;
                leftMax = max(leftMax, height[l]);
                count += (leftMax - height[l]);
            } else {
                r -= 1;
                rightMax = max(rightMax, height[r]);
                count += (rightMax - height[r]);
            }
        }
        count
    }
}
