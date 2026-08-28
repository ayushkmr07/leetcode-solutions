class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        sort(pairs.begin(), pairs.end());  
         vector<int> t(n,1);
         int maxLis=1;
         for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(pairs[j][1] <pairs[i][0]){
                    t[i]=max(t[i],t[j]+1);
                    maxLis=max(maxLis,t[i]);
                }
            }
        }
        return maxLis;
    }
};

//class Solution {
// public:
//     int solve(int i, int prev, vector<vector<int>>& pairs,
//               vector<vector<int>>& dp) {

//         if (i == pairs.size()) {
//             return 0;
//         }

//         if (dp[i][prev + 1] != -1) {
//             return dp[i][prev + 1];
//         }

        
//         int notTake = solve(i + 1, prev, pairs, dp);

     
//         int take = 0;

//         if (prev == -1 || pairs[i][0] > pairs[prev][1]) {
//             take = 1 + solve(i + 1, i, pairs, dp);
//         }

//         return dp[i][prev + 1] = max(take, notTake);
//     }

//     int findLongestChain(vector<vector<int>>& pairs) {

//         int n = pairs.size();

//         sort(pairs.begin(), pairs.end());  

//         vector<vector<int>> dp(
//             n, vector<int>(n + 1, -1)
//         );

//         return solve(0, -1, pairs, dp);
//     }
// };