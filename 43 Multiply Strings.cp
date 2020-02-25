class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.length();
        int n2 = num2.length();
        vector<int>val(n1+n2);
        
        for (int i=n1-1; i>=0; i--){
            for(int j=n2-1; j>=0; j--){
                int mul = (num1[i]-'0')*(num2[j]-'0');
                int sum = val[i+j+1] + mul;
                val[i+j+1] = sum%10;
                val[i+j] += sum/10;
            }
        }
        int start=0;
        while (val[start]==0){
            start++;
            if (start == val.size()-1) break;
        }
        string ans;
        for (int i=start; i<=val.size()-1; i++){
            char a = val[i]+48;
            ans.push_back(a);
        }
        if (ans.length()==0) return "0";
        return ans;
    }
};
