use cses_rust::{read_single_element};

fn main() {
    let mut x = read_single_element::<i64>();
    while x != 1 {
        print!("{} ", x);
        if x % 2 == 0 {
            x /= 2;
        } else {
            x = x * 3 + 1;
        }
    }

    println!("{} ", 1);
}
