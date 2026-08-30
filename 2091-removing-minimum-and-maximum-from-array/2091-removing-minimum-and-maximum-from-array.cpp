class Solution { 
public: 
    int minimumDeletions(vector<int>& nums) { 
        int n = nums.size(); 
        
        if(n == 1) return 1;

        int sum = INT_MAX; 
        int maxInd = -1; 
        int minInd = -1; 
        
        // Find minimum index
        for(int i = 0; i < n; i++){ 
            if(sum > nums[i]){ 
                sum = nums[i]; 
                minInd = i; 
            } 
        } 
        
        // Find maximum index
        sum = INT_MIN; 
        
        for(int i = 0; i < n; i++){ 
            if(sum < nums[i]){ 
                sum = nums[i]; 
                maxInd = i; 
            } 
        } 

        int j = max(minInd, maxInd); 
        int k = min(minInd, maxInd); 

       
        int front = j + 1;

       
        int back = n - k;

        int both = (k + 1) + (n - j);

        return min({front, back, both});
    } 
};