class Solution {
public:
    int f(vector<int>& nums, int target, int i, int currSum) {
        
    
        if (i == nums.size()) {
            return currSum == target;
        }
       
        int plus = f(nums, target, i + 1, currSum + nums[i]);
        
       
        int minus = f(nums, target, i + 1, currSum - nums[i]);
        
        return plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return f(nums, target, 0, 0);
    }
};