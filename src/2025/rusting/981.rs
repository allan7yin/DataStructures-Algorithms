use std::collections::HashMap;

struct TimeMap {
    mp: HashMap<String, Vec<(i32, String)>>
}

impl TimeMap {
    fn new() -> Self {
        TimeMap {
            mp: HashMap::new()
        }
    }
    
    // Stores the key `key` with the value `value` at the given timestamp
    fn set(&mut self, key: String, value: String, timestamp: i32) {
        self.mp.entry(key).or_insert_with(Vec::new).push((timestamp, value));
    }
    
    // get the largest prev_timestamp such that prev_timestamp <= timestamp 
    fn get(&self, key: String, timestamp: i32) -> String {
        if let Some(values) = self.mp.get(&key) {
            // Handle empty vector case
            if values.is_empty() {
                return String::from("");
            }
            
            let (mut l, mut r) =(0, values.len() as i32 - 1);
            let mut result = String::from("");

            while l <= r {
                let m = l + (r - l) / 2;
                if values[m as usize].0 <= timestamp {
                    result = values[m as usize].1.clone();
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }

            result
        } else {
            String::from("")
        }
    }
}