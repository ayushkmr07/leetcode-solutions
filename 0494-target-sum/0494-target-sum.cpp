class Solution {
public:// challenge is currentSum can be negative as index cannot be negative
 map<pair<int, int>, int> dp;
    int f(vector<int>& nums, int target, int i, int currSum) {
        
    
        if (i == nums.size()) {
            return currSum == target;
        }
         if (dp.find({i, currSum}) != dp.end()) {
            return dp[{i, currSum}];
        }
       
        int plus = f(nums, target, i + 1, currSum + nums[i]);
        
       
        int minus = f(nums, target, i + 1, currSum - nums[i]);
        
       return dp[{i, currSum}] = plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return f(nums, target, 0, 0);
    }
};