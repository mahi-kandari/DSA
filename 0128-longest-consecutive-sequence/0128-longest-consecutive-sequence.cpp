class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        int ans= 0;
        int n = nums.size();
        for(int i =0;i<n;i++ ){
            st.insert(nums[i]);
        }
        for(auto it : st){
            int val = it;
            ans = max(ans,1);
            if(st.find(val-1) != st.end()) continue;
            int curr=1;
            while(st.find(val+1)!= st.end()){
                curr++;
                val++;
            }
            ans = max(ans,curr);
        }
        return ans;
    }
};