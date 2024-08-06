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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==0)
        return head;
        int prevvalue=head->val;
        ListNode* prev=head;
        ListNode* temp=head->next;
        while(temp!=0){
            if(temp->val==prevvalue){
                prev->next=temp->next;
                temp=temp->next;

            }
            else{
                prev=temp;
                prevvalue=temp->val;
                temp=temp->next;
            }
        }
        return head;
        
    }
};