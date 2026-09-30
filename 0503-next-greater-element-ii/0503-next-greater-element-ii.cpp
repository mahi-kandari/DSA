class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr;
        for(int i=0;i<n;i++){
            arr.push_back(nums[i]);
        }
        vector<int> ans;
        arr.insert(arr.end(),nums.begin(),nums.end());
        for(int i =0;i<n;i++){
            bool found = false;
            for(int j=i+1;j< i+n;j++ ){
                if(arr[j]>arr[i]){
                    ans.push_back(arr[j]);
                     found = true;
                    break;
                }
            }
            if(!found) ans.push_back(-1);
            
        }
        return ans;
    }
};