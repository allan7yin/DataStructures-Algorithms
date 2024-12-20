// probably a binary search problem
impl Solution {
    pub fn maximum_beauty(items: Vec<Vec<i32>>, queries: Vec<i32>) -> Vec<i32> {
        let mut result = vec![];
        let mut items = items;
        items.sort_by(|a, b| a[0].cmp(&b[0]));

        let mut temp = items[0][1];
        for item in items.iter_mut() {
            if item[1] > temp {
                temp = item[1];
            }

            item[1] = temp;
        }

        for &q in queries.iter() {
            let (mut l, mut r) = (0 as i32, (items.len() as i32) - 1);
            let mut maxBeauty = 0;

            while l <= r {
                let m = l + (r - l) / 2;
                if items[m as usize][0] <= q {
                    maxBeauty = std::cmp::max(items[m as usize][1], maxBeauty);
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
            result.push(maxBeauty);
        }
        result
    }
}
