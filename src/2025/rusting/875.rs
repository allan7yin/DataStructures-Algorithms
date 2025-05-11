struct Solution;

/*
The idea behind this is just binary search the posible solutions
*/
impl Solution {
    pub fn min_eating_speed(piles: Vec<i32>, h: i32) -> i32 {
        let mut l: i64 = 1;
        let mut r: i64 = *piles.iter().max().unwrap() as i64;
        let mut res = r;

        while l <= r {
            let m = l + (r - l) / 2;
            let time_needed = Solution::time(&piles, m as f64);
            if time_needed <= h as i64 { // something to remember, Rust will not do automatic type converion
                res = res.min(m);
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        res as i32
    }

    fn time(piles: &Vec<i32>, h: f64) -> i64 {
        // want ceil(piles[i] / h) summed together
        piles.iter()
            .map(|&pile| (pile as f64 / h).ceil() as i64)
            .sum()
    }
}

fn main() {
    let piles = vec![805306368,805306368,805306368];
    println!("{}", Solution::min_eating_speed(piles, 1000000000));
}