use std::cmp::min;

pub struct Solution {}

/*
- The initial idea is that we maintain a the first and second smallest values in a row, along with their index
- This way, for the i+1 row, we will always add the smallest value in the above row that is not in the same column
- If they are, we can just add the second smallest one, which is guaranteed to be in a different column
*/

impl Solution {
    pub fn min_falling_path_sum(mut grid: Vec<Vec<i32>>) -> i32 {
        let mut min_pairs: Vec<(i32, usize, i32, usize)> = vec![(0, 0, 0, 1)];
        for i in 0..grid.len() {
            let mut row = &mut grid[i];
            let mut smallest: i32 = i32::MAX;
            let mut smallest_index: usize = 0;
            let mut second_smallest: i32 = i32::MAX;
            let mut second_smallest_index: usize = 0;

            // add min_pairs.last() onto the current row
            // in this loop, we also track the smallest and second smallest values in this row
            for j in 0..row.len() {
                if let Some(last) = min_pairs.last() {
                    let temp = *last;
                    if j != temp.1 {
                        row[j] += temp.0;
                    } else {
                        row[j] += temp.2;
                    }

                    // assign smallest and second_smallest
                    if row[j] < smallest {
                        smallest = row[j];
                        smallest_index = j;
                    } else if row[j] < second_smallest {
                        second_smallest = row[j];
                        second_smallest_index = j;
                    }
                }
            }

            // push onto the min_pairs
            min_pairs.push((
                smallest,
                smallest_index,
                second_smallest,
                second_smallest_index,
            ));
        }

        // now find the min sum
        min_pairs.last().unwrap().0
    }
}
