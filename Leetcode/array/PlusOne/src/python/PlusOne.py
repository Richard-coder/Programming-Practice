class Solution:
    def plusOne(self,digits):
        dig=1;
        for i in reversed(xrange(len(digits))):
            digits[i]+=dig
            dig=digits[i]/10;
            digits[i]%=10
        if dig:
            digits=[1]+digits
        return digits
if __name__=="__mian__":
    print Solution().plusOne([9,9,9,9])