class Solution {
public:
    bool search(int start, int ele, vector<int> & nums){
        for(int i=start ; i<nums.size();i++){
            if (nums[i]==ele) return true;
        }
        return false;
    }
    int missingInteger(vector<int>& nums) {
        int sum =nums[0] , j=0,k=0, ind =0;
        for(int i=1;i<nums.size();i++){
            if (nums[i] == nums[j]+1 && j<nums.size()){
                sum+= nums[i];
                ind = i;
                j++;
            }
            else{
                break;
            }
            
        }
        while(search(0, sum+k,nums)){
            k++;
        }
        return sum+k;
    }
};