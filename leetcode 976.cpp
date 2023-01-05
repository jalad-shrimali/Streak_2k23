class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        // int max= INT_MIN;
        // int sum=0;
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]>max)max= nums[i];
        // }
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]+nums[i+1]>max){
        //         sum+=nums[i];
        //     }
        // }
        // return sum;
        sort(nums.begin(), nums.end());
        for(int i=nums.size()-3;i>=0;i--){
            if(nums[i]+nums[i+1]>nums[i+2]){
                return nums[i]+nums[i+1]+nums[i+2];
            }
        }
        return 0;
    }
};
