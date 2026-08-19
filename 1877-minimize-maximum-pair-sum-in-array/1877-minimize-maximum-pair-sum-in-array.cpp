class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
    int i=0;int r=n-1;
    long long sum=0;
    long long result=INT_MIN;
    while(i<r){
        sum=nums[i]+nums[r];
        result=max(result,sum);
        i++;
        r--;
    }
    return result;
    }
};