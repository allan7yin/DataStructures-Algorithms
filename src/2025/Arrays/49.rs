use std::collections::HashMap;

impl Solution {
    pub fn group_anagrams(strs: Vec<String>) -> Vec<Vec<String>> {
        let mut keys: HashMap<String, Vec<String>> = HashMap::new();
        for word in strs.iter() {
            let mut chars: Vec<char> = word.chars().collect();
            chars.sort();
            let key: String = chars.into_iter().collect();
            keys.entry(key).or_insert(vec![]).push(word.clone());
        }

        keys.into_values().collect()
    }
}