class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        int ans = high;
        while (low<=high){
            int mid = low + (high-low)/2;
            int sub = 1;
            int count = 0;
            for(int i =0;i<n;i++){
                count += nums[i];
                if (count > mid){
                    count = nums[i];
                    sub++;
                }

            }
            if (sub > k){
                low = mid+1;
            }
            else{
                ans = mid;
                high  = mid-1;

            }
        }
        return ans;
    }
};