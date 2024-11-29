use std::rc::Rc;
use std::cell::RefCell;

use crate::trees::{Solution, TreeNode};

impl Solution {
    pub fn is_balanced(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        let mut cond = true;
        Self::height(root, &mut cond);
        cond
    }

    pub fn height(curr: Option<Rc<RefCell<TreeNode>>>, cond: &mut bool) -> i32 {
        if let Some(value) = curr {
            let left_height = Self::height(value.borrow().left.clone(), cond);
            let right_height = Self::height(value.borrow().right.clone(), cond);

            if (left_height - right_height).abs() > 1 {
                *cond = false;
            }

            return 1 + std::cmp::max(left_height, right_height);
        }
        0
    }
}