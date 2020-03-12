class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string>nums = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string>result;
        if (digits.length()==0) return result;
        result.push_back(""); //initial case
        for (int i=0; i<digits.length(); i++){
            int n = digits[i]-'0';
            string candidate = nums[n];
            vector<string>temp;
            for (int j=0; j<candidate.length(); j++){
                for (int k=0; k<result.size(); k++){
                    temp.push_back(result[k]+candidate[j]);
                }
            }
            result = temp;
        }
        return result;
    }
};
