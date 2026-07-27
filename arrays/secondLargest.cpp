int secondLargest(vector<int> & nums){
    int max1= nums[0];
    int max2 = INT_MIN;
    for(int i=1;i<nums.size();i++){
        if ( nums[i]>max1){
            max2 = max1;
            max1 = nums[i];
        }
        else if(nums[i]<max1 && nums[i]>max2){
            max2= nums[i];
        }
    }
    return max2;
}