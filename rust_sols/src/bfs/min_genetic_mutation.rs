use std::collections::{HashSet, VecDeque};

/*
First idea is sort of the brute force idea -> we create a map, making an edge between 2 strings that only differ
by one character. Then, we'll do a naive BFS, checking if each string is endGame. If none are, then we can't reach it

This will be O(mn^2) -> slow. Look for better solu8tion

The better solution is to rely on the fact that each word is always 8 characters long, and that there are only 4 possible characters.
So, trying to see if replacing a character with everh poss. char, and seeing if is valid gene, is a constant time: 8*4*O(n) -> 32o(n) ->O(n)
*/
pub struct Solution {}

impl Solution {
    pub fn min_mutation(start_gene: String, end_gene: String, mut bank: Vec<String>) -> i32 {}
}
