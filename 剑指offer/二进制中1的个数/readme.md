#递归 二进制中1的个数

tags： 递归

---

## 题目原文
大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。
n<=39

## 解题思路
### 低效率不实用的方法
斐波那契数列的求解方法最容易些想到的就是如下的递归形式
```c++
long long Fibonacci(unsigned int n){
    if (n<=0)
        return 0;
    
    if (n==1)
        return 1;

    return Fibonacci(n-1)+Fibonacci(n-2)
}
```
上面的递归形式看起来很简单，但效率却很低，因为在递归的过程中存在着大量的重复计算。例如，计算f(10)的时候需要计算f(8)和f(9)，在计算f(9)的时候又要计算一遍f(8),因此，计算的时间复杂度会随着n的增大而指数级增大。

### 改进方法

上面的方法问题在于递归的过程存在大量的重复计算，因此可以考虑在计算的过程中把计算结果保存下来，比如建立一个数组保存中间计算结果，但这也不是好的方法，因为耗费了额外的内存空间。

换种思路，先根据f(0)和f(1)计算出f(2),再依次计算出f(3)，f(4)，...，f(n),这种计算方法的空间复杂度是常数，时间复杂度是$\Theta(n)$


### 时间复杂度为$\Theta(logn)$但不是很实用的解法
介绍解法之前先介绍下面的数学公式：

$$\begin{bmatrix}f(n)&f(n-1)\\f(n-1)&f(n-2) \end{bmatrix}=\begin{bmatrix}1&1\\1&0 \end{bmatrix}^{n-1}$$

这个公式可以用数学归纳法证明，有了这个公示后，原来的问题就变成了求矩阵$=\begin{bmatrix}1&1\\1&0 \end{bmatrix}^{n-1}$，若果只是简单的从0开始循环计算，n次方需要n次计算，时间复杂度仍为$\Theta(n)$，与前面的方法相同，但可以考虑乘方的如下性质

$$a^n=\begin{cases} a^{n/2}.a^{n/2} &\text{n为偶数} \\ a^{(n-1)/2}.a^{(n-1)/2}.a & \text{n为奇数} \end{cases}$$

但这种方法隐含的时间常数比较大（不是很懂）,很少会有软件采用这种算法，另外这种算法实现复杂，有多个递归基，不适合面试。

### 拓展 青蛙跳台阶
题目描述： 一个台阶总共有n级，如果一次可以跳1级，也可以跳2级。求总共有多少总跳法，并分析算法的时间复杂度。

通过题目的描述，可以很清晰地看到，这就是一个Fibonacci数列。

题目描述： 一个台阶总共有n级，如果一次可以跳1级，也可以跳2级……也可以跳n级。求总共有多少总跳法，并分析算法的时间复杂度。

用f(n)表示青蛙上n级台阶的跳法数，设f(0)=1（f(0)的值代表从起点直接到达终点），所以有

f(1)=1

f(2)=f(1)+f(0)

...

f(n)=f(n-1)+f(n-2)+...+f(n-n)&nbsp; &nbsp; &nbsp; (a)

f(n-1)=f(n-2)+f(n-3)+...+f(n-n)&nbsp; &nbsp; &nbsp; (b)

(a)减去(b)整理之后得到$f(n)=2f(n-1)$

所以有递归公式如下：

$$f(n)=\begin{cases} 1 &\text{n=0}\\1 & \text{n=1}\\
2*f(n-1) & \text{n>2}\end{cases}$$

### 拓展2 铺瓷砖问题
我们可以用2x1的小矩形横着或者竖着取覆盖更大的矩阵，请问用8个2x1的小矩形取无重叠地覆盖一个2x8的大矩形，总共有多少种方法？

![斐波那契数列拓展2][1]
<center><small> 斐波那契数列拓展2</small></center>

记2x8的覆盖方法记为f(8)，用第一个1x2的小矩形取覆大矩形的的最左边时有两个选择，竖着放或者横着放，竖着放的时候，覆盖方法为f(7)，横着放的时候，比如在左上角，则左下角也只能在横着放一个小矩形，因此，横着放的时候覆盖方法为f(6)，因此f(8)=f(7)+f(6)，可以看出这仍然是斐波那契数列。



## 代码
### [c++代码](./src/cpp/二进制中1的个数.cpp)

```c++
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
```

### [python代码](./src/python/二进制中1的个数.py)

```python

# -*- coding:utf-8 -*-
class Solution:
    def Fibonacci(self, n):
        tempArray = [0, 1]
        if n >= 2:
            for i in range(2, n+1):
                tempArray[i%2] = tempArray[0] + tempArray[1]
        return tempArray[n%2]
```

[1]:./img/斐波那契数列拓展2.png