class Solution {
public:
    string intToRoman(int num) {
        string ans;
        
        vector<string>thousands = {"", "M", "MM", "MMM"};
        vector<string>hundreds = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        vector<string>tens = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        vector<string>units = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        
        if (num/1000 > 0) {
            ans+=(thousands[num/1000]);
            num = num%1000;
        }
        if (num/100 > 0) {
            ans+=(hundreds[num/100]);
            num = num%100;
        }
        if (num/10 > 0) {
            ans+=(tens[num/10]);
            num = num%10;
        }
        if (num >= 0) {
            ans+=(units[num]);
        }
        return ans;
    }
};
