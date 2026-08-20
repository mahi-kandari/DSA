class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int cp=-1, n= nums.size(), grt = INT_MAX;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                cp = i;
                break;
            }
        }
        if (cp == -1){
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int j=n-1;j>cp;j--){
            if(nums[j]>nums[cp] && nums[j]<grt){
                grt = nums[j];
                swap(nums[cp],nums[j]);
                
            }
        }
        reverse(nums.begin()+cp+1,nums.end());

    }
};