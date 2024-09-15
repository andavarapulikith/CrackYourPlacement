class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalgas=0;
        int totalcost=0;
        int n=gas.size();
        for(int i=0;i<n;i++){
            totalgas+=gas[i];
            totalcost+=cost[i];
        }
        if(totalgas<totalcost)
        return -1;
        
        int startIndex=0, curFuel = 0;
        for(int i=0;i<n;i++){
            if(curFuel < 0){
                curFuel = 0;
                startIndex = i;
            }

            curFuel += (gas[i]-cost[i]);
        }
        return startIndex;
        
    }
};