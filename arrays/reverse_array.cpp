// two pointer 
void reverseArray(int arr[], int n){
    if (n <=  1) return; // No reversal needed for empty or single-element array.
    for (int i = 0,j = n - 1; i < j; i ++, j --){
        swap(arr[i],arr[j]);
    }
}
