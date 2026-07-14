// standard method 

pair<int, int> MaxMin(const vector<int>& arr){
    if (arr.size()<=0) return {0,0};
    int maxVal = arr[0], minVal = arr[0];
    for (int i = 0; i < arr.size(); i++){
        if (arr[i]>maxVal) maxVal = arr[i];
        if (arr[i]<minVal) minVal = arr[i];
    }
    return {maxVal, minVal};
}

//optimized method : pair wise 
