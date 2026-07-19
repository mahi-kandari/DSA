// the problem here is that 1900, 2100, 2300 is divisible by 4 but not a leap year. 
// so the year must be divisible by 4 , 400 but not 100.
// 0000 -> 0 by cpp
bool leapYear(int year){
    if (year %4 ==0 ) {
        if (year % 400 == 0 || year % 100 !=0) return true;
    }
    return false;
}