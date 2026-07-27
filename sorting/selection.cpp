void selection(vector<int> & nums){        //[3,2,4,5,1]
    int n = nums.size();
    for (int j=0;j<n;j++){
        int min = nums[j];
        for (int i=j+1;i<n;i++){
            if (nums[i] < min){
                min = nums[i];
            }
        }
        swap(min,nums[j]);
    }
    
}