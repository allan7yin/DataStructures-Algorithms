package trees

func buildTree(preorder []int, inorder []int) *TreeNode {
	if len(preorder) == 0 || len(inorder) == 0 {
		return nil
	}

	root := preorder[0]
	rootNode := &TreeNode{Val: root}

	size := 0
	for i, node := range inorder {
		if node == root {
			size = i
			break
		}
	}

	rootNode.Left = buildTree(preorder[1:size+1], inorder[0:size])
	rootNode.Right = buildTree(preorder[size+1:], inorder[size+1:])
	return rootNode
}
