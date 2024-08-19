class DisjointSet {
public: 
    vector<int> rank, parent, size; 
    DisjointSet(int n) {
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findUPar(parent[node]); 
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v; 
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u; 
        }
        else {
            parent[ulp_v] = ulp_u; 
            rank[ulp_u]++; 
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
}; 

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
 
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0) continue;
                int dx[] = {1, 0, 0, -1};
                int dy[] = {0, 1, -1, 0};
                
                for(int k = 0; k < 4; k++){
                    int newi = i + dx[k];
                    int newj = j + dy[k];
                    if(newi >= 0 && newi < n && newj >= 0 && newj < n && grid[newi][newj] == 1){
                        int num1 = n * i + j;
                        int num2 = n * newi + newj;
                        ds.unionBySize(num1, num2);
                    }
                }
            }
        }
        
    
        int maxi = 0;
        bool hasZero = false;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0) {
                    hasZero = true;
                    set<int> st;
                    int dx[] = {1, 0, 0, -1};
                    int dy[] = {0, 1, -1, 0};
                    
                    for(int k = 0; k < 4; k++){
                        int newi = i + dx[k];
                        int newj = j + dy[k];
                        if(newi >= 0 && newi < n && newj >= 0 && newj < n && grid[newi][newj] == 1){
                            int num2 = n * newi + newj;
                            st.insert(ds.findUPar(num2));
                        }
                    }
                    
                    int size1 = 1; 
                    for(auto it: st){
                        size1 += ds.size[it];
                    }
                    maxi = max(maxi, size1);
                }
            }
        }

        
        if (!hasZero) return n * n;

        return maxi;
    }
};
