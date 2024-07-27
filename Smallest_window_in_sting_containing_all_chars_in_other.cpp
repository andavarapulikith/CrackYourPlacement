class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string t)
    {
        // Your code here
        int n=s.length();
        int m=t.length();
        if(n<m) return "-1";
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
        return indi==-1 ? "-1" : s.substr(indi, min_len);
    }
};