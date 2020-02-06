class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num>1){
            if (num%4==0){
            num=num/4;
            }
            else{
                return false;
            }
        }
        else if(num==1) return true;
        else return false;
        return isPowerOfFour(num);
    }
};
