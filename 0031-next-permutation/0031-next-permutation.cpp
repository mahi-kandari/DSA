class Solution {
public:
    void nextPermutation(vector<int>& nums) {
      int b =-1, n = nums.size();
      for(int i =n-2;i>=0;i--){
        if(nums[i]<nums[i+1]){
            b = i;
            break;
        }
      }
      if(b==-1){
        reverse(nums.begin(),nums.end());
        return;
      } 
      for(int j = n-1;j>=0;j--){
        if(nums[j]>nums[b]){
            swap(nums[j],nums[b]);
            break;
        }
      }
      reverse(nums.begin()+b+1,nums.end()); 
    }
};