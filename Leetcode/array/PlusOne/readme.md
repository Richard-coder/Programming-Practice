66. Plus One

tags： Array，Math

---

## 题目原文
[原文网址](https://leetcode.com/problems/plus-one/description/)

Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.

You may assume the integer do not contain any leading zero, except the number 0 itself.

The digits are stored such that the most significant digit is at the head of the list.

## 题目大意
用vector保存一个数字，个位数在索引最大的位置，计算这个数字加1后的结果。


## 解题思路
写的更通用一些，可以加0-9，sum表示某一位上的相加和，dig表示进位，值只能取0或1，某一位上相加后为sum%10。

## 注意事项

虽然不判断输入数组是否为空, 程序依旧可以成功提交, 但是最好还是加上输入判断

## C++知识点

在vector的指定位置插入指定元素, 下面的例子是在int型vector的开始处插入数字1

```c++
digits.insert(digits.begin(),1);
```

## python 代码知识点

### Python2和Python3中除法操作的不同

Python中除法有两种运算符：’/’和’//’

在Python 2.6中，’/’执行传统除法，如果操作数都是整数的话，执行截断的整数除法（即对于结果只保留整数部分），否则，执行浮点除法（保留余数）；’//’执行Floor除法，与Python3.0一样，对于整数执行截断除法，浮点数执行浮点除法。

在Python 3.0中，’/’总是执行真除法，不管操作数的类型，都会返回包含任何余数的浮点结果；’//’执行Floor除法，截除掉余数并且针对整数操作数返回一个整数，如果有任何一个操作数是浮点数，则返回一个浮点数。

补充：

Floor除法：效果等同于math模块中的floor函数：

math.floor(x) ：返回不大于x的整数

所以当运算数是负数时：结果会向下取整。

> 5//3#1.6666666666666667
> 1
> -5//3
> -2

**使代码中除法部分支持两个python版本**
尽管 / 的行为在python2.6和python3.0中不同，我们仍然能够在自己的代码中支持这两个版本，如果你的程序依赖于截断整数除法，在pyton2.6和python3.0中都使用//。如果你的程序对于整数需要有余数的浮点数结果，使用浮点数，从而确保代码在python2.6中运行的时候/的一个操作数是浮点数

参考: [Python2和Python3中除法操作/的不同](https://www.jianshu.com/p/ba132cb399a1), [python3之数字(在实际应用中的数字--除法：传统除法、Floor除法和真除法)](https://blog.csdn.net/fhd001/article/details/6969864)

### Python2和Python3中range()函数的不同

Python3 range() 函数返回的是一个可迭代对象（类型是对象），而不是列表类型， 所以打印的时候不会打印列表。它只是在迭代的情况下返回指定索引的值，但是它并不会在内存中真正产生一个列表对象，这样也是为了节约内存空间。

Python3 list() 函数是对象迭代器，可以把range()返回的可迭代对象转为一个列表，返回的变量类型为列表。

Python2 range() 函数返回的是列表。

xrange也是python2的内置函数，用于创造xrange对象用于迭代。 
在python3中，range()这种实现被移除了，保留了xrange()的实现，且将xrange()重新命名成range(), python3的range()在xrange()的基础上变的更强大了

参考: [Python3：range和xrange](https://blog.csdn.net/jasonLee_lijiaqi/article/details/78973204), [Python3 range() 函数用法](http://www.runoob.com/python3/python3-func-range.html)

### reversed()

reversed()是python内置函数, 返回序列seq的反向访问的迭代器(迭代器的意思是只能通过循环来输出）。参数可以是列表，元组，字符串，不改变原对象。

**python中sort，sorted，reverse,reversed的区**别

简单的说以上四个内置函数都是排序。

对于sort和reverse都是list列表的内置函数，一般不传参数，没有返回值，会改变原列表的值。

而sorted和reversed是python内置函数，需要传参数，参数可以是字符串，列表，字典，元组，不管传的参数是什么sorted返回的都是列表，reversed返回的都是迭代器，原参数的值不会发生改变。

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
```
