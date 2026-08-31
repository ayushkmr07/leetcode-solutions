/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev=head;
        ListNode* curr=prev->next;
        ListNode* temp=nullptr;
        int cnt=1;
        vector<int> ans;
        while(curr->next!=nullptr){
       if(curr->val>prev->val &&  curr->val>curr->next->val){
        ans.push_back(cnt);
       }
       if(curr->val<prev->val &&  curr->val<curr->next->val){
        ans.push_back(cnt);
       }
        temp=curr;
        curr=curr->next;
        prev=temp;
        cnt++;
        }
       if(ans.size()<2)
       return {-1,-1};
       int n=ans.size();
       
       int mini=INT_MAX;
      for(int i=1;i<n;i++){
       mini=min(mini,ans[i]-ans[i-1]);
      }
      
      int y=ans[n-1]-ans[0];
     
       return {mini, y};
    }
};