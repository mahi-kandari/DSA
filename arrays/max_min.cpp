// standard method 

pair<int, int> MaxMin(const vector<int>& arr){
    if (arr.size()<=0) return {0,0};
    int maxVal = arr[0], minVal = arr[0];
    for (int i = 1; i < arr.size(); i++){
        if (arr[i]>maxVal) maxVal = arr[i];
        if (arr[i]<minVal) minVal = arr[i];
    }
    return {maxVal, minVal};
}

//optimized method : pair wise  {incorrect}
//[12,34,23,54,2,4]

pair <int,int> MinMax(const vector<int>& arr){
    if (arr.empty()) return {0,0};
    int currMax= arr[0], currMin= arr[1];
    int i=0;
    while(i < arr.size()){
        int maxVal= arr[i], minVal= arr[i+1];
        if (arr[i]<arr[i+1]){
            maxVal=arr[i+1];
            minVal= arr[i];
        }
        if (maxVal>currMax) currMax= maxVal;
        if (minVal<currMin) currMax = minVal;
        i += 2;
    }
    return { currMax, currMax};
} 

// correct code: 
pair<int, int> MinMax(const vector<int>& arr) {
    if (arr.empty())
        return {0, 0};

    int currMin, currMax;
    int i;

    // Initialization
    if (arr.size() % 2 == 0) {
        if (arr[0] < arr[1]) {
            currMin = arr[0];
            currMax = arr[1];
        } else {
            currMin = arr[1];
            currMax = arr[0];
        }
        i = 2;
    } else {
        currMin = currMax = arr[0];
        i = 1;
    }

    // Process elements in pairs
    while (i < arr.size() - 1) {
        int minVal, maxVal;

        if (arr[i] < arr[i + 1]) {
            minVal = arr[i];
            maxVal = arr[i + 1];
        } else {
            minVal = arr[i + 1];
            maxVal = arr[i];
        }

        if (minVal < currMin)
            currMin = minVal;

        if (maxVal > currMax)
            currMax = maxVal;

        i += 2;
    }

    return {currMin, currMax};
}

