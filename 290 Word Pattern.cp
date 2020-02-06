class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int pat_size = pattern.length();
        int str_size = str.length();
        vector<string>vec;
        
        int start = 0;
        int end = 0;
        int count = 0;
 while (end < str_size){
    while (end < str_size){
        if (str[end]==' ' ){
            vec.push_back(str.substr(start,count));
            start=end+1;
            end++;
            count = 0;
            break;
        }
        else if (end==str_size-1){
            vec.push_back(str.substr(start, count+1));
            end++;
            break;
        }
        else{
            end++;
            count++;
        }
    }
 }
        if (vec.size()!=pattern.size()) return false;

        map<char, string> m;
        for (int i=0; i<pat_size; i++){
            if (m.count(pattern[i])==0){
                m[pattern[i]]=vec[i];
            }
            else{
                if (m[pattern[i]]!=vec[i])
                    return false;
            }
        }
        for (int i=0; i<pat_size; i++){
            for (int j=i; j<pat_size; j++){
                if (pattern[i]!= pattern[j] && m[pattern[i]]==m[pattern[j]]) return false;
            }
        }
        
        return true;
        
    }
};
