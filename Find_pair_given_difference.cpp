class Solution {
  public:
    int findPair(int n, int x, vector<int> &arr) {
        // code here
         sort(arr.begin(), arr.end());
        int left = 0, right = 1;
        while (left < n && right < n) {
            if (left != right && arr[right] - arr[left] == x) {
                return 1;
            } else if (arr[right] - arr[left] < x) {
                right++;
            } else {
                left++;
            }
        }
        return -1;
    }
};