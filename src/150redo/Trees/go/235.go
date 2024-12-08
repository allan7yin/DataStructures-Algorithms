package trees

// Definition for a binary tree node
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
	if q.Val < p.Val {
		temp := p
		p = q
		q = temp
	}

	return dfs(root, p, q)
}

func dfs(root, p, q *TreeNode) *TreeNode {
	if root == nil {
		return root
	}
	if p.Val <= root.Val && root.Val <= q.Val {
		return root
	} else if p.Val > root.Val {
		return dfs(root.Right, p, q)
	} else {
		return dfs(root.Left, p, q)
	}
}
