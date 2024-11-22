package LinkedList

// really wierd question, only can solve this since I've seen it before
// remeber that toirtoise hare algorithm is only for detecting existence of a cycle
// to find beginning of cycle, move slow to start and move both one by one till they meet

func findDuplicate(nums []int) int {
	slow, fast := 0, 0

	for true {
		slow = nums[slow]
		fast = nums[nums[fast]]

		if slow == fast {
			break
		}
	}

	slow = 0
	for nums[slow] != nums[fast] {
		slow = nums[slow]
		fast = nums[fast]
	}
	return nums[fast]
}
