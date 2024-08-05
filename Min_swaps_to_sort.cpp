class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    vector<pair<int,int>>vec;
        int n=nums.size();
        for(int i=0;i<n;i++){
          vec.push_back({nums[i],i});
        }
        sort(vec.begin(),vec.end());
        int swaps=0;
        for(int i=0;i<n;i++){
            pair<int,int>p=vec[i];
            int indi=p.second;
            if(indi!=i){
                swap(vec[i],vec[indi]);
                i--;
                swaps++;
            }

        }
        return swaps;
	}
};
