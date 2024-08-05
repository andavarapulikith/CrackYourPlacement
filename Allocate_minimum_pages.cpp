class Solution {
  public:
    // Function to find minimum number of pages.
    bool predicate(int arr[], int n, long long mid, int m) {
        int cnt = 1;  
        long long curr_sum = 0;
        
        for (int i = 0; i < n; ++i) {
            if (arr[i] > mid) {
                return false;
            }
            
            if (curr_sum + arr[i] > mid) {
                cnt++;
                curr_sum = arr[i];
                if (cnt > m) return false;
            } else {
                curr_sum += arr[i];
            }
        }
        return true;
    }
    long long findPages(int n, int arr[], int m) {
        // code here
        if (m > n) return -1;  
        
        long long sum = 0;
        long long max_pages = 0;
        
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            max_pages = max(max_pages, (long long)arr[i]);
        }
        
        long long low = max_pages, high = sum, result = high;
        
        while (low <= high) {
            long long mid = (low + high) / 2;
            
            if (predicate(arr, n, mid, m)) {
                high = mid-1;
                result=mid;
            } else {
                low = mid+1;
            }
        }
        
        return result;
    }
};
