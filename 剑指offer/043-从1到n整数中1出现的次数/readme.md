# 043-从1到n整数中1出现的次数

tags： 递归

---

## 题目原文

[牛客网链接](https://www.nowcoder.com/practice/bd7f978302044eee894445e244c7eee6?tpId=13&tqId=11184&tPage=2&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,但是对于后面问题他就没辙了。ACMer希望你们帮帮他,并把问题更加普遍化,可以很快的求出任意非负整数区间中1出现的次数（从1 到 n 中1出现的次数）。

## 解题思路

### 暴力方法

最简单直接的方法就是我们循环所有的1~n中的每个number，计算每个number出现的次数

```c++
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        if(n<=0)
            return 0;
        int times=0;
        for(int i=1;i<=n;i++){
            times+=NumberOf1(i);
        }
        return times;
    }
    int NumberOf1(int num){
        int times=0;
        while(num!=0){
            if(num%10==1)
                times++;
            num=num/10;
        }
        return times;
    }
};
```



### 方法一 剑指offer的递归版本

链接：https://www.nowcoder.com/questionTerminal/bd7f978302044eee894445e244c7eee6来源：牛客网

  以21345为例分析。把从1到21345的所有数字分为两段，一段是从1到1345，另一段是从1346到21345。 

   先看从1346到21345中1出现的次数。1的出现分为两种情况。首先分析1出现在最高位的情况。从1346到21345的数字中，1出现在10000~19999这10000个数字的万位中，一共出现了10000个。 

   但是并不是对所有5位数而言在万位出现的次数都是10000个，比如12345，1只出现在10000~12345的万位，出现的次数是2346次，也就是除去最高位数字之后剩下的数字再加上1。 

  接下来分析1出现在除最高位之外的其他四位数中的情况，也就是例子中1346~21345这20000个数字中后4位中1出现的次数。书中说2000次，我认为书中此处有误。由于最高位是2，可以再把1346~21345分成两段：1346~11345和11346~21345。每一段剩下的4位数字中，选择其中一位是1，总共有C4      1种情况，其余3位可以在0-9这10个数字中任意选择，也就是4*10^3=4000次。也许有人会说：这样会有重复的情况出现啊？对，如果重复一次是存在两个1，重复两次是存在三个1，重复三次是存在4个1，也就是重复的次数就是四位数中1多于一个的个数，这正是我们想要的。那么总共出现的次数是2*4000=8000次。 

  至于从1到1345中1出现的次数，可以按照上面的方法求得。以此类推，就得出总共1的个数。代码如下：

```c++
public class Solution {
    public int NumberOf1Between1AndN_Solution(int n) {
        if (n <= 0) {
            return 0;
        }
        int tenPow; // 10的倍数，用于分离高位和低位
        int pow; // 10的倍数的位数
        int hi; // 高1位
        int lo; // 低位
        int count = 0; // 总数
        for (tenPow = 1, pow = 0; tenPow * 10 <= n; tenPow *= 10, pow++); // 求出最高位的位数和对应的10的倍数
        while (tenPow > 0) {
            hi = (n / tenPow) % 10; // 取高1位
            lo = n % tenPow; // 取低位
            if (hi > 1) {
                count += tenPow; // 高1位大于1时有该位对应的10的倍数个1出现
            } else if (hi == 1) {
                count += lo + 1; // 高1位等于1时有低位的数+1个1出现
            }
            count += tenPow / 10 * hi * pow; // 低位的数有多少个1出现
            tenPow /= 10;
            pow--;
        }
        return count;
    }
}
```



### 方法二 代码简洁但不好理解

[参考](https://www.nowcoder.com/questionTerminal/bd7f978302044eee894445e244c7eee6)

主要思路：设定整数点（如1、10、100等等）作为位置点i（对应n的各位、十位、百位等等），分别对每个数位上有多少包含1的点进行分析

根据设定的整数位置，对n进行分割，分为两部分，高位n/i，低位n%i 

当i表示百位，且百位对应的数>=2,如n=31456,i=100，则a=314,b=56，此时百位为1的次数有a/10+1=32（最高两位0~31），每一次都包含100个连续的点，即共有(a%10+1)*100个点的百位为1 

当i表示百位，且百位对应的数为1，如n=31156,i=100，则a=311,b=56，此时百位对应的就是1，则共有a%10(最高两位0-30)次是包含100个连续点，当最高两位为31（即a=311），本次只对应局部点00~56，共b+1次，所有点加起来共有（a%10*100）+(b+1)，这些点百位对应为1 

当i表示百位，且百位对应的数为0,如n=31056,i=100，则a=310,b=56，此时百位为1的次数有a/10=31（最高两位0~30） 

综合以上三种情况，当百位对应0或>=2时，有(a+8)/10次包含所有100个点，还有当百位为1(a%10==1)，需要增加局部点b+1 

之所以补8，是因为当百位为0，则a/10==(a+8)/10，当百位>=2，补8会产生进位位，效果等同于(a/10+1)

```c++
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
    int ones = 0;
     //m表示当前分析的是哪一个数位
    for (long long m = 1; m <= n; m *= 10) {
        int a = n/m, b = n%m;
        ones += (a + 8) / 10 * m + (a % 10 == 1) * (b + 1);
    }
    return ones;
    }

};
```



## 代码

### [c++代码](./src/cpp/043-从1到n整数中1出现的次数.cpp)

```c++
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
    int ones = 0;
     //m表示当前分析的是哪一个数位
    for (long long m = 1; m <= n; m *= 10) {
        int a = n/m, b = n%m;
        ones += (a + 8) / 10 * m + (a % 10 == 1) * (b + 1);
    }
    return ones;
    }

};
```

### [python代码](./src/python/043-从1到n整数中1出现的次数.py)

```python

```
