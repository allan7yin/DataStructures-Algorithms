impl Solution {
    pub fn min_remove_to_make_valid(s: String) -> String {
        let mut result = vec![];
        let mut stackCount = 0;

        for ch in s.chars() {
            if ch == '(' {
                // incrementing this counter simulates pushing something onto the stack 
                stackCount += 1;
            } else if ch == ')' {
                if stackCount > 0 {
                    // meaning there is corresponding '(' 
                    stackCount -= 1;
                } else {
                    continue;
                }
            }
            result.push(ch);
        }

        let mut result2 = String::new();

        stackCount = 0;
        for ch in result.iter().rev() {
            let ch = *ch;
            if ch == ')' {
                // incrementing this counter simulates pushing something onto the stack 
                stackCount += 1;
            } else if ch == '(' {
                if stackCount > 0 {
                    // meaning there is corresponding '(' 
                    stackCount -= 1;
                } else {
                    continue;
                }
            }
            result2.push(ch);
        }
        let sol_v: Vec<char> = result2.chars().rev().collect();
        let sol_s = sol_v.into_iter().collect();
        sol_s
    }
}