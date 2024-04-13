pub struct Solution {}


/*
 * While we solve this question with D&C in class, not the best way to approach
 * this problem, especially in the interest of time and how error prone dnc
 * can potentially be. 
 *
 * To solve this problem, we will use a motonically increasing stack of pairs
 */
impl Solution {
    pub fn largest_rectangle_area(heights: Vec<i32>) -> i32 {
        let mut maxArea = heights[0];
        let mut stack: Vec<(i32, usize)> = vec![];
        stack.push((heights[0], 0));

        for i in 1..heights.len() {
            let mut start = i;
            while !stack.is_empty() && stack.last().unwrap().0 > heights[i] {
                // update the max maxArea
                let top = stack.pop().unwrap();
                maxArea = max(maxArea, top.0 * (i - top.1) as i32);
                start = top.1;
            }
            stack.push((heights[i], start));
        }
        // go back and pop everything, and find 
        for pair in &stack {
            maxArea = max(maxArea, pair.0 * (heights.len() - pair.1) as i32);
        }
        maxArea
    }
}
