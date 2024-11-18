use std::collections::HashMap;

struct TimeMap {
    mp: HashMap<String, Vec<(i32, String)>>
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl TimeMap {
    fn new() -> Self {
        TimeMap {
            mp: HashMap::new(),
        }
    }
    
    fn set(&mut self, key: String, value: String, timestamp: i32) {
        self.mp.entry(key).or_default().push((timestamp, value));
    }
    
    fn get(&self, key: String, timestamp: i32) -> String {
        if let Some(values) = self.mp.get(&key) {
            let mut result = String::new();
            let mut l = 0;
            let mut r = values.len() as i32 - 1;

            while l <= r {
                let mut m = l + (r - l) / 2;
                if values[m as usize].0 <= timestamp {
                    result = values[m as usize].1.clone();
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
            
            result
        } else {
            String::new()
        }
    }
}

/**
 * Your TimeMap object will be instantiated and called as such:
 * let obj = TimeMap::new();
 * obj.set(key, value, timestamp);
 * let ret_2: String = obj.get(key, timestamp);
 */