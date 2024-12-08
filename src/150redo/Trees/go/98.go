package trees

import "math"

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isValidBST(root *TreeNode) bool {
	return f(root, math.MaxInt, math.MinInt)
}

func f(curr *TreeNode, maxVal int, minVal int) bool {
	if curr == nil {
		return true
	}

	if curr.Val >= maxVal || curr.Val <= minVal {
		return false
	}

	return f(curr.Left, curr.Val, minVal) && f(curr.Right, maxVal, curr.Val)
}
