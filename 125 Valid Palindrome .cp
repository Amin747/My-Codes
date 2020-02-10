class Solution {
public:
    bool isPalindrome(string s) {
        if (s.length()==0) return true;
        if (s.length()==1) return true;
        int size = s.length()-1;
        
        int start = 0;
        int end = size;
        while (start<end){
            if (!isalnum(s[start])){
                start++;
            }
            else if (!isalnum(s[end])){
                end--;
            }
            else if (tolower(s[start])!=tolower(s[end])){
                return false;
            }
            else {
                start++;
                end--;
            }
        }
        return true;
    }
};
