/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1=0;
        int len2=0;
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        while(temp1!=0){
            len1++;
            temp1=temp1->next;
        }
        while(temp2!=0){
            len2++;
            temp2=temp2->next;
        }
        temp1=headA;
        temp2=headB;
        if(len2>=len1)
        {
            swap(temp1,temp2);
            swap(len1,len2);
        }
        int k=len1-len2;
        while(k--)
        temp1=temp1->next;
        while(temp1!=temp2){
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return temp1;


        
    }
};