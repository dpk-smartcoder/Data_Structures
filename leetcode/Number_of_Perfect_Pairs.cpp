class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans;
        for(auto &x : nums){
            long long ele = x;
            ans.push_back(abs(ele));
        }
        sort(ans.begin(), ans.end());
        long long cnt = 0;
        int j = 0;
        for(int i=0; i<n; i++){
            while(j<n && ans[j] <= 2*ans[i]){
                j++;
            }
            cnt += j-i-1;
        }
        return cnt;
    }
};