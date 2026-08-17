class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int o =0, j=n-1, i=0;
        while(i<j){
            if (nums[i]+nums[j] == k){
                 o++;
                 i++;
                 j--;
            }
            else if  (nums[i]+nums[j]>k){
                j--;
            }
            else i++;
        }
        return o;
    }
};