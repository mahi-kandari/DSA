vector<int> divisiors(int num){
    vector<int> nums;
    for(int i=1; i*i <= num;i++){
        if (num%i==0){
            nums.push_back(i);
            if (i!= num/i){
                nums.push_back(n/i);
            }
        }
    }
    return nums;
}