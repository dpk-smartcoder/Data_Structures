class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int initColor = image[sr][sc];
        if(initColor == color) return image;

        queue<pair<int,int>> qu;
        // vector<vector<int>> vis(n, vector<int> (m, 0));
        qu.push({sr, sc});
        image[sr][sc] = color;

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        while(!qu.empty()){
            int row = qu.front().first;
            int col = qu.front().second;
            qu.pop();
            for(int i=0; i<4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol] == initColor){
                    qu.push({nrow, ncol});
                    image[nrow][ncol] = color;
                }
            }
        }
        return image;
    }
};