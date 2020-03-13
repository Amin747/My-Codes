class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        int i = 0;
        
        while(i<asteroids.size()){
            if (asteroids[i]>0){        //we're adding positive to right, so won't collide
                st.push(asteroids[i]);
                i++;
            }
            else if(asteroids[i]<0){
                if(st.empty() || st.top()<0){  //st rmpty or top is negative, no collision
                    st.push(asteroids[i]);
                    i++;
                }
                else if(abs(asteroids[i]) > st.top()){  //top is + but ast is higher -, so stack pops, but i++ /.\ not happens, as we have to compare it to the res
                    st.pop();
                }
                else if (abs(asteroids[i])==st.top()){
                    st.pop();
                    i++;
                }
                else if (abs(asteroids[i]) < st.top()){
                    i++;
                }
            }
        }
        
        int size = st.size();
        vector<int>ans(size);
        for (int i=size-1; i >= 0; i--){
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};
