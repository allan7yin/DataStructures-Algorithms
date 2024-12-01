use std::rc::Rc;
use std::cell::RefCell;
use crate::trees::{Solution, TreeNode};

impl Solution {
    pub fn is_subtree(root: Option<Rc<RefCell<TreeNode>>>, sub_root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        if let (Some(root_val), Some(sub_root_val)) = (&root, &sub_root) {
            if Self::is_same_tree(Some(root_val.clone()), Some(sub_root_val.clone())) {
                return true;
            } else {
                return Self::is_subtree(root_val.borrow().left.clone(), Some(sub_root_val.clone())) || Self::is_subtree(root_val.borrow().right.clone(), Some(sub_root_val.clone()));
            }
        }
        false
    }
}