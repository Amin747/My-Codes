class Solution {
public:
    int maximumSwap(int num) {
        vector<int>digits;
        int copy = num;
        int ans = 0;
        bool found = false;
        while(num>0){
            digits.insert(digits.begin(), num%10);
            num = num/10;
        }
        int start = 0;
        while(start < digits.size()){
            if (start==digits.size()-1) break;
            int max = 0;
            int max_index=-1;
            for (int i=digits.size()-1; i>=start+1; i--){
                if (digits[i]>max){
                    max = digits[i];
                    max_index = i;
                }
            }
            if (max_index >=0 && digits[max_index]>digits[start]){
                found = true;
                swap(digits[max_index], digits[start]);
                int power=0;
                for (int j=digits.size()-1; j>=0; j--){
                    ans+=digits[j]*pow(10,power);
                    power++;
                }
                return ans;
            }
            start++;
        }
        return copy;
    }
};
