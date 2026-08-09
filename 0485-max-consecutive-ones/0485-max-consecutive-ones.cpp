class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int j=0 , count=0 , maxVal= 0;
        for(int i=0;i<nums.size();i++){
            if (nums[i] == 1){
                count++;
                maxVal = max(maxVal, count);
            }
            else{
                count = 0;
                
            } 
        }
        return maxVal;
    }
};