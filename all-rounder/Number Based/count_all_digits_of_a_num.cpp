int countDigits(int n){
    int num= abs(n);
    if (num == 0) return 1;
    int count =0;
    while (num>0){
        count++;
        num = num/10;
    }
    return count;
}