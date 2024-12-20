class Solution {
    public int findMin(int[] nums) {
        int l = 0, r = nums.length - 1;
        int result = nums[0];

        while (l <= r) {
            int m = l + (r - l) / 2;
            result = Math.min(result, nums[m]);
            if (nums[r] <= nums[m] && nums[m] >= nums[r]) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return result;
    }
}