class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
      vector<int> pos;
      vector<int> neg;
      int n = nums.size();
      for(int i=0;i<n;i++){
        if(nums[i]>0){
            pos.push_back(nums[i]);
        }
        else{
            neg.push_back(nums[i]);
        }
      }
      for(int j=0;j<n;j++){
        if(j%2 == 0){
            nums[j] = pos[j/2];
        }
        else{
            nums[j] = neg[j/2];
        }
      }
      return nums;  
    }
};