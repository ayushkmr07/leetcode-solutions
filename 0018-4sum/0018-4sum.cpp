class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n=nums.size();
        long long sum=0;
        for(int i=0;i<n-3;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            for(int j=i+1;j<n-2;j++){
                if(j>i+1 && nums[j]==nums[j-1]){
                    continue;
                }
            
            //int x=nums[i];
            //int y=nums[j];
            int l=j+1;
            int r=n-1;
           
            while(l<r){
              sum=(long long) nums[l]+ (long long)nums[r]+nums[i]+nums[j];
             
              if(sum>target){
                r--;
              }
              else if(sum<target){
                l++;

              }
              else {
                 ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                 l++;
                 r--;
               
              
                 while(l<r && nums[l]==nums[l-1]){
                    l++;
                }
                  while(l<r && nums[r]==nums[r+1]){
                    r--;
                }
                
              }
            }}
            
        }
        return ans;
    }
};