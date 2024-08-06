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
    ListNode* removeElements(ListNode* head, int val) {
       
        
        while(head!=0 &&head->val==val)
        head=head->next;
        if(head==0)
        return head;
        ListNode* prev=head;
        ListNode* temp=head->next;
        while(temp!=0){
            if(temp->val==val){
                prev->next=temp->next;
                
            }
            else{
            prev=temp;
            }
            temp=temp->next;
        }
        return head;
        
    }
};