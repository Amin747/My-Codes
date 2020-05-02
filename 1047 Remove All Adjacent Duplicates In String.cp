class Solution {
public:
    string removeDuplicates(string S) {
        stack<char>st;
        for (int i=0; i<S.length(); i++){
            if(st.empty()) st.push(S[i]);
            else{
                if(st.top()==S[i]){
                    st.pop();
                }
                else{
                    st.push(S[i]);
                }
            }
        }
        string ans = "";
        while(!st.empty()){
            ans.insert(ans.begin(), st.top());
            st.pop();
        }
        return ans;
    }
};
