class Solution {
public:
    vector<vector<int>> dp;

    int solve(int n, int x) {
        if (n == 0) return 0;
        if (x == 0) return 1e9;

        if (dp[n][x] != -1)
            return dp[n][x];

        int take = 1e9;

        if (x * x <= n) {
            take = 1 + solve(n - x * x, x);
        }

        int notTake = solve(n, x - 1);

        return dp[n][x] = min(take, notTake);
    }

    int numSquares(int n) {
        int x = sqrt(n);
        dp.assign(n + 1, vector<int>(x + 1, -1));

        return solve(n, x);
    }
};