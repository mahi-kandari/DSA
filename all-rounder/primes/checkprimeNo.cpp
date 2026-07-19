bool prime(int num){
    if (n<=1) return false;
    for (int i=2; i<=(n/2); i++){
        if (n%i == 0) return false;
    }
    return true;
}

// this is good for composite no.s [for eg= 49, loop stops at i=7] but not for prime no.s, therefore  optimzed version is : 

bool prime(int num){
    if (n<=1) return false;
    for (int i=2; i*i <= num; i++){ 
        if (num % i == 0) return false;
    }
    return true;
}
//num = 47 (prime) Checks only: 2, 3, 4, 5, 6, since √47 ≈ 6.8.