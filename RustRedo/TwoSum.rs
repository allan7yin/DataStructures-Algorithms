use std::collections::HashMap;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut map: HashMap<i32, usize> = HashMap::new();

        // this is enumerate method in Rust. 
        for (index, num) in nums.into_iter().enumerate() {
            match map.get(&(target - num)) {
                Some(&prev_index) => {
                    return vec![prev_index as i32, index as i32]
                }
                None => {
                    map.insert(num,index);
                }
            }
        }
        vec![]
    }
}