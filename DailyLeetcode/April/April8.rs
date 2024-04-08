use std::collections::VecDeque;

impl Solution {
    pub fn count_students(students: Vec<i32>, sandwiches: Vec<i32>) -> i32 {
        let mut queue: VecDeque<i32> = VecDeque::from(students);
        let mut size = queue.len();
        let mut index = 0;

        while size > 0 && queue.len() > 0 {
            if let Some(top) = queue.front() {
                if *top == sandwiches[index] {
                    index += 1;
                    queue.pop_front();
                    size = queue.len();
                } else if let Some(top) = queue.pop_front() {
                    queue.push_back(top);
                    size -= 1;
                }
            }
        }

        let mut sol: i32 = queue.len() as i32;
        sol

    }
}