class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k==num.length()) return "0";
        int i=1;
        stack<char>st;
        st.push(num[0]);
        while(!st.empty() && i<num.length()){
            while(!st.empty() && num[i]<st.top() && k>0){
                st.pop();
                k--;
            }
            st.push(num[i]);
            i++;
        }
        
        while(k>0){
            st.pop();
            k--;
        }
        
        string ans = "";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        while(ans.length()>1 && ans[0]=='0') ans.erase(ans.begin());
        return ans;
    }
};
