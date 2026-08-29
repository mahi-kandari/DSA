class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int min = INT_MAX;
        int p=0,ans=0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<min){
                min = nums[i];
            }
            p = nums[i] - min;
            ans = max(ans , p);
        }
        return ans;
    }
};