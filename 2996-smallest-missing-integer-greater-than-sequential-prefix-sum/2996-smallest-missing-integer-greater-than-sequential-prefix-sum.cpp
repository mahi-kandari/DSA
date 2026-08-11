class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();
        int sum = nums[0] ,k=0;
        for (int i = 0; i < n;i++) {
            if (mp.find(nums[i]) == mp.end()) {
                mp[nums[i]]++; 
            }
        }
        for(int j=1;j<n;j++){
            if(nums[j]-1 == nums[j-1]){
                sum += nums[j];
            }
            else{
                break;
            }
        }
        while(mp.find(sum+k) != mp.end()) k++;
        return sum+k;
    }

};