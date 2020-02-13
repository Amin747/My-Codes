class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        map<int,int>m1;
        vector<vector<int>>ans;
        for (int i=0; i<items.size(); i++){
            if (!m1[items[i][0]]){
                m1[items[i][0]] = 1;
            }
            else
                m1[items[i][0]]++;
        }
        for (int i=1; i<=100; i++){
            if (m1[i]>=1 && m1[i]<=5){
                int total =0;
                for(int j=0; j<items.size(); j++){
                    if (items[j][0]==i){
                        total+=items[j][1];
                    }
                }
                vector<int>v = {i,total/m1[i]};
                ans.push_back(v);
            }
            else if (m1[i] >= 5){
                int max=0;
                int counter = 0;
                int total = 0;
                int dex =0;
                while(counter<5){
                    for(int j=0; j<items.size(); j++){
                        if (items[j][0]==i){
                            if(items[j][1]>=max){
                                max = items[j][1];
                                dex = j;
                            }
                        }
                    }
                    total+=max;
                    items.erase(items.begin() + dex);
                    counter++;
                    max =0;
                }
                vector<int>v = {i,total/5};
                ans.push_back(v);
            }
        }
        return ans;
    }
};
