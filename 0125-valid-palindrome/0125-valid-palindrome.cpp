class Solution {
public:
    bool isPalindrome(string s) {
        string a ="";
        for( char c : s){
            if(isalnum(c)){
                a+= tolower(c);
            }
            
        }
        for(int i=0 , j= a.length()-1;i<a.length()/2;i++,j--){
            if(a[i]!=a[j]) return false;
        }
        return true;

        
    }
};