class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int,vector<int>,greater<int>>pq;
        int n=heights.size();
        int i=0;
        for(i;i<n-1;i++){
            if(heights[i]>=heights[i+1])
            continue;
            else{
                int diff=heights[i+1]-heights[i];
                if(ladders>0){
                    pq.push(diff);
                    ladders--;
                }
                else{
                    pq.push(diff);
                    int k=pq.top();
                    if(k>bricks)
                    break;
                    else{
                        pq.pop();
                        bricks-=k;
                    }
                    
                }
            }
        }
        return i;

    }
};