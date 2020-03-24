class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>vec(26);
        for(int i=0; i<tasks.size(); i++){
            vec[tasks[i]-'A']++;
        }
        sort(vec.begin(), vec.end());
        int max_val = vec[25]-1; //we don't need to have slots after last element
        int slots = max_val*n;
        for (int i=24; i>=0; i--){
            slots-=min(vec[i], max_val);
        }
        if (slots>0) return tasks.size() + slots;
        return tasks.size();
    }
};
