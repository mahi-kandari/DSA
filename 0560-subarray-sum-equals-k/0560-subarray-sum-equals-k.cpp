class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int c=0;
        unordered_map<int,int> mp;
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            
            if(mp.find(sum-k) != mp.end()){
                c += mp[sum-k];
            }
            if (sum==k){
                c++;
            }
            mp[sum]++;

        }
        return c;
    }
};