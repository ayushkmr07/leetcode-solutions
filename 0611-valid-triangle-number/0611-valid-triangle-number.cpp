class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int cnt=0;
        int n=nums.size();
        long long sum=0;
        for(int i=n-1;i>=2;i--){
            
            int l=0;
            int r=i-1;
            while(l<r){
                sum=nums[l]+nums[r];
                if(sum>nums[i]){
                   cnt+=r-l;
                   r--;
                }
                else{
                    l++;
                }
                
                
            }

        }
        return cnt;
    }
};