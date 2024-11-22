use std::cmp::max;

impl Solution {
    pub fn minimized_maximum(n: i32, quantities: Vec<i32>) -> i32 {
        let mut l = 1;
        let mut r = 0;

        for &num in quantities.iter() {
            r = max(r, num);
        }

        let mut result = -1;
        while l <= r {
            let mut m = l + (r - l) / 2;
            let mut temp = 0;
            for &num in quantities.iter() {
                temp += (num as f64 / m as f64).ceil() as i32;
            }

            if (temp <= n) {
                result = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        result
    }
}
