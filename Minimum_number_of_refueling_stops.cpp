class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int maxi=startFuel;
        int n=stations.size();
        int indi=0;
        int cnt=0;
        priority_queue<int>pq;
        while(maxi<target){
            while(indi<n && stations[indi][0]<=maxi){
                pq.push(stations[indi][1]);
                indi++;
            }
            if(pq.empty())
            return -1;
           
            maxi+=pq.top();
            pq.pop();
            cnt++;
            
        }
        return cnt;
        
    }
};