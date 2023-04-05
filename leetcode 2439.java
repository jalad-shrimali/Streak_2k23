public class Solution {
    public int minimizeArrayValue(int[] nums) {
        long max = 0;
        long sum = 0;
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
            max = Math.max(max, (sum + i) / (i + 1));
        }
        return (int) max;
    }
}
