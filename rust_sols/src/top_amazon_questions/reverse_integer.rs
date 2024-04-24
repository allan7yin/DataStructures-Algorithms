pub struct Solution {}

impl Solution {
    pub fn reverse(mut x: i32) -> i32 {
        // reverse, and check in each iteration if over
        let mut reversed: i32 = 0;
        let mut prev: i32 = reversed;
        while x != 0 {
            let ones: i32 = x % 10;
            reversed *= 10;
            reversed += ones;

            if prev != (reversed - ones) / 10 {
                return 0;
            }
            x /= 10;
            prev = reversed;
        }
        reversed
    }
}
