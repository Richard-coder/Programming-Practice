class Solution {
public:
    int Fibonacci(int n) {
        int result[2]={0,1};
        if (n<2)
            return result[n];
        long long int f_zero=0, f_one=1,f_res=0;
        int count=1;
        while(count<n){
            f_res=f_zero+f_one;
            f_zero=f_one;
            f_one=f_res;
            count++;
        }
        return f_res;
    }
};