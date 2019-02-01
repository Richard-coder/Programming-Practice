# python2 代码
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
    
# python3 代码
class Solution:
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        return self.plusX(digits, 1)
    def plusX(self, digits, dig):
        for i in reversed(range(len(digits))):
            sum=digits[i]+dig
            dig=sum//10
            digits[i]=sum%10
        if dig:
            digits=[1]+digits
        return digits