class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        set<string>tens;
        set<string>ans;
        vector<string>res;
        if(s.length()<=9) return res;
        for(int i=0; i<s.size()-9; i++){
            if(!tens.count(s.substr(i,10))) tens.insert(s.substr(i,10));
            else if(tens.count(s.substr(i,10)) && !ans.count(s.substr(i,10))){
                ans.insert(s.substr(i,10));
                res.push_back(s.substr(i,10));
            }
        }
        
        return res;
    }
};
