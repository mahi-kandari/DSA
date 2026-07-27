pair<int,int> highFreq(vector<int> & nums){
    unordered_map<int,int> m;
    int x;
    for(int n : nums){
        m[n]++;
    }
    int maxFreq = INT_MIN;
    for (auto it : m){
        if (it.second > maxFreq){
            maxFreq = it.second;
            x= it.first;
        }
    }
    return {x, maxFreq};
}

