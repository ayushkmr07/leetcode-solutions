class Solution {
public:
static bool myFunction(string &word1,string &word2){
    return word1.length()<word2.length();
}
bool check(string &prev, string &curr){
    if (curr.size() != prev.size() + 1)
            return false;
            int i=0;
            int j=0;
            while(j<curr.size()){
                if(i<prev.size()&& prev[i]==curr[j]){
                    i++;
                }
                j++;
            }
            return i==prev.size();
}
 int solve(int i, int prev,
              vector<string>& words,
              vector<vector<int>>& dp){
                if(i==words.size())
                return 0;
                 if (dp[i][prev + 1] != -1)
            return dp[i][prev + 1];
int notTake = solve(i + 1, prev, words, dp);
        int take = 0;
        if(prev==-1 || check(words[prev],words[i])){
                        take = 1 + solve(i + 1, i, words, dp);

             

        }
        return dp[i][prev + 1] =
               max(take, notTake);
              }
    int longestStrChain(vector<string>& words) {
         sort(words.begin(), words.end(),myFunction);
          int n = words.size();

        vector<vector<int>> dp(
            n, vector<int>(n + 1, -1)
        );
        return solve(0, -1, words, dp);
    }
};