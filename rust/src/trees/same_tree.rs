use crate::trees::{Solution, TreeNode};
use std::rc::Rc;
use std::cell::RefCell;


impl Solution {
    pub fn is_same_tree(p: Option<Rc<RefCell<TreeNode>>>, q: Option<Rc<RefCell<TreeNode>>>) -> bool {
        if let (Some(p_val), Some(q_val)) = (&p, &q) {
            let left = Self::is_same_tree(p_val.borrow().left.clone(), q_val.borrow().left.clone());
            let right = Self::is_same_tree(p_val.borrow().right.clone(), q_val.borrow().right.clone());

            left && right && (p_val.borrow().val == q_val.borrow().val)
        } else {
            p.is_none() && q.is_none()
        }
    }
}