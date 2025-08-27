class Solution {
public:
    int longestValidParentheses(string s) {
        // Can be solved by stack or dp, dp is bit complicated
        // Let's explore stack approach
        stack<int> st;
        st.push(-1);
        int maxLen = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i] == '('){
                st.push(i); // push the index not value
            }else{
                st.pop();
                // now check the previous char
                if(st.empty()){
                    st.push(i);
                }else{
                    maxLen = max(maxLen, i-st.top());
                }
            }
        }
        return maxLen;
    }
};