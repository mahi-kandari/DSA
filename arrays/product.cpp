int product(vector<int>& num){
    int p=1;
    for(int i=0; i<num.size(); i++){
        p=p*num[i];
        if (p==0) return 0;
    }
    return p;
}