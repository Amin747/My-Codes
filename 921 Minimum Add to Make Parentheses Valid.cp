class Solution {
public:
    int minAddToMakeValid(string S) {
        
        stack<char>st;
        int i = 0;
        while (i<S.length()){
            if (st.empty()) st.push(S[i]);
            else if (st.top()=='(' && S[i]==')') st.pop();
            else st.push(S[i]);
            i++;
        }
        return st.size();
    }
};
