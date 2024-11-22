use std::collections::VecDeque;

impl Solution {
    pub fn deck_revealed_increasing(mut deck: Vec<i32>) -> Vec<i32> {
        // first sort the vector
        deck.sort();
        let mut dq: VecDeque<i32> = VecDeque::new();

        while let Some(back) = deck.pop() {
            if let Some(back_q) = dq.pop_back() {
                dq.push_front(back_q);
            }
            dq.push_front(back);
        }

        dq.into_iter().collect()
    }
}