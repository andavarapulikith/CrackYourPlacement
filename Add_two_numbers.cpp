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
        int carry=0;
        ListNode* ans=new ListNode(0);
        ListNode* temp=ans;
        while(l1!=0 && l2!=0){
            int val=l1->val+l2->val+carry;
            if(val>=10){
                carry=1;
                val=val%10;
            }
             else
            carry=0;
            temp->next=new ListNode(val);
            temp=temp->next;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1!=0){
            int val=l1->val+carry;
             if(val>=10){
                carry=1;
                val=val%10;
            }
             else
            carry=0;
            temp->next=new ListNode(val);
            temp=temp->next;
            l1=l1->next;
        }
        while(l2!=0){
           int val=l2->val+carry;
             if(val>=10){
                carry=1;
                val=val%10;
            }
            else
            carry=0;
            l2=l2->next;
            temp->next=new ListNode(val);
            temp=temp->next;
        }
        if(carry)
        {
            temp->next=new ListNode(carry);
        }

        return ans->next;
        
    }
};