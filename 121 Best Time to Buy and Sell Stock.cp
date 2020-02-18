class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        if (prices.size()==0) return profit;
        int min = *max_element(prices.begin(), prices.end());
        
        for (int i=0; i<prices.size(); i++){
            if (prices[i] < min) min = prices[i];
            else{
                if (prices[i]-min>profit){
                    profit = prices[i]-min;
                }
            }
        }
        return profit;
    }
};
