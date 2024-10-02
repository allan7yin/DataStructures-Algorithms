impl Solution {
    pub fn make_good(s: String) -> String {
        let mut i = 0;
        let mut s = s.chars().collect::<Vec<char>>();
        while i < s.len() - 1 && s.len() != 0
        {
            if s[i].to_lowercase().to_string() == s[i + 1].to_lowercase().to_string() {
                if (s[i].is_lowercase() && s[i + 1].is_uppercase()) ||
                   (s[i].is_uppercase() && s[i + 1].is_lowercase())
                {
                    s.remove(i);
                    s.remove(i);
                    i = match i > 0 {
                        true  => i - 1,
                        false => 0,
                    };
                    continue;
                }
            }
            i += 1;
        }

        // implicit return here, last line is returned, needs to match function return type
        s.iter().collect::<String>()
    }
}