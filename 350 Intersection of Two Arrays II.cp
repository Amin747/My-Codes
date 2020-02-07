class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int size1=nums1.size();
        int size2=nums2.size();
        int mini = min(size1, size2);
        vector<int>answer;
        int i=0;
        int j=0;
        while (i<size1){
            while(j<size2){
                if(nums1[i]==nums2[j]){
                    answer.push_back(nums2[j]);
                    nums2[j]=-1;
                    if(answer.size()==mini) return answer;
                    j=0;
                    break;
                }
                else{
                    j++;
                }
            }
            j=0;
            i++;
        }
        return answer;
    }
};
