use cses_rust::{read_single_element};
fn main() {
    let word = read_single_element::<String>();
    let mut max_length = 1;
    let mut count = 1;
    let mut prev_char = 'z';

    for ch in word.chars() {
        if ch == prev_char {
            count += 1;
        } else {
            count = 1;
        }

        prev_char = ch;
        max_length = std::cmp::max(max_length, count);
    }

    println!("{}", max_length);
}