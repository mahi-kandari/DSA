class Solution {
public:
    bool solve(int mid, vector<int> &nums, int k){
        int n = nums.size();
        int count =1;
        int book = nums[0];
        for(int i =1;i<n;i++){
            if(nums[i]+book <= mid){
                book += nums[i];
            }
            else{
                count++;
                book = nums[i];
            }
        }
        return count <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        int high  = accumulate(nums.begin(),nums.end(),0);
        int ans = high;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(solve(mid,nums,k)){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};