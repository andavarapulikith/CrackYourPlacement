class solution {
  public:
    long long multiplyTwoLists(Node *first, Node *second) {
        // code here
        long long mod=1e9+7;
        long long num1=0;
        long long num2=0;
        while(first!=0){
            num1=(num1*10+first->data)%mod;
            first=first->next;
        }
        while(second!=0){
            num2=(num2*10+second->data)%mod;
            second=second->next;
        }
        return (num1*num2)%mod;
    }
};