class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<pair<int,int>> q;
        vector<int> distance(n, INT_MAX);
        unordered_map<int, vector<pair<int, int>>> adj;

        for(auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        q.push({src, 0});
        distance[src] = 0;
        int level = 0;

        while(!q.empty()) {
            if(level > k) break;

            int size = q.size();
            for(int i = 0; i < size; i++) {
                int node = q.front().first;
                int dist = q.front().second;
                q.pop();  
                for(auto it : adj[node]) {
                    if(distance[it.first] > dist + it.second) {
                        distance[it.first] = dist + it.second;
                        q.push({it.first, distance[it.first]});
                    }
                }
            }
            level++;
        }

        return (distance[dst] == INT_MAX) ? -1 : distance[dst];
    }
};
