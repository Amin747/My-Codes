class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int one = words.size();
        int two = words.size();
        int min = words.size();
        for (int i=0; i<words.size(); i++){
            if (words[i]==word1){
                one = i;
            }
            if (words[i]==word2){
                two = i;
            }
            if (abs(two - one) < min && one!=two){
                min = abs(one-two);
            }
        }
        return min;
    }
};
