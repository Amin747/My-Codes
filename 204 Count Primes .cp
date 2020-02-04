class Solution {
public:
    int countPrimes(int n) {
        if (n==0||n==1||n==2)return 0;
        vector<bool>primes(n);
        for (int i=0; i<n ; i++){
            primes[i]=true;
        }
        primes[0]=false;
        primes[1]=false;
        for (int i=2; i*i<n; i++){
            if (primes[i]){
                for (int j=i; i*j<n; j++){
                    primes[i*j]=false;
                }
            }
        }
        int count=0;
        for (int k=2; k<n; k++){
            if (primes[k]==true){
                count++;
            }
        }
        return count;
    }
};
