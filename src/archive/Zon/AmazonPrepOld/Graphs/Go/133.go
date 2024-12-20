package graphs

type Node struct {
	Val       int
	Neighbors []*Node
}

func cloneGraph(node *Node) *Node {
	if node == nil {
		return node
	}
	mp := make(map[*Node]*Node)
	return f(node, mp)
}

func f(node *Node, mp map[*Node]*Node) *Node {
	if val, exists := mp[node]; exists {
		return val
	}

	newNode := &Node{Val: node.Val}
	mp[node] = newNode
	for _, neighbour := range node.Neighbors {
		newNode.Neighbors = append(newNode.Neighbors, f(neighbour, mp))
	}
	return newNode
}
