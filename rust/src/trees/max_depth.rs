use std::rc::Rc;
use std::cell::RefCell;

use crate::trees::{TreeNode, Solution};

impl Solution {
    pub fn max_depth(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        if let Some(value) = root {
            let node = value.borrow();
            let left_depth = Self::max_depth(node.left.clone());
            let right_depth = Self::max_depth(node.right.clone());
            1 + std::cmp::max(left_depth, right_depth)
        } else {
            0
        }
    }
}