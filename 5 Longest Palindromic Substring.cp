class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()==0) return "";
        int start = 0, end = 0;
        for(int i=0; i<s.length(); i++) {
            int len1 = expandAroundCenter(s, i, i);
            int len2 = expandAroundCenter(s, i, i+1);
            int maxlen =max(len1, len2);
            if(maxlen > (end-start)) {
                start = i - ((maxlen-1)/2);
                end = i + (maxlen/2);
            }
        }
        return s.substr(start, end-start+1);
    }
    
    int expandAroundCenter(string s, int left, int right) {
        if(s.length()==0 || left>right) return 0;
        while(left>=0 && right<s.length() && s[left]==s[right]) left--, right++;
        return right-left-1;
    }
};
