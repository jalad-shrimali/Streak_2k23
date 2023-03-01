class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        if (nums.size() <= 1)
            return nums;

        for (int j = 1; j < nums.size(); ++j) {
            int temp = nums[j];
            int i = j - 1;
            while (i >= 0 && nums[i] > temp) {
                nums[i+1] = nums[i];
                i--;
            }
            nums[i+1] = temp;
        }

        return nums;
    }
}
//This solution given below worked
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        
        nums.sort()
        return nums
