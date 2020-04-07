class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int t = 0;
        int n = 0;
        if(typed[t]!=name[n]) return false;
        while (n<name.length() || t<typed.length()){
            cout << "t is " << t << " n is " << n << endl;
            if (n == name.length()-1) return true;
            
            if (typed[t] == name[n]){
                t++;
                if (n+1<name.length() && name[n]==name[n+1]){
                    n++;
                }
            }
            else if (n+1<name.length() && typed[t] == name [n+1]){
                n++;
                t++;
            }
            else return false;
        }
        return true;
    }
};
