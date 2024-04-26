use std::cmp::min;

pub struct Solution {}

/*
- The initial idea is that we maintain a the first and second smallest values in a row, along with their index
- This way, for the i+1 row, we will always add the smallest value in the above row that is not in the same column
- If they are, we can just add the second smallest one, which is guaranteed to be in a different column
*/

impl Solution {
    pub fn min_falling_path_sum(mut grid: Vec<Vec<i32>>) -> i32 {
        let mut prev_values: Vec<(i32, usize, i32, usize)> = vec![];
        for i in 0..grid.len() {
            let mut row: &mut Vec<i32> = &mut grid[i];
            let mut smallest: i32 = row[0];
            let mut smallest_index: usize = 0;
            let mut second_smallest: i32 = row[0];
            let mut second_smallest_index: usize = 0;

            for j in 0..row.len() {
                if row[j] < smallest {
                    smallest = row[j];
                    smallest_index = j;
                } else if row[j] < second_smallest {
                    second_smallest = row[j];
                    second_smallest_index = j;
                }
            }
            if i == 0 {
                //means the first row, add to prev_values and continue
                prev_values.push((
                    smallest,
                    smallest_index,
                    second_smallest,
                    second_smallest_index,
                ));
                continue;
            }
            // we have 2 smallest ones, we now populate these as tuples into dp
            for j in 0..row.len() {
                if let Some(last_row) = prev_values.last() {
                    let temp = *last_row;
                    if j == temp.1 {
                        row[j] += temp.0;
                    } else {
                        row[j] += temp.2; // Use second_smallest instead of smallest
                    }
                }
            }
        }

        // return the min value inside of last row in grid
        let mut min_sum = i32::MAX;
        for num in &grid[grid.len() - 1] {
            min_sum = min(min_sum, *num);
        }

        min_sum
    }
}
