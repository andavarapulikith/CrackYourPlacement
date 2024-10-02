class Solution {
public:
    int minDeletions(string s) {
        vector<int>v(26,0);
        for(int i=0;i<s.length();i++){
            v[s[i]-'a']++;
        }
        int cnt=0;
        set<int>st;
        for(int i=0;i<26;i++){
            int val=v[i];
            while(st.find(val)!=st.end() && val!=0)
             {
                val--;
                cnt++;
             }
             if(val!=0)
             st.insert(val);

        }
        return cnt;
        
    }
};