//{ Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        // Your code here
        stack<int>st;
        int n=S.length();
        for(int i=0;i<n;i++){
            if(S[i]=='+'){
                int k=st.top();
                st.pop();
                int l=st.top();
                st.pop();
                st.push(k+l);
            }
            else if(S[i]=='-'){
                  int k=st.top();
                st.pop();
                int l=st.top();
                st.pop();
                st.push(l-k);
            }
            else if(S[i]=='*'){
                  int k=st.top();
                st.pop();
                int l=st.top();
                st.pop();
                st.push(k*l);
            }
            else if(S[i]=='/'){
                  int k=st.top();
                st.pop();
                int l=st.top();
                st.pop();
                st.push(l/k);
            }
            else
            st.push(S[i]-'0');
        }
        return st.top();
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends