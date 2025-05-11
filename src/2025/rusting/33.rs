struct Solution;

impl Solution {
    pub fn search(nums: Vec<i32>, target: i32) -> i32 {
        let (mut l, mut r) = (0, (nums.len() - 1) as i32);
        
        while l <= r {
            let m = l + (r - l) / 2;
            let middle_num = nums[m as usize];

            if target == middle_num {
                return m;
            }
            
            if nums[l as usize] <= middle_num {
                // this half is sorted
                if target >= nums[l as usize] && target < middle_num {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            } else {
                // right half is sorted
                if target > middle_num && target <= nums[r as usize] {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
        }

        -1
    }
}

// 6 7 0 1 2 4 5 

fn main() {
    let nums = vec![5,1,3];
    println!("{}", Solution::search(nums, 2));
}
