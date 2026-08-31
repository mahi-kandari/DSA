class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size();
        int n = needle.size();
        int start =0,i=0,j=0;
        bool found  = false;
        while(i<m){
            if (haystack[i] == needle[j]){
                i++;
                j++;
                if(j == n){
                    found = true;
                    break;
                }
            }
            else{
                
                start++;
                i= start;
                j=0;
            }
        }
        if(found) return start;
        else return -1;
    }
}

;