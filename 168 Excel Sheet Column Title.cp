class Solution {
public:
    string convertToTitle(int n) {
        vector<char>ans;
        string answer;
        if (n==1){
            answer+='A';
            return answer;
        }
        while (n>0){
            n--;
            ans.insert(ans.begin(), ((char)(n%26) + 65));
            n = n/26;
        }
        for(int i=0; i<ans.size(); i++){
            answer+=ans[i];
        }
        return answer;
     }
};
