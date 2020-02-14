class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
    int count=0;
    map<int,int>m;
        for (int i=0; i<time.size(); i++){
            time[i]=time[i]%60;
        }
        
        for (int i=0; i<time.size(); i++){
            m[time[i]]++;
        }
        for (int i = 0; i<31; i++){
            if (i==0 || i==30) count += m[i]*(m[i]-1)/2;
            else if (m[i]) {
                count+=m[i]*m[60-i];
            }
        }
    return count;
    }
};
