class Solution {
public:
    bool isNumber(string s) {
        bool digitseen=false;
        bool dotseen=false;
        bool eseen=false;
        int plusminuscnt=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(isdigit(s[i]))
            digitseen=true;
            else if(s[i]=='+'|| s[i]=='-'){
                if(plusminuscnt>=2)
                return false;
                if(i>0 && s[i-1]!='e'&& s[i-1]!='E')
                return false;
                if(i==n-1)
                return false;
                plusminuscnt++;
            }
            else if(s[i]=='.'){
                if(eseen || dotseen)
                return false;
                if(i==n-1 && !digitseen)
                return false;
                dotseen=true;
            }
            else if(s[i]=='e' || s[i]=='E'){
                if(eseen || !digitseen )
                return false;
                if(i==n-1)
                return false;
                eseen=true;

            }
            else
            return false;
        }
        return true;
        
    }
};