class Solution {
public:
    bool isHappy(int n) {
    int temp = 0;
    int count = 0;
    map<int,int>m;
    while (n!=1){
        while (n!=0){
            temp += pow(n%10, 2);
            n/=10;
        }
        n=temp;
        if (m[n] >=1 ) return false;
        m[n]++;
        temp = 0;
    }
    if (n==1) {return true;
    }
    return false;
    }
};

