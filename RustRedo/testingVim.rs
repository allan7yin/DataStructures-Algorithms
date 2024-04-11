pub struct Solution{}

impl Solution {
    pub fn reverse(mut x: i32) -> bool {
        let mut result = 0;
        let mut flag = false;
        if x < 0 {
            x *= (-1)
            flag = true;
        }

        while x > 0 {
            let mut last = x % 10;
            result = (result * 10) + last;
            x /= 10;
        }

        if flag {
            result *= -1;
        }
        result
    }
}

fn main () {
    
}
