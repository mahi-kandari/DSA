class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int cnt =1,ans=1;
        if (nums.empty()) return 0;
        for(int i =1;i<nums.size();i++){
            
            if(nums[i] == nums[i-1]) continue;
            if (nums[i] == nums[i-1]+1){
                cnt++;
                ans = max(ans,cnt);
            }
            else{
                cnt = 1;
            }
        }
        return ans;
    }
};