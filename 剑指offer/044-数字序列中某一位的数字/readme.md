# 044-数字序列中某一位的数字

tags： 找规律

---

## 题目原文

[AcWing链接](https://www.acwing.com/problem/content/description/52/)

数字以0123456789101112131415…的格式序列化到一个字符序列中。

在这个序列中，第5位（从0开始计数）是5，第13位是1，第19位是4，等等。

请写一个函数求任意位对应的数字。

## 解题思路

[参考](https://www.cnblogs.com/wangkundentisy/p/8963605.html)

《剑指offer》上提供了两种思路。

方法1：

第一种思路是：从0开始枚举每个数字。每枚举一个数字的时候，求出该数字是几位(如15是2位数、9323是4位数)，并把该数字的位数和前面所有数字的位数累加。如果位数之和仍然小于等于n，则继续枚举下一个数字。当累加的数位大于n时，那么第n位数字一定在这个数字里。(此处为什么是大于而不是大于等于？因为是从0开始计数的，实质应为第n+1位)该算法的时间复杂度为O(N)，当N很大时(如N = 10 ^ 11)往往会超时。

方法2；

这种方法是本文论述的重点，其实本提可以采用和文章http://www.cnblogs.com/wangkundentisy/p/8920147.html中的第二题的方法4类似。我们令f(m)表示"从0~长度为m的最大的数字"的数字个数之和，由此我们可以继续分析：

f(0) = 0

f(1) =10 + 0 = 10 (对应0 ~ 9)

f(2) =90 * 2 + f(1) = 190 (对应10 ~99, 0 ~ 9)

f(3) =900 * 3 + f(2) = 2890 (对应100 - 999,0 ~ 99)

f(4) = 9000 * 4 + f(3) =38890 (对应1000 ~ 9999,0 ~ 999)

....

f(m) = 9 * 10^(i - 1) * m + f(m-1)

其中m表示数字的长度。求出f(m)之后，剩下的就比较好解了。

对于数字n，我们只需要比较n与数组f中每个元素，如果f(k) >= n，其中k是满足前面条件的最小值，那么我们就可以确定最终的数字长度一定是k了。所以令n = n - f(k - 1),然后根据n / k和n % k的结果，就能知道最终的数字R和R中的哪个位置。

举个例子：

假设 n = 1001，由于f(2) < 1001且f(3) > 1001，所以最终的数字一定是3位数的数字。令n = n - f(2) = 811。有811 / 3 =270  ,811 % 3 = 1。所以最终的数字为100 + 270 = 370，且是370中的第1位数(从0开始计数)，所以最终的结果是7。

## 代码

### [c++代码](./src/cpp/044-数字序列中某一位的数字.cpp)

```c++
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
```

### [python代码](./src/python/044-数字序列中某一位的数字.py)

```python

```
