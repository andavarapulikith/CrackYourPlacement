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
    ListNode* partition(ListNode* head, int x) {
        ListNode *left=new ListNode(0);
        ListNode* left1=left;
        ListNode* right=new ListNode(0);
        ListNode* right1=right;
        while(head!=0){
            if(head->val<x){
                left->next=head;
                left=head;
            }
            else
            {
                right->next=head;
                right=head;
            }
            head=head->next;
        }
        left->next=right1->next;
        right->next=0;
        return left1->next;

        
    }
};