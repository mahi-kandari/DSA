float avgArray(int arr[],int n){
    if (n<=0) return 0;
    float s=0;
    for (int i = 0; i<n; i++){
        s+= arr[i];
    }
    return s/n;
}