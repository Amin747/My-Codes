class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        
        int minc = 0;
        int total = 0;
        
        //Get the upper and lower bounds of the binary search
        for(auto w : weights) {
            minc = max(minc, w);          //Get maximum single weight (capacity must be at least this to ship all)
            total += w;                  //Get total weight of entire shipment (1 day delivery)
        }
        
        while(minc < total) {                      //Increase minc until we reach total or until shipping within D days
            int cap = minc + (total-minc)/2;       //The final cap will be somewhere between the current cap and the total;
            int days = 1;                         //binary search starting at average between cap and total, move up or down
            int currWeight = 0;                   //as necessary
            
            for(auto w: weights) {               //Count the days
                if(currWeight + w > cap) {
                    days++;
                    currWeight = 0;
                }
                currWeight += w;
            }
            
            if(days > D)                    //If days too long, narrow search to values greater than cap (cap to total)
                minc = cap+1;
            else
                total = cap;                //if too short, narrow search to values less than cap (minc to cap)
        }
        
        return minc;
    }
};
