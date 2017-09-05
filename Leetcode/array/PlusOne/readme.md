66. Plus One

tags： Array，Math

---

## 题目原文
Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.

You may assume the integer do not contain any leading zero, except the number 0 itself.

The digits are stored such that the most significant digit is at the head of the list.

## 题目大意
用vector保存一个数字，个位数在索引最大的位置，计算这个数字加1后的结果。


## 解题思路
写的更通用一些，可以加0-9，sum表示某一位上的相加和，dig表示进位，值只能取0或1，某一位上相加后为sum%10。


## 代码
### [c++代码](./src/cpp/PlusOne.cpp)
```c++
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
```

### [python代码](./src/python/PlusOne.py)
```python
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
```
