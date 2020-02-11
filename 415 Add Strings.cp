class Solution {
public:
    string addStrings(string num1, string num2) {
        int size1 = num1.length()-1;
        int size2 = num2.length()-1;
        int carry = 0;
        string ans;
        map<char,int>m1;
        int num=0;
        for (char i = 48; i<59; i++){
            m1[i]=num;
            num++;
        }
        map<int,char>m2;
        char a = 48;
        for (int i = 0; i<=9; i++){
            m2[i]=a;
            a++;
        }
        while(size1 >=0 && size2 >=0){
            if ((m1[num1[size1]]+m1[num2[size2]]+carry)<10){
                ans.insert(ans.begin(), m2[m1[num1[size1]]+m1[num2[size2]]+carry]);
                size1--;
                size2--;
                carry=0;
            }
            else{
                ans.insert(ans.begin(), m2[(m1[num1[size1]]+m1[num2[size2]]+carry)%10]);
                size1--;
                size2--;
                carry=1;
            }
        }
        while (size1 >=0 || size2 >=0){
            if (size1 >=0){
                if (m1[num1[size1]]+carry>=10){
                    ans.insert(ans.begin(),m2[(m1[num1[size1]]+carry)%10]);
                    carry=1;
                }
                else{
                    ans.insert(ans.begin(), m2[(m1[num1[size1]]+carry)%10]);
                    carry=0;
                }
                size1--;
            }
            if (size2 >=0){
                if (m1[num2[size2]]+carry>=10){
                    ans.insert(ans.begin(), m2[(m1[num2[size2]]+carry)%10]);
                    carry=1;
                }
                else{
                    ans.insert(ans.begin(), m2[(m1[num2[size2]]+carry)%10]);
                    carry=0;
                }
                size2--;
            }
        }
        if (carry==1) ans.insert(ans.begin(),'1');
        return ans;
    }
};
