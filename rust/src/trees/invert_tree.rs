use std::cell::RefCell;
use std::rc::Rc;
use crate::trees::{TreeNode, Solution};

impl Solution {
    pub fn invert_tree(node: Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
        if let Some(value) = node.clone() {
            let mut curr = value.borrow_mut();
            
            let temp = curr.left.clone();
            curr.left = curr.right.clone();
            curr.right = temp;
            
            if let Some(left) = curr.left.clone() {
                Solution::invert_tree(Some(left));
            }

            if let Some(right) = curr.right.clone() {
                Solution::invert_tree(Some(right));
            }
        }
        node
    }
}
