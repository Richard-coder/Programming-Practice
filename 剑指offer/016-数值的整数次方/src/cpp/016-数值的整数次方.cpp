class Solution {
public:
    double Power(double base, int exponent) {
        double res=1,cur=base;
        unsigned int n;
        if(exponent>0){
            n=(unsigned int)(exponent);
        }else if(exponent<0){
            if(fabs(base-0)<0.00000001)
                throw new logic_error("分母不能为0");
            n=(unsigned int)(-exponent);
        }else{// n==0
            return 1;// 0的0次方
        }
        
        while(n){
            if((n&0x01)==1)
                res*=cur;
            cur*=cur;// 翻倍
            n>>=1;// 右移一位
        }
        
        return exponent>=0?res:(1/res);
    }
};