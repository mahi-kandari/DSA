class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        int ans=1,maxa = 1;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i =1;i<n;i++){
            if(nums[i]== nums[i-1]){
                continue;
            }
            if(nums[i]== nums[i-1]+1){
                ans++;
                maxa = max(ans,maxa);
            }
            else{
                ans=1;
            }

        }
        return maxa;
    }
};