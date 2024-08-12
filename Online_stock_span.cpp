class StockSpanner {
public:
    stack<pair<int,int>>st;
    int indi=-1;
    StockSpanner() {
        indi=-1;
    }
    
    int next(int price) {
        indi++;
        while(!st.empty() && st.top().first<=price)
        st.pop();
        int ans=indi-(st.empty()?-1:st.top().second);
        st.push({price,indi});
        return ans;

    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */