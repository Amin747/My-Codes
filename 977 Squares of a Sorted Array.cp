class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int A_size = A.size();
        vector<int>ans(A_size);
        if (A_size==0) return A;
        if (A_size==1) {
            A[0]=A[0]*A[0];
            return A;
        }
        if (A_size==2) {
            if (A[0]*A[0] >= A[1]*A[1]){
                ans[0] = A[1]*A[1];
                ans[1] = A[0]*A[0];
                return ans;
            }
            else{
                ans[0] = A[0]*A[0];
                ans[1] = A[1]*A[1];
                return ans;
            }
        }
        int negs = 0;
        for (int i=0; i<A_size; i++){
            if (A[i]<0){
                negs++;
            }
        }
        if (negs==0){
            for (int i=0; i<A_size; i++){
                ans[i] = A[i]*A[i];
            }
            return ans;
        }
            
            
        int mid_index;
        int min;
        
        for (int i=0; i<A_size; i++){
            if (A[i] < 0 && A[i+1] >= 0){
                if ((pow(A[i],2) < pow(A[i+1],2))){
                    mid_index = i;
                }
                else {
                    mid_index = i+1;
                }
            }
        }
        ans[0]=pow(A[mid_index],2);
        int right_index = mid_index+1;
        int left_index = mid_index-1;
        int count =1;
        while((right_index<=A_size || left_index>=-1) && count <A_size){
            if (left_index == -1) {
                ans[count]= pow(A[right_index],2);
                right_index++;
            }
            else if(right_index == A_size){
                ans[count] = pow(A[left_index],2);
                left_index--;
            }
            else if (pow(A[right_index],2) <= pow(A[left_index],2)){
                ans[count]=pow(A[right_index],2);
                right_index++;
            }
            else {
                ans[count]=pow(A[left_index],2);
                left_index--;
            }
            count++;
        }
        return ans;
    }
};
