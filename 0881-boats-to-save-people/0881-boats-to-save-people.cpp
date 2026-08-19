class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int cnt=0;
        sort(people.begin(),people.end());
        int n=people.size();
        int i=0;
        int j=n-1;
        while(i<=j){
            if(people[i]+people[j]>limit){
                cnt++;
                j--;
            }
            else{
                cnt++;
                i++;
                j--;
            }
        }
        return cnt;
    }
};