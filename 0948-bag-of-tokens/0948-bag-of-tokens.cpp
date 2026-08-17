class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
       
        int n=tokens.size();
         if (n == 0) return 0;
        sort(tokens.begin(),tokens.end());
        int score=0;
        int i=1,j=n-1;
        if (power >= tokens[0]) {
            power -= tokens[0];
            score++;
        } else {
            return 0;
        }

      while(i<=j){
        if (power >= tokens[i]){
            power-=tokens[i];
            score++;
            i++;
        }
         else if (score > 0 && i < j) {
                power += tokens[j];
                score--;
                j--;
            }
                  else {
                break;
            }
        }
      
      return score;
    }
};