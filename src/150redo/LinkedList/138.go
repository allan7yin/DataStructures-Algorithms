package LinkedList

type Node struct {
	Val    int
	Next   *Node
	Random *Node
}

var (
	mp = make(map[*Node]*Node)
)

// look to perform deeop copy of this list
func copyRandomList(head *Node) *Node {
	return f(head)
}

func f(curr *Node) *Node {
	if value, ok := mp[curr]; ok {
		return value
	}

	if curr == nil {
		return nil
	}
	// make copy of this Node
	cpy := &Node{}
	mp[curr] = cpy // THIS IS IMPORTANT => Not doing this here can reuslt in infinite recursion, need this to so when reaching here again, we return instead of creating another instance
	cpy.Val = curr.Val
	cpy.Next = f(curr.Next)
	cpy.Random = f(curr.Random)

	return cpy
}
