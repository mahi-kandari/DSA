bool palindrome(int n){
    int rev =0;
    int original = n;
    while(n>0){
        int r = n%10;
        rev = rev*10 + r;
        n= n/10;
    }
    if (original==rev) return true;
    else return false; 
}