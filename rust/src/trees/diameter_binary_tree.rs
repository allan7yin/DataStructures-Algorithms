use std::rc::Rc;
use std::cell::RefCell;
use crate::trees::{Solution, TreeNode};

impl Solution {
    pub fn diameter_of_binary_tree(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        // diamater of a binary tree is the longest distance between 2 nodes in a binary tree
        let mut diameter = 0;
        Self::f(root, &mut diameter);
        diameter
    }

    fn f(curr: Option<Rc<RefCell<TreeNode>>>, depth: &mut i32) -> i32 {
        if let Some(node) = curr {
            let mut borrowd_node = node.borrow();
            let max_left = Self::f(borrowd_node.left.clone(), depth);
            let max_right = Self::f(borrowd_node.right.clone(), depth);
            *depth = std::cmp::max(*depth, max_left + max_right);
            std::cmp::max(max_left, max_right) + 1
        } else {
            0
        }
    }
}
