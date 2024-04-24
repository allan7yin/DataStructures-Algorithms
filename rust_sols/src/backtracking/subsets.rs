pub struct Solution {}
impl Solution {
    pub fn combination_sum(candidates: Vec<i32>, target: i32) -> Vec<Vec<i32>> {
        let mut result: Vec<Vec<i32>> = vec![];
        let mut elements: Vec<i32> = vec![];

        fn dfs(
            index: usize,
            candidates: &Vec<i32>,
            result: &mut Vec<Vec<i32>>,
            elements: &mut Vec<i32>,
            target: i32,
            path_sum: i32,
        ) {
            if path_sum == target {
                result.push(elements.clone());
                return;
            }

            if index == candidates.len() {
                return;
            }

            let current = candidates[index];

            if path_sum < target {
                elements.push(current);
                dfs(
                    index,
                    candidates,
                    result,
                    elements,
                    target,
                    path_sum + current,
                );

                elements.pop();
                dfs(index + 1, candidates, result, elements, target, path_sum);
            } else {
                return;
            }
        }

        dfs(0, &candidates, &mut result, &mut elements, target, 0);
        result
    }
}
