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
    ListNode* reverseList(ListNode* head) {
        if(head==0 || head->next==0)
        return head;
        ListNode* prev=head;
        ListNode* temp=head->next;
        while(temp!=0){
          ListNode*  temp2=temp->next;
          temp->next=prev;
          prev=temp;
          temp=temp2;
        }
        head->next=0;
        return prev;
    
        
    }
};