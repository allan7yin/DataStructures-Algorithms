use std::cmp::max;


pub struct Solution {}
/*
 * We solve this with memoization top-down DP 
 * - Recall the largest rectangle area in histogram question. We can use that 
 *   here. Each row in the matrix, we maintain the height of each column, just 
 *   like a histogram. Than, we can try calling function every row. 
 */
use std::cmp::max;

impl Solution {
    pub fn maximal_rectangle(matrix: Vec<Vec<char>>) -> i32 {
        // basically, from first row to last of matrix, make a histogram
        let mut maxRect = 0;
        let mut heights: Vec<i32> = vec![0; matrix[0].len()];
        for row in &matrix {
            for i in 0..row.len() {
                match row[i] {
                    '1' => heights[i] += 1,
                    _ => heights[i] = 0,
                }
            }
            // now call the below helper function 
            maxRect = max(maxRect, Solution::find_max_area(&heights));
            println!("{}", maxRect);
        }
        maxRect
    }

    pub fn find_max_area(heights: &Vec<i32>) -> i32 {
        let mut maxArea = heights[0];
        let mut stack: Vec<(i32, usize)> = vec![];
        stack.push((heights[0], 0));

        for i in 1..heights.len() {
            let mut start = i;
            while !stack.is_empty() && stack.last().unwrap().0 > heights[i] {
                let top = stack.pop().unwrap();
                maxArea = max(maxArea, top.0 * (i - top.1) as i32);
                start = top.1;
            }

            stack.push((heights[i], start));    
        }

        // now pop the ones at the end 
        for pair in &stack {
            maxArea = max(maxArea, pair.0 * (heights.len() - pair.1) as i32);
        }
        maxArea
    }
}
