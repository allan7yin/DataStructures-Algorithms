use std::collections::{HashMap, HashSet};
// create a hashmap from the graph, to map the edges, and add everything into a set
// then at the end, we can just

struct Solution {}

impl Solution {
    // this is quiot
    pub fn valid_path_dfs(n: i32, edges: Vec<Vec<i32>>, source: i32, destination: i32) -> bool {
        if source == destination {
            return true;
        }
        let mut edge_map: HashMap<i32, Vec<i32>> = HashMap::new();
        let mut visited: HashSet<i32> = HashSet::new();
        let mut stack: Vec<i32> = vec![];

        // populate the hashmap
        for edge in &edges {
            edge_map.entry(edge[0]).or_insert(Vec::new()).push(edge[1]);
            edge_map.entry(edge[1]).or_insert(Vec::new()).push(edge[0]);
        }

        // do dfs with a stack
        stack.push(source);
        while !stack.is_empty() {
            if let Some(top) = stack.pop() {
                if visited.contains(&top) || !edge_map.contains_key(&top) {
                    continue;
                }
                visited.insert(top);

                if top == destination {
                    break;
                }
                for node in &edge_map[&top] {
                    stack.push(*node);
                }
            }
        }
        return visited.contains(&destination);
    }
}
