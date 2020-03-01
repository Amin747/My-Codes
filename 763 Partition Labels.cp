class Solution {
public:
    vector<int> partitionLabels(string S) {
        map<char,int>m;
        for (int i=0; i<S.length(); i++){
            m[S[i]]=i;
        }
        int first = 0;
        int second = m[S[first]];
        vector<int>ans;
        while (first<S.length()){
            second = m[S[first]];
            for(int j=0; j<=second; j++){
                if (m[S[j]]>second){
                    second = m[S[j]];
                }
            }
            ans.push_back(second-first+1);
            first = second+1;
        }
        return ans;
    }
};
