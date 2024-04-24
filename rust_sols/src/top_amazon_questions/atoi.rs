use std::collections::HashMap;
pub struct Solution {}

impl Solution {
    pub fn my_atoi(s: String) -> i32 {
        let mut digits: i32 = 0;
        let mut sign_read: bool = false;
        let mut is_leading_space: bool = true;
        let mut result: i32 = 0;
        let mut prev = result; // this is used to prevent overflow
        let mut negative: bool = false;
        let mut map: HashMap<char, i32> = HashMap::new();
        // let's populate this HashMap
        for i in 0..=9 {
            map.insert(('0' as u8 + i) as char, i as i32);
        }

        // now, let's go through the array and do this
        for ch in s.chars() {
            if is_leading_space && ch == ' ' {
                continue;
            } else {
                is_leading_space = false;
            }

            if map.contains_key(&ch) {
                if let Some(new_result) =
                    result.checked_mul(10).and_then(|r| r.checked_add(map[&ch]))
                {
                    println!("{}", new_result);
                    result = new_result;
                    digits += 1;
                } else {
                    // Integer overflow occurred
                    if negative {
                        return i32::MIN;
                    } else {
                        return i32::MAX;
                    }
                }
                prev = result;
            } else if ch == '-' && !sign_read && digits == 0 {
                negative = true;
                sign_read = true;
            } else if ch == '+' && !sign_read && digits == 0 {
                negative = false;
                sign_read = true;
            } else {
                break;
            }
        }

        if negative {
            result *= (-1);
        }
        result
    }
}
