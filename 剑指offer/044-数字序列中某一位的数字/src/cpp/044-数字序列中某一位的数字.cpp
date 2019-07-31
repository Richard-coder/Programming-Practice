class Solution {
public:
    int digitAtIndex(int n) {
        if(n<=0)
            return 0;
        long long i=1,s=9,base=1;
        while(n>i*s){
            if(i==1)
                n-=10;
            else
                n-=i*s;
            i++;
            s=s*10;
            base=base*10;
        }
        if(i==1)
            n=n-1;
        int number=base+n/i;
        int r=n%i;
        for(int j=i-r;j>1;j--) number/=10;
        return number%10;
    }
};