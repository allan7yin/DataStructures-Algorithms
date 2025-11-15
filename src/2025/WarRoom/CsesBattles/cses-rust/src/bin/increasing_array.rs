use cses_rust::{read_line_elements, read_single_element};

fn main() {
    let _n = read_single_element::<i64>();
    let mut nums = read_line_elements::<i64>(' ');
    let mut moves = 0;
    for i in 1..nums.len() {
        if nums[i] < nums[i-1] {
            moves += nums[i-1] - nums[i];
            nums[i] = nums[i-1];
        }
    }

    println!("{}", moves);
}