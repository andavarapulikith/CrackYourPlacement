class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string>s;
        int n=wordList.size();
        for(auto it:wordList){
            s.insert(it);
        }
        s.erase(beginWord);
        queue<pair<int,string>>q;
        q.push({1,beginWord});
        while(!q.empty()){
            string original=q.front().second;
            int steps=q.front().first;
            q.pop();
            if(original==endWord)
            return steps;
            string str=original;
            for(int i=0;i<str.length();i++){
                for(char ch='a';ch<='z';ch++){
                    str[i]=ch;
                    if(s.find(str)!=s.end()){
                        s.erase(str);
                        q.push({steps+1,str});
                    }
                    
                }
                str=original;
            }
        }
        return 0;
    }
};