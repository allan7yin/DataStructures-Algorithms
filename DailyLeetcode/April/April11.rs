// remember, this is a monotonically increasing stack 
// want to maintain a k-sized monotonically increasing stack
impl Solution {
    pub fn remove_kdigits(num: String, mut k: i32) -> String {
        let mut stack: Vec<char> = vec![];

        for ch in num.chars() {
            while !stack.is_empty() && *stack.last().unwrap() > ch && k > 0 {
                k -= 1;
                stack.pop();
            }

            if stack.len() == 1 && *stack.last().unwrap() == '0' {
                stack.pop();
            }
            stack.push(ch);
        }

        while k > 0 && !stack.is_empty() {
            // say after the above, we are left with 5432222 and this is more than num.len() - k
            // we need to cut the end off, as the first k will be smallest possible, as this is in ascending order
            stack.pop();
            k -= 1;
        }
        if stack.is_empty() {
            return String::from("0");
        }
        String::from_iter(stack)
    }
}