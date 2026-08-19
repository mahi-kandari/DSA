class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<int> result;
        for (int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto it: mp){
            if (it.second <2 ){ 
                result.push_back(it.first);
            }
        }
        return result;
    }
};