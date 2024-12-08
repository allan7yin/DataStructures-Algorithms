package trees

func kthSmallest(root *TreeNode, k int) int {
	var result *TreeNode
	count := 0
	var f func(curr *TreeNode)

	f = func(curr *TreeNode) {
		if curr == nil {
			return
		}

		f(curr.Left)
		count++
		if count == k {
			result = curr
		}
		f(curr.Right)
	}

	f(root)
	return result.Val
}
