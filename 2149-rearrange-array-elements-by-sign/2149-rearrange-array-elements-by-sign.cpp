class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if (nums[i]<0) neg.push_back(nums[i]);
            else pos.push_back(nums[i]);
        }
        for(int j = 0;j<nums.size();j++){
            if (j%2 == 0){
                ans.push_back(pos[j/2]);
            }
            else{
                ans.push_back(neg[j/2]);
            }
        }
        return ans;
    }
};