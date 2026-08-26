class Solution {
public:
    vector<vector<int>> dp; 
 
    // int solve(int n, int x) { 
    //     if (n == 0) return 0; 
    //     if (x == 0) return 1e9; 
 
    //     if (dp[n][x] != -1) 
    //         return dp[n][x]; 
 
    //     int take = 1e9; 
 
    //     if (x * x <= n) { 
    //         take = 1 + solve(n - x * x, x); 
    //     } 
 
    //     int notTake = solve(n, x - 1); 
 
    //     return dp[n][x] = min(take, notTake); 
    // } 
 
    int numSquares(int n) { 
        int x = sqrt(n); 
        const int INF = 1e9;

        dp.assign(n + 1, vector<int>(x + 1, -1));  

        // If the target is 0, we need 0 squares. 
        // It doesn't matter what x is. 
        for (int j = 0; j <= x; j++) { 
            dp[0][j] = 0; 
        } 

        for (int i = 1; i <= n; i++) { 
            dp[i][0] = INF; 
        } 

        for (int i = 1; i <= n; i++) { 
            for (int j = 1; j <= x; j++) { 

                int take = INF; 
 
                if (j * j <= i) { 
                    take = 1 + dp[i - j * j][j]; 
                } 
 
                int notTake = dp[i][j - 1]; 
 
                dp[i][j] = min(take, notTake); 
            } 
        } 
 
        return dp[n][x]; 
    } 
};



//          x
//         0   1   2   3
//       +----------------
// n = 0 | 0   0   0   0
// n = 1 | ∞
// n = 2 | ∞
// n = 3 | ∞
// n = 4 | ∞
// ...
// n =12 | ∞

//Replace solve() with dp[][]
//solve(n - x * x, x)-> dp[n - x * x][x]