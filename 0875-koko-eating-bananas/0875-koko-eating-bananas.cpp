class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int high = *max_element(piles.begin(),piles.end());
        int low =1;
        int ans = high;
        while(low<=high){
            int mid = low+(high-low)/2;
            long long  count =0;
            for(int x:piles){
                count+= (x +mid -1LL)/mid;
            }
            if (count<=h){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};