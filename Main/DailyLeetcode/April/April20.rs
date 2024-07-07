/*
This is another example of a classic of a dfs problem.
We will call it from every square, and if it is a one, go in a dfs.

This is the second time doing this -> first time is in c++
*/
pub struct Solution {};

impl Solution {
    pub fn find_farmland(mut land: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
      let mut result: Vec<Vec<i32>> = vec![];
      for i in 0..land.len() {
        for j in 0..land[0].len() {
          if land[i][j] == 1 { // check if I need the == 1 after
          let bottom_corner = Self::dfs(&mut land, i, j);
            let group = vec![i as i32, j as i32, bottom_corner[0] as i32, bottom_corner[1] as i32];
            result.push(group);
          }
        }
      }
      result
    }

    fn dfs(land: &mut Vec<Vec<i32>>, i: usize, j: usize) -> Vec<i32> {
      if (i < 0 || i >= land.len() || j < 0 || j >= land[0].len() || land[i][j] != 1) {
        return vec![];
      }

      // mark this place as visited
      land[i][j] = -1;
      // corner piece base case -> check if next 2 are both empty vectors (to the right, and below)
      let bottom = Self::dfs(land, i + 1, j);
      let right = Self::dfs(land, i, j + 1);

      if bottom.len() == 0 && right.len() == 0 {
        // this is the bottom right corner
        return vec![i as i32, j as i32];
      } else if bottom.len() == 0 {
        return right;
      } else {
        return bottom;
      }
    }
}
