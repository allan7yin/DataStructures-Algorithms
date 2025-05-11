import scala.collection.mutable.ArrayBuffer

/*
Don't kill me, ik theres O(1) -> this is just to get more used to the sorting and syntax
*/
object Solution {
    def twoSum(nums: Array[Int], target: Int): Array[Int] = {
        val numPairs : ArrayBuffer[(Int, Int)] = ArrayBuffer()
        for (i <- 0 until nums.length) {
            numPairs += ((nums(i), i))
        }

        val sortedNums = numPairs.sorted
        var (l, r) = (0, sortedNums.length - 1)

        while (l < r) {
            val sum = sortedNums(l)._1 + sortedNums(r)._1
            if (sum == target) return Array(sortedNums(l)._2, sortedNums(r)._2)
            else if (sum < target) {
                l += 1
            } else {
                r -= 1
            }
        }

        return Array()
    }
}
