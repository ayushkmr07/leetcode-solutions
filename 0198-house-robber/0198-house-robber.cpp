class Solution {
public:
int F(int ind,int n,vector<int>& dp,vector<int>& nums){
    if(ind>=n) return 0;
    if(dp[ind]!=-1){
        return dp[ind];
    }
    int take=nums[ind]+F(ind+2,n,dp,nums);
    int notTake=F(ind+1,n,dp,nums);
    return dp[ind]=max(take,notTake);
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        int ans=F(0,n,dp,nums);
        return ans;
    }
};