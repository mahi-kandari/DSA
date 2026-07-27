int reverseNum(int n){. //23454
    int revnum=0 , r;
    while(n>0){
        r = n%10;
        revnum = revnum*10 + r;
        n= n/10;
    }
    return revnum;
}