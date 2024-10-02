class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>v(26,0);
     
        for(int i=0;i<tasks.size();i++){
            v[tasks[i]-'A']++;
            
        }
        sort(v.begin(),v.end(),greater<int>());
        int ideal=(v[0]-1)*n;
        for(int i=1;i<26;i++){
            ideal-=min(v[0]-1,v[i]);
        }
        return tasks.size()+max(0,ideal);

        
    }
};