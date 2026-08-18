class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0;
        while(j<n){
        if(nums[j]==0){
            break;
        }
        j++;
      }

        i=j+1;
        while(i<n){
            if(nums[i]!=0 && nums[j]==0){
                swap(nums[i],nums[j]);
                j++;
            }
           i++;
        }
       
    }
};