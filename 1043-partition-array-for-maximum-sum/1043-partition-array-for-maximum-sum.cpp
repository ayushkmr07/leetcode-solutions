
class Solution {
public:
    int solve(vector<int>& arr, int n, int k, int i, vector<int>& dp) {
        // Base case
        if (i >= n)
            return 0;

        // Already calculated
        if (dp[i] != -1)
            return dp[i];

        int curr_max = -1;
        int result = 0;

        // Try all partitions of length 1 to k
        for (int j = i; j < n && j - i + 1 <= k; j++) {

            curr_max = max(curr_max, arr[j]);

            int len = j - i + 1;

            result = max(
                result,
                len * curr_max + solve(arr, n, k, j + 1, dp)
            );
        }

        // Store the answer for index i
        return dp[i] = result;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();

        // dp[i] = maximum sum starting from index i
        vector<int> dp(n, -1);

        return solve(arr, n, k, 0, dp);
    }
};



// class Solution {
// public:
//     int solve(vector<int>& arr, int n, int k, int i) {
//         if (i >= n)
//             return 0;

//         int curr_max = -1;
//         int result = 0;

//         for (int j = i; j < n && j - i + 1 <= k; j++) {
//             curr_max = max(curr_max, arr[j]);

//             result = max(
//                 result,
//                 (j - i + 1) * curr_max + solve(arr, n, k, j + 1)
//             );
//         }

//         return result;
//     }

//     int maxSumAfterPartitioning(vector<int>& arr, int k) {
//         int n = arr.size();
//         return solve(arr, n, k, 0);
//     }
// };