void countNum(vector<int> arr){
    int cp=0, cn = 0, cz=0 ;
    for (int i=0 ; i< arr.size();i++){
        if (arr[i]==0) {
            cz++;
        } else if (arr[i]>0){
            cp++;
        }else cn++;
    }
    cout<< "positive: "<< cp;
    cout<< "\nnegative: "<< cn;
    cout<< "\nzeros: "<< cz;

}
