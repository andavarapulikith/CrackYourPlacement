class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int len1 = a.length();
        int len2 = b.length();
        if (len1 < len2) {
            swap(a, b);
            swap(len1, len2);
        }

        int carry = 0;
        int i = len2 - 1;
        int j = len1 - 1;

        while (i >= 0) {
            int sum = (a[j] - '0') + (b[i] - '0') + carry;
            ans += to_string(sum % 2);
            carry = sum / 2;
            i--;
            j--;
        }

        while (j >= 0) {
            int sum = (a[j] - '0') + carry;
            ans += to_string(sum % 2) ;
            carry = sum / 2;
            j--;
        }

        if (carry) {
            ans += "1" ;
        }
       reverse(ans.begin(),ans.end());
        return ans;
    }
};
