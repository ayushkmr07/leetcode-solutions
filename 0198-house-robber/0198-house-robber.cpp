class Solution {
public:
//int F(int ind,int n,vector<int>& dp,vector<int>& nums){
//     if(ind>=n) return 0;
//     if(dp[ind]!=-1){
//         return dp[ind];
//     }
//     int take=nums[ind]+F(ind+2,n,dp,nums);
//     int notTake=F(ind+1,n,dp,nums);
//     return dp[ind]=max(take,notTake);
// }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> dp(n+1,0);
        
      //dp[i]=max stolen money till house i
      //no house dp[0]
        dp[0]=0;
        dp[1]=nums[0];
        for(int i=2;i<=n;i++){
       int take=nums[i-1]+dp[i-2];
       int notTake=dp[i-1];
       dp[i]=max(take,notTake);
        }
        return dp[n];
    }
};