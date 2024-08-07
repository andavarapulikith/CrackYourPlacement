/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*,Node*>mpp;
        Node *ans=new Node(0);
        Node *temp1=head;
        Node* temp2=ans;
        while(temp1!=0){
            temp2->next=new Node(temp1->val);
            mpp[temp1]=temp2->next;
            temp2=temp2->next;
            temp1=temp1->next;
        }
        temp1=head;
        temp2=ans->next;
        while(temp1!=0){
            temp2->random=mpp[temp1->random];
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return ans->next;
        
    }
};