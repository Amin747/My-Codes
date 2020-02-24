class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.length()-1;
        int j = num2.length()-1;
        int carry = 0;
        string ans;
        
        while (i >=0 || j>=0){
            int sum = carry;
            if (i>=0){
                sum+= num1[i]-'0';
                i--;
            }
            if (j>=0){
                sum+= num2[j]-'0';
                j--;
            }
            carry = sum/10;
            sum = sum%10;
            char c = sum+48;
            cout << c << endl;
            ans.push_back(c);
        }
        if (carry!=0) ans.push_back('1');
        cout << ans << endl;
        string ans2;
        for (int i=ans.length()-1; i>=0; i--){
            ans2.push_back(ans[i]);
        }
        return ans2;
    }
};
