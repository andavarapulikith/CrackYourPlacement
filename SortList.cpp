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
    ListNode* findMiddle(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=0  && fast->next!=0){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* list1,ListNode* list2){
      ListNode* dummy=new ListNode(-1);
      ListNode* temp=dummy;
      while(list1!=0 && list2!=0){
        if(list1->val<list2->val){
            temp->next=list1;
            temp=list1;
            list1=list1->next;
        
        }
        else{
            temp->next=list2;
            temp=list2;
            list2=list2->next;

        }

      }
      if(list1)
      temp->next=list1;
      else
      temp->next=list2;
      return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==0 || head->next==0)
        return head;
        ListNode* middle=findMiddle(head);
        ListNode* left=head;
        ListNode* right=middle->next;
        middle->next=NULL;
        left=sortList(left);
        right=sortList(right);
        return merge(left,right);
        
    }
};