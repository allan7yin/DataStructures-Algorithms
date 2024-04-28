pub struct Solution {}

impl Solution {
    pub fn generate(num_rows: i32) -> Vec<Vec<i32>> {
        let mut result: Vec<Vec<i32>> = vec![vec![1]];
        for i in 1..num_rows {
            let mut new_row: Vec<i32> = vec![1];
            if let Some(last_row) = result.last() {
                if last_row.len() > 1 {
                    for j in 0..last_row.len() - 1 {
                        new_row.push(last_row[j] + last_row[j + 1]);
                    }
                }
            }
            new_row.push(1);
            result.push(new_row)
        }
        result
    }
}
