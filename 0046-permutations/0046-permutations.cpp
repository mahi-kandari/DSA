class Solution {
public:
    void solve(vector<int>& nums, int ind, vector<vector<int>> &result){
        if ( ind == nums.size()-1){
            result.push_back(nums);
            return;
        }
        for( int i= ind; i<nums.size();i++){
            swap(nums[i],nums[ind]);
            solve(nums,ind+1,result);
            swap(nums[i],nums[ind]);
        }
      } 
    vector<vector<int>> permute(vector<int>& nums) {
       vector<vector<int>> result;
       int ind =0;
    solve(nums,ind,result);
    return result;
       
    }

};