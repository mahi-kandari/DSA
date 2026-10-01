class Solution {
public:
    int expand(string s, int left, int right){   
        while(left>=0 && right<s.size() && s[left] == s[right]){
            
                left--;
                right++;
            
        }
        return right - left-1;
    }
    string longestPalindrome(string s) {
        int maxlen =1;
        int len ,  start=0;
        for(int i = 0;i<s.length();i++){
            int oddP = expand(s,i,i);
            int evenP = expand(s,i,i+1);
            len = max(oddP,evenP);
            if(len > maxlen){
                maxlen = len;
                start = i- (len-1)/2;
            }
        }
        return s.substr(start,maxlen);
    }
};