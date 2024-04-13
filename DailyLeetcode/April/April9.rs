use std::collections::VecDeque;

impl Solution {
    pub fn time_required_to_buy(tickets: Vec<i32>, k: i32) -> i32 {
        let mut queue: VecDeque<i32> = VecDeque::from(tickets);
        let mut time = 0;

        'outer: loop {
            for i in 0..queue.len() {
                if let Some(front) = queue.pop_front() {
                    if (front != 0) {
                        queue.push_back(front - 1);
                        time += 1;
                    } else {
                        queue.push_back(front);
                    }

                    if (i as i32 == k) {
                        if let Some(back) = queue.back() {
                            if *back == 0 {
                                // we are done, return from here
                                break 'outer;
                            }
                        }
                    }
                }
            }
        }
        time
    }
}
