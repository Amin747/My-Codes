class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num==0 || num==NULL) return false;
        if (num==1)return true;
        for (long int i=1; i<=num/2; i++){
            if (num==i*i){
                return true;
            }
        }
        return false;
    }
};
