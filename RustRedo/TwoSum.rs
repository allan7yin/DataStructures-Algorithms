use std::collections::HashMap;

// hashmap's key and value, are copies. That is why the key must either have .clone() or .copy()
impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut map: HashMap<i32, usize> = HashMap::new();

        for i in 0..nums.len() {
            match map.get(&(target - nums[i])) {
                Some(&prev_index) => {
                    return vec![prev_index as i32, i as i32] // how to type cast
                }
                None => {
                    map.insert(nums[i],i);
                }
            }
        }
        vec![]
    }
}

// This is now when we use .iter(). The .iter() returns an iterator tat yields references to the elements in the collection
impl Solution2 {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut map: HashMap<i32, usize> = HashMap::new();

        // this is enumerate method in Rust. 
        for (index, num) in nums.iter().enumerate() {
            match map.get(&(target - num)) {
                Some(&prev_index) => {
                    return vec![prev_index as i32, index as i32]
                }
                None => {
                    map.insert(*num,index); // since num is &i32, we need to dereference it, this does not change ownership
                }
            }
        }
        vec![]
    }
}

// the below is one using enumerate -> into_iter(), bad since this consumes the vec, takes ownership, so nums is gone after the loop
impl Solution3 {
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