use std::collections::HashSet;
use std::cmp::max;

// whenever we have string, just collect the chars into a vector
impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let mut character_set = HashSet::new();
        let vector_s: Vec<char> = s.chars().collect();
        let mut l = 0;
        let mut max_length = 0;

        // now, why can't we use .into_iter() -> this consumes the vector's, and takes ownership of the vector's memory
        // So, this means that vector_s no longer owns that data, and cannot be accessed. So, will not compile 
        for (r, ch) in vector_s.iter().enumerate() {
            while character_set.contains(&ch) && l <= r {
                character_set.remove(&vector_s[l]); // Efficient removal with slice
                l += 1;
            }
            character_set.insert(ch);
            max_length = max(max_length, (r + 1) - l); // Accurate length calculation
        }
        max_length as i32
    }
}