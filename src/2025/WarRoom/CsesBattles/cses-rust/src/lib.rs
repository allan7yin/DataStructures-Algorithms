use std::fmt::Debug;
use std::io::{self};
use std::str::FromStr;

pub fn read_line_elements<T>(delimiter: char) -> Vec<T>
where
T: FromStr,
T::Err: Debug,
{
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();

    input.trim()
        .split(delimiter)
        .filter_map(|x| {
            let trimmed = x.trim();
            if trimmed.is_empty() { None } else { Some(trimmed.parse().unwrap()) }
        })
        .collect()
}

pub fn read_single_element<T>() -> T
where 
    T: FromStr,
    T::Err: Debug,
{
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    input.trim().parse().unwrap()
}