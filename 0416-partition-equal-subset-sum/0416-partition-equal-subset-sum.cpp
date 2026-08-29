class Solution {
public:
    int dp[201][20001];

    bool solve(int i, int sum, vector<int>& nums) {
        if (sum == 0) return true;
        if (i == nums.size()) return false;

        if (dp[i][sum] != -1) return dp[i][sum];

        bool take = false;

        if (nums[i] <= sum) {
            take = solve(i + 1, sum - nums[i], nums);
        }

        bool notTake = solve(i + 1, sum, nums);

        return dp[i][sum] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;

        for (int num : nums) {
            sum += num;
        }

        if (sum % 2 != 0) return false;

        memset(dp, -1, sizeof(dp));

        return solve(0, sum / 2, nums);
    }
};