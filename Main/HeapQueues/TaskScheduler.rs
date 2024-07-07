use std::cmp::Reverse;
use std::collections::BinaryHeap;
use std::collections::VecDeque;

// this is a re-write of the above question in Rust
struct Solution {}

impl Solution {
    pub fn least_interval(tasks: Vec<char>, n: i32) -> i32 {
        let mut queue: VecDeque<(i32, i32)> = VecDeque::new();
        let mut freq: Vec<i32> = vec![0; 26];
        // create a frequency map
        for ch in &tasks {
          freq[ch-'A']++;
        }
        let mut max_heap: BinaryHeap<Reverse<i32>> = BinaryHeap::from(freq);
        let mut time = 0;

        while (!queue.is_empty() || !max_heap.is_empty()) {
          time++;
          if let mut Some(top) = max_heap.pop() {
            queue.push((top, time + n));
          } else {
            time = queue.front().2;
          }

          // now, pop all that are now free in this time
          while !queue.is_empty() && queue.front().unwrap().1 == time {
            max_heap.push(queue.pop().unwrap().1);
          }
        }
        time
    }
}
