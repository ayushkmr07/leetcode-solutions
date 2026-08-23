class Solution {
public:
int t[101];
  int F(int ind,int n,vector<int>& nums){
    if(ind>n) return 0;
    if(t[ind]!=-1){
        return t[ind];

    }
    int take=nums[ind]+F(ind+2,n,nums);
    int notTake=F(ind+1,n,nums);
    return t[ind]=max(take,notTake);
  }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        memset(t,-1,sizeof(t));
        //for 0ths 
        int zero=F(0,n-2,nums);
         memset(t,-1,sizeof(t));
         int one=F(1,n-1,nums);

         return max(zero,one);
    }
};