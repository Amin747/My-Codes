class Solution {
public:
    bool validPalindrome(string s) {
        
        int start = 0;
        int end = s.length()-1;
        
        while (start <= end){
            if (s[start] == s[end]){
                start++;
                end--;
            }
            else {
                int st = start+1;
                int en = end;
                while (s[st]==s[en] && st<= en){
                    st++;
                    en--;
                    if (st>=en){
                        return true;
                    }
                }
                int ss = start;
                int es = end-1;
                while (s[ss]==s[es] && ss<= es){
                    ss++;
                    es--;
                    if (ss>=es){
                        return true;
                    }
                }
                return false;
            }
        }
        return true;
    }
};
