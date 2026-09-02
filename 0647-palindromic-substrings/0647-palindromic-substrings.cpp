class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n,0));
        
        int i =0 , j=0;
        int count =0;
        while(j<n){
            dp[i][j] = 1;
            count ++;
            i++;
            j++;
        }
        i = 0,j=1;
        while (j<n){
            if(s[i]==s[j]){
                dp[i][j] =1;
                count++;
            }
            i++;
            j++;
        }
        i=0,j=2;
        while(j<n){
            int nj = j;
            i=0;
            while(nj<n){
                if(s[i]== s[nj] && dp[i+1][nj-1] == 1){ 
                    dp[i][nj] = 1;
                    count++;
                }
                i++;
                nj++;
            }
            j++;
        }
        return count;

    }
};