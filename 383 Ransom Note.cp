class Solution {
public:
    bool canConstruct(string r, string m) {
        
        if (r.size()==0)return true;
        if (m.size()==0)return false;
        if (r.size()==0)return true;
        int r_size = r.length();
        map<char,int>mr;
        for(int i=0;i<r.length();i++){
            if (!mr[r[i]]){
                mr[r[i]]=1;
            }
            else{
                mr[r[i]]++;
            }
        }
        
        for(int i=0; i<m.length(); i++){
            if (mr[m[i]]){
                mr[m[i]]--;
            }
        }
        for (char a= 'a'; a<= 'z'; a++){
            if (mr[a]){
                if (mr[a]>0){
                    return false;
                }
            }
        }
        return true;
    }
};
