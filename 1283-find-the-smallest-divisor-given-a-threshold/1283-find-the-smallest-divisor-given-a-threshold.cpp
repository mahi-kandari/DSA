class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int n = nums.size();
        int high  = *max_element(nums.begin(),nums.end());
        int ans=high;
        int low = 1;
        while(low<=high){
            int mid = low + (high-low)/2;
            int curr=0;
            for(int i=0;i<n;i++){
                curr += ceil(float (nums[i])/mid);
            }
            if(curr <= threshold){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;

    }
};