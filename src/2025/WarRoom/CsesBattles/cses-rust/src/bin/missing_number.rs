use cses_rust::{read_single_element, read_line_elements};
use std::collections::HashSet;

fn main() {
    let x = read_single_element::<i64>();
    let numbers = read_line_elements::<i64>(' ');
    let mut set = HashSet::new();
    
    for i in 1..=x {
        set.insert(i);
    }
    
    for num in numbers {
        set.remove(&num);
    }

    let element = match set.len() {
        1 => set.into_iter().next().unwrap(),
        _ => panic!("Set doesn't have exactly one element"),
    };
    
    println!("{}", element);
}