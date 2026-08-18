class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=INT_MAX;
       for(int i=0;i<n-2;i++){
        if(i>0 && nums[i]==nums[i-1]){
            continue;
        }
        int l=i+1;
        int r=n-1;
        
        int prev=INT_MAX;
        while(l<r){
            long long sum=(long long)nums[i]+nums[l]+nums[r];
            if(abs(sum - target) < abs((long long)ans - target)){
                ans=sum;
            }
             if (sum == target) {
                    return target;
                }
                else if (sum < target) {
                    l++;
                }
                else {
                    r--;
                }
            
        }
       }
   return ans;
    }
};