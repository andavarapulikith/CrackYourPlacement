class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
        if(head==0)
        return head;
        vector<int>cnt(3,0);
        Node* temp=head;
        while(temp!=0){
            cnt[temp->data]++;
            temp=temp->next;
        }
        temp=head;
        int indi=0;
        while(temp!=0){
            while(cnt[indi]==0)
            indi++;
            temp->data=indi;
            cnt[indi]--;
            temp=temp->next;
        }
        return head;
        
    }
};