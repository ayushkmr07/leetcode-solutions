class Solution {
public:
    unordered_set<string> st;
    vector<int> dp;

    bool solve(int i, string &s, int n) {

        // Reached the end
        if (i == n) {
            return true;
        }

        // Already calculated
        if (dp[i] != -1) {
            return dp[i];
        }

        for (int l = 1; l <= n - i; l++) {

            string temp = s.substr(i, l);

            if (st.find(temp) != st.end() &&
                solve(i + l, s, n)) {

                return dp[i] = true;
            }
        }

        return dp[i] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {

        int n = s.size();

        for (string &it : wordDict) {
            st.insert(it);
        }

        dp.assign(n, -1);

        return solve(0, s, n);
    }
};