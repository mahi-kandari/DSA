class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int min = INT_MAX;
        for(int i=0;i<n;i++){
            if (nums[i]<min) min=nums[i];
            ans = max(ans,nums[i]-min);
        }
        return ans;
    }
};
