class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int>ans(T.size());
        stack<int>st;
        for (int i=T.size()-1; i>=0; i--){
            while (!st.empty() && T[st.top()] <= T[i]){
                st.pop();
            }
            if (st.empty()) ans[i] = 0;
            else ans[i] = st.top() - i;
            st.push(i);
        }
        return ans;
    }
};
