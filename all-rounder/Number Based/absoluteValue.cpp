//The absolute value of a number is its distance from 0 on the number line.
//Since distance can never be negative, the absolute value is always non-negative.
//|-34| = 34

int absValue(int x){
    if (x<0){
        return -x;
    }
    return x;
}