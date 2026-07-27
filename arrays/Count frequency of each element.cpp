void frequecy(vector<int>& nums){
    unordered_map<int,int> m;
    for (int n: nums){
        m[n]++;
    }
    for(auto it : m){
        cout<< it.first()<<" "<< it.second();
    }
}

void frequecy(vector<int>& nums){
    for(int i=0;i<nums.size();i++){
        int count = 0;
        for(int j=0; j<nums.size();j++){
            if (nums[i]==nums[j]){
                count++;
            }
            
        }
        cout<<nums[i]<<" "<<count;
    }
}

