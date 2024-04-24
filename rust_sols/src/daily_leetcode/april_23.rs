use std::collections::{HashMap, VecDeque};

struct Solution {}

impl Solution {
    pub fn find_min_height_trees(n: i32, edges: Vec<Vec<i32>>) -> Vec<i32> {
        let mut result: Vec<i32> = vec![];
        if n == 1 {
            result.push(0);
            return result;
        }
        let mut degree: Vec<i32> = vec![0; n as usize];
        let mut edge_map: HashMap<i32, Vec<i32>> = HashMap::new();
        // we want to count the number of edges connected to a node for each node in the tree
        for edge in &edges {
            degree[edge[0] as usize] += 1;
            degree[edge[1] as usize] += 1;

            // we also want to populate the edges map
            edge_map
                .entry(edge[0])
                .or_insert_with(Vec::new)
                .push(edge[1]);

            edge_map
                .entry(edge[1])
                .or_insert_with(Vec::new)
                .push(edge[0]);
        }

        // now, push all deg = 1 into a queue
        let mut queue: VecDeque<i32> = VecDeque::new();
        for i in 0..degree.len() {
            if degree[i] == 1 {
                queue.push_back(i as i32);
            }
        }

        let mut remaining: i32 = n;
        while !queue.is_empty() {
            let size = queue.len();
            remaining -= size as i32;
            for i in 0..size {
                if let Some(top) = queue.pop_front() {
                    if remaining == 0 {
                        result.push(top);
                    }

                    if let Some(neighbours) = edge_map.get_mut(&top) {
                        for val in neighbours.iter_mut() {
                            degree[*val as usize] -= 1;
                            if degree[*val as usize] == 1 {
                                queue.push_back(*val);
                            }
                        }
                    }
                }
            }
        }
        result
    }
}
