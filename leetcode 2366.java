public class Solution {
    public long minimumReplacement(int[] nums) {
        int limit = nums[nums.length - 1];
        long ans = 0;
        for (int i = nums.length - 2; i >= 0; i--) {
            int replacements = nums[i] / limit - 1;
            if (nums[i] % limit != 0) {
                replacements++;
            }
            ans += replacements;
            limit = nums[i] / (replacements + 1);
        }
        return ans;
    }
}
