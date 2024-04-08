impl Solution {
    pub fn check_valid_string(s: String) -> bool {
        let mut leftMin = 0;
        let mut leftMax = 0;

        for ch in s.chars() {
            match ch {
                '(' => {
                    leftMin += 1;
                    leftMax += 1;
                },
                ')' => {
                    leftMin -= 1;
                    leftMax -= 1;
                },
                _ => {
                    leftMin -= 1;
                    leftMax += 1;
                }
            };
            if leftMax < 0 {
                return false;
            }
            if leftMin < 0 {
                leftMin = 0;
            }
        }
        leftMin == 0
    }
}