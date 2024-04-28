use std::cmp::max;
use std::collections::HashMap;
/*
- the initial idea is to do this recursively, while maintaining a hashmap
to cash the results, as we likely will need to use them again
*/
pub struct Solution {}

impl Solution {
    pub fn integer_break(n: i32) -> i32 {
        let mut cache: HashMap<i32, i32> = HashMap::new();
        fn helper(num: i32, cache: &mut HashMap<i32, i32>) -> i32 {
            let mut max_prod: i32 = 0;
            if cache.contains_key(&num) {
                return cache[&num];
            }

            for i in 0..num {
                max_prod = max(max_prod, helper(i, cache) * helper(num - i, cache));
            }
            cache.insert(num, max_prod);
            return max_prod;
        }
        helper(n, &mut cache)
    }
}
