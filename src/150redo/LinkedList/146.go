package LinkedList

type DLLNode[T any] struct {
	val  T
	key  T
	next *DLLNode[T]
	prev *DLLNode[T]
}

// the idea is maintain a linked list, and pop left node once the cache is full
type LRUCache struct {
	head     *DLLNode[int]
	tail     *DLLNode[int]
	mp       map[int]*DLLNode[int]
	capacity int
}

func Constructor(capacity int) LRUCache {
	return LRUCache{
		nil,
		nil,
		make(map[int]*DLLNode[int]),
		capacity,
	}
}

func (this *LRUCache) removeNode(node *DLLNode[int]) {
	if this.head == node && this.tail == node {
		this.head = nil
		this.tail = nil
		return
	}

	if this.head == node {
		this.head = node.next
		this.head.prev = nil
	} else if this.tail == node {
		this.tail = node.prev
		this.tail.next = nil
	} else {
		node.prev.next = node.next
		node.next.prev = node.prev
	}

	node.prev = nil
	node.next = nil
}

func (this *LRUCache) insertNode(node *DLLNode[int]) {
	node.next = nil
	node.prev = nil
	if this.tail == nil {
		// this is the first node
		this.head = node
		this.tail = node
	} else {
		// just add to the end
		this.tail.next = node
		node.prev = this.tail
		this.tail = node
	}
}

// lru -> if we get some key, need to move it to the back
func (this *LRUCache) Get(key int) int {
	if value, ok := this.mp[key]; ok {
		this.removeNode(value)
		this.insertNode(value)
		return value.val
	}

	return -1
}

func (this *LRUCache) Put(key int, value int) {
	if node, ok := this.mp[key]; ok {
		node.val = value
		this.removeNode(node)
		this.insertNode(node)
		return
	}

	if len(this.mp) == this.capacity {
		evictKey := this.head.key
		this.removeNode(this.head)
		delete(this.mp, evictKey)
	}

	newNode := &DLLNode[int]{key: key, val: value}
	this.insertNode(newNode)
	this.mp[key] = newNode
}
