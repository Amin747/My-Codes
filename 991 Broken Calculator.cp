class Solution {
public:
    int brokenCalc(int X, int Y) {
        int ans = 0;
        if (X==Y) return ans;
        while(X<Y){
            if (Y%2==1){
                Y++;
                ans++;
                if (X==Y){
                    return ans;
                }
            }
            else {
                ans++;
                Y/=2;
                if (X==Y){
                    return ans;
                }
            }
        }
        while (X>Y){
            return ans+=X-Y;
        }
        return ans;
    }
};
