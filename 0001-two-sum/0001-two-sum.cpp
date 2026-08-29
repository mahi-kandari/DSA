class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        int c;
        for (int i = 0; i < nums.size(); i++) {
            c = target - nums[i];
            if (mp.find(c) != mp.end()) {
                return {i, mp[c]};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};