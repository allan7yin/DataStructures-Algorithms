use std::cmp::max;

struct Solution {}

impl Solution {
    pub fn largest_rectangle_area(heights: Vec<i32>) -> i32 {
        let mut max_area: i32 = 0;
        let mut st: Vec<(i32, usize)> = vec![];

        for (i, &height) in heights.iter().enumerate() {
            let mut start = i;
            while let Some(&(last_height, index)) = st.last() {
                if height > last_height {
                    break;
                }

                start = index;
                let area = (i - index) as i32 * last_height;
                max_area = max(max_area, area);
                st.pop();
            }

            st.push((height, start));
        }

        // while some remaining heights --> an monotonically increasing one
        while let Some((height, index)) = st.last() {
            max_area = max(max_area, (heights.len() - index) as i32 * height);
            st.pop();
        }

        max_area
    }
}


fn main() {
    let heights = vec![2, 1, 5, 6, 2, 3];
    let solution = Solution {};
    let result = solution.largest_rectangle_area(heights);
    println!("Largest rectangle area: {}", result);
}