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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int>st1;
        stack<int>st2;
        while(l1!=0){
            st1.push(l1->val);
            l1=l1->next;
        }
        while(l2!=0){
            st2.push(l2->val);
            l2=l2->next;
        }
        ListNode* ans=NULL;
      
        int carry=0;
        while(!st1.empty() || !st2.empty()){
            int val=carry;
            if(!st1.empty())
            {
                val+=st1.top();
                st1.pop();
            }
            if(!st2.empty()){
                val+=st2.top();
                st2.pop();
            }
            ListNode* temp2=new ListNode(val%10);
            if(ans==NULL){
                ans=temp2;
            }
            else{
            temp2->next=ans;
            ans=temp2;
            }
            carry=val/10;
        }
        if(carry){
            ListNode* temp2=new ListNode(1);
            temp2->next=ans;
            ans=temp2;
        }
        return ans;

       
        
    }
};