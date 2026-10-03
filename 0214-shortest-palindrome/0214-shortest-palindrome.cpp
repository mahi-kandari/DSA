class Solution {
public:
    string shortestPalindrome(string s) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string lps_str = s + "#" + rev_s;
        
        int n = lps_str.size();
        vector<int> lps(n, 0);
        
        for (int i = 1; i < n; i++) {
            int j = lps[i - 1];
            while (j > 0 && lps_str[i] != lps_str[j]) {
                j = lps[j - 1];
            }
            if (lps_str[i] == lps_str[j]) {
                j++;
            }
            lps[i] = j;
        }
        
        int longest_palindrome_prefix_len = lps.back();
        string add = s.substr(longest_palindrome_prefix_len);
        reverse(add.begin(), add.end());
        
        return add + s;
    }
};