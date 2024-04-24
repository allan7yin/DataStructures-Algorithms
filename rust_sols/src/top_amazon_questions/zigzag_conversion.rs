pub struct Solution;

impl Solution {
    pub fn convert(s: String, num_rows: i32) -> String {
        if num_rows == 1 {
            return s;
        }
        let mut rows: Vec<Vec<char>> = vec![vec![]; num_rows as usize];
        let mut reverse: bool = false;
        let mut index: usize = 0;

        for ch in s.chars() {
            if index == num_rows as usize - 1 {
                reverse = true;
            }

            if index == 0 {
                reverse = false;
            }

            rows[index].push(ch);
            if reverse {
                index -= 1;
            } else {
                index += 1;
            }
        }

        let mut result: String = String::new();
        for row in &rows {
            let temp: String = row.into_iter().collect();
            result += &temp;
        }

        result
    }
}
