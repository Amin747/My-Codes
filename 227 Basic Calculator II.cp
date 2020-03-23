class Solution {
public:
    int calculate(string s) {
        char op = '+';
        int i = 0;
        long long ans = 0;
        int interim = 0;
        long long num = 0;
        
        while (i<s.length()){
            if (isdigit(s[i])){
                num = 0;
                while (i<s.length() && isdigit(s[i])){
                    num += num*10 + s[i] - '0';
                    i++;
                }
                if (op=='-' || op=='+'){
                    ans += interim;
                    if (op=='-') interim = -1 * num;
                    else if (op=='+') interim = num;
                }
                else if (op=='*'){
                    interim = interim * num;
                }
                else if (op=='/'){
                    interim = interim / num;
                }
                continue;
            }
            else if (s[i]!=' '){
                op = s[i];
            }
            i++;
        }
        ans += interim;
        return ans;
    }
};
