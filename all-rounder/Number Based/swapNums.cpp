// without temp
pair<int,int> swapNums(int a , int b){     //a=5, b=3
    a= a+b;
    b= a-b;
    a= a-b;
    return { a,b };
}
// this function when test with large no. causes signed integer overflow, which is undefined behavior in C++.


pair<int,int> swapNums(int a , int b){     
    int temp = a;
    a=b;
    b= temp;
    return { a,b };
}


