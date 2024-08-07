class Solution
{
    public:
    Node *compute(Node *head)
    {
        // your code goes here
        if(head==0 || head->next==0)
        return head;
        Node *prev=head;
        Node *temp=head->next;
        while(temp!=0){
            Node *temp2=temp->next;
            temp->next=prev;
            prev=temp;
            temp=temp2;
        }
        head->next=0;
        head=prev;
        prev=head;
        temp=head->next;
        int maxi=head->data;
        while(temp!=0){
            if(temp->data<maxi){
                prev->next=temp->next;
                
            }
            else{
            maxi=max(maxi,temp->data);
            prev=temp;
            }
            temp=temp->next;
        }
        prev=head;
        temp=head->next;
        while(temp!=0){
            Node *temp2=temp->next;
            temp->next=prev;
            prev=temp;
            temp=temp2;
        }
        head->next=0;
        return prev;
        
       
    }
    
};