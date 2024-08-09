
class Solution {
public:
    ListNode* reverseList(ListNode* temp1){
        ListNode* prev=temp1;
        ListNode *temp=temp1->next;
        while(temp!=0){
           ListNode* temp2=temp->next;
            temp->next=prev;
            prev=temp;
            temp=temp2;
        }
        temp1->next=0;
        return prev;
       
    }
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head->next;
        if(head==0 || head->next==0)
        return ;
        while(fast!=0 && fast->next!=0){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* second=reverseList(slow->next);
        slow->next=0;
        ListNode* first=head;
        while(second!=0){
            ListNode* temp1=first->next;
            ListNode* temp2=second->next;
            first->next=second;
            second->next=temp1;
            first=temp1;
            second=temp2;
        }
    }
};