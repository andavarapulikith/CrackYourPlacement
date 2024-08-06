class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        // Your code here
        for(int i=0;i<n;i++){
            
            if(arr[i]>=1 && arr[i]<=n){
                int indi=arr[i]-1;
                if(arr[indi]!=arr[i]){
                    swap(arr[i],arr[indi]);
                    i--;
                    
                }
            }
        }
        for(int i=0;i<n;i++){
            if(arr[i]!=i+1)
            return i+1;
        }
        return n+1;
        
        
    } 
};