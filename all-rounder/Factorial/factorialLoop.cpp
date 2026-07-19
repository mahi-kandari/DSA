int factorial(int n){
    int fact = 1 , i=2;  //n=2
    while (i<=n){
        fact= fact*i;
        i++;
    }
    return fact;
}

// for loop: 
int factorial(int n){
    int fact = 1;
    for(int i=2; i<=n; i++){
        fact = fact * i ;
    }
    return fact;
}