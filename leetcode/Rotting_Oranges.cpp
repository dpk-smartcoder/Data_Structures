class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>, int>> qu;
        vector<vector<int>> vis(n, vector<int> (m, 0));
        int cntFresh = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    qu.push({{i,j}, 0});
                    vis[i][j] = 2;
                }
                if(grid[i][j] == 1) cntFresh++;
            }
        }
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        int time=0; int cntRot = 0;

        while(!qu.empty()){
            int r = qu.front().first.first;
            int c = qu.front().first.second;
            int t = qu.front().second;
            time = max(time,t);
            qu.pop();
            for(int i=0; i<4; i++){
                int nrow = r+drow[i];
                int ncol = c+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && grid[nrow][ncol]==1){
                    qu.push({{nrow,ncol}, time+1});
                    vis[nrow][ncol] = 2;
                    cntRot++;
                }
            }
        }
        if(cntRot != cntFresh){
            return -1;
        }
        return time;
    }
};