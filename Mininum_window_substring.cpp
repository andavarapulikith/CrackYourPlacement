class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.length();
        int m=t.length();
        if(n<m) return "";
        int l=0;
        int r=0;
        int cnt=0;
        vector<int>hash(256,0);
        int min_len=INT_MAX;
        int indi=-1;
        for(int i=0;i<m;i++)
            hash[t[i]]++;
        while(r<n){
            if(hash[s[r]]>0)
                cnt+=1;
            hash[s[r]]--;
            while(cnt==m){
                if(r-l+1<min_len){
                    min_len=r-l+1;
                    indi=l;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0)
                    cnt-=1;
                l++;
            }
            r++;
        }
        return indi==-1 ? "" : s.substr(indi, min_len);
    }
};
