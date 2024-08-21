class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mpp;
        int n = s.length();
        
        for (char c : s) {
            mpp[c]++;
            if (mpp[c] > (n + 1) / 2) {
                return "";
            }
        }

 
        char maxChar = '\0';
        int maxFreq = 0;
        for (auto it : mpp) {
            if (it.second > maxFreq) {
                maxFreq = it.second;
                maxChar = it.first;
            }
        }

  
        vector<char> ans(n);
        int i = 0;

     
        while (maxFreq > 0) {
            ans[i] = maxChar;
            i += 2;
            maxFreq--;
        }

     
        mpp.erase(maxChar);

        for (auto it : mpp) {
            char ch = it.first;
            int freq = it.second;
            while (freq > 0) {
                if (i >= n) {
                    i = 1; 
                }
                ans[i] = ch;
                i += 2;
                freq--;
            }
        }

      
        return string(ans.begin(), ans.end());
    }
};
