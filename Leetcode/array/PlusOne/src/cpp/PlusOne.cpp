class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        plus(digits,1);
        return digits;
    }
private:
    void plus(vector<int>& digits,int dig){
        int sum=0;
        for(int i=digits.size()-1;i>=0;i--){
            sum=digits[i]+dig;
            digits[i]=sum%10;
            dig=sum/10;
        }
        if (dig)
            digits.insert(digits.begin(),1);
    }
};