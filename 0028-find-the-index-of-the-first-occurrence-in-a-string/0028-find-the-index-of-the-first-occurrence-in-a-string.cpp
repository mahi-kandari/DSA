class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size();
        int n = needle.size();
        for(int i =0;i<m;i++){
            for(int j =i,k=0;j<m;j++,k++){
                if(haystack[j]!=needle[k]) break;
                if(k == n-1){
                    return i;
                } 
            }
            
        }
        return -1 ;
    }
}

;