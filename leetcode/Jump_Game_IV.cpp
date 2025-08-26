class Solution {
public:
    int minJumps(vector<int>& arr) {
        // simple bfs implementation
        int n = arr.size();
        unordered_map<int, vector<int>> ump;
        vector<bool> vis(n, false);
        for(int i=0; i<n; i++){
            ump[arr[i]].push_back(i);
        }

        int steps = 0;
        queue<int> qu;
        qu.push(0);
        vis[0] = true;
        while(!qu.empty()){
            int size = qu.size();
            while(size--){
                int currIdx = qu.front();
                qu.pop();
                int left = currIdx-1;
                int right = currIdx+1;

                if(currIdx == n-1) return steps;
                if(left>=0 && !vis[left]){
                    qu.push(left);
                    vis[left] = true;
                }
                if(right<n && !vis[right]){
                    qu.push(right);
                    vis[right] = true;
                }
                // For teleport to same value
                for(auto &idx : ump[arr[currIdx]]){
                    if(!vis[idx]){
                        qu.push(idx);
                        vis[idx] = true;
                    }
                }
                ump.erase(arr[currIdx]);
            }
            steps++;
        }
        return -1;
    }
};