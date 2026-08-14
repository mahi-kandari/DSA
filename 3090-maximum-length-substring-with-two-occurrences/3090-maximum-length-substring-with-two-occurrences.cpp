class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n= s.length();
        int l=0 , len =0, maxlen= 0;
        unordered_map<char,int> mp;
        for(int r=0;r<n;r++){
            mp[s[r]]++; 
            while(mp[s[r]]>2){
                mp[s[l]]--;
                l++;
            }
            len = r - l+1;
            maxlen = max(maxlen , len);
        }
        return maxlen;
    }
};
