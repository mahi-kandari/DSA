bool armstrong(int n){. //157
    int arm=0;
    int count = 0;
    int temp = n;
    int k=n;
    while(temp > 0){
        count++;
        temp = temp/10;
    }
    while (k>0){
        int d = k%10;
        arm = arm + pow(d,count);
        k /=10;
        
    }
    if (arm == n) return true;
    return false;
}