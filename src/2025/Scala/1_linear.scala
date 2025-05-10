import scala.collection.mutable.HashMap

/*
Scala seems to be picky about non-local returns
*/
object Solution {
    def twoSum(nums: Array[Int], target: Int): Array[Int] = {
        val map = HashMap[Int, Int]()
        var result: Array[Int] = Array()
        for (i <- 0 until nums.length) {
            val complement = target - nums(i)
            if (map.contains(complement)) {
                result = Array(map(complement), i)
            }
            map(nums(i)) = i
        }
        result
    }
}