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
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      ListNode* mergednode=NULL;
      int n=lists.size();
      if(n==0)
      return NULL;
      if(n==1)
      return lists[0];
      mergednode=merge(lists[0],lists[1]);
      for(int i=2;i<n;i++)
      mergednode=merge(mergednode,lists[i]);
      return mergednode;
        
    }
};