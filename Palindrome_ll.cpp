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
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        if(head==0 || head->next==0)
        return head;
        int len=0;
        while(fast!=0 && fast->next!=0){
            slow=slow->next;
            fast=fast->next->next;
            len+=2;
        }
        if(fast)
        len++;
        if(len%2==1)
        {
        slow=slow->next;
        }
        ListNode *prev=slow;
        ListNode *temp=slow->next;
        while(temp!=0){
            ListNode* temp2=temp->next;
            temp->next=prev;
            prev=temp;
            temp=temp2;
        }
        slow->next=0;
        temp=head;
        while(prev!=0){
            if(prev->val!=temp->val)
            return false;
            prev=prev->next;
            temp=temp->next;
        }
        return true;
        

    }
};