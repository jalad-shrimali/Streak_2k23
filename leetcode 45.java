class Solution {
    public int jump(int[] nums) {
        if(nums == null || nums.length == 0 || nums.length == 1) return 0;
        int slow = 0, fast = 0, result = 0, reach = 0;
        while(reach < nums.length - 1){
            result++;
            for(int i = slow; i <= fast; i++)
                reach = Math.max(reach, i + nums[i]);
            slow = fast + 1;
            fast = reach;
        }
        return result;
    }
}
