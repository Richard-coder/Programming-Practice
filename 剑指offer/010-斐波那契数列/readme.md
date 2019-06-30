#010-斐波那契数列

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

换种思路，先根据f(0)和f(1)计算出f(2),再依次计算出f(3)，f(4)，...，f(n),这种计算方法的空间复杂度是常数，时间复杂度是O(n)

### 代码
#### [c++代码](./src/cpp/010-斐波那契数列.cpp)

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

#### [python代码](./src/python/010-斐波那契数列.py)

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

### 时间复杂度为$\Theta(logn)$但不是很实用的解法
介绍解法之前先介绍下面的数学公式：

$$\begin{bmatrix}f(n)&f(n-1)\\f(n-1)&f(n-2) \end{bmatrix}=\begin{bmatrix}1&1\\1&0 \end{bmatrix}^{n-1}$$

这个公式可以用数学归纳法证明，有了这个公示后，原来的问题就变成了求矩阵$=\begin{bmatrix}1&1\\1&0 \end{bmatrix}^{n-1}$，若果只是简单的从0开始循环计算，n次方需要n次计算，时间复杂度仍为$\Theta(n)$，与前面的方法相同，但可以考虑**乘方的如下性质**

$$a^n=\begin{cases} a^{n/2}.a^{n/2} &\text{n为偶数} \\ a^{(n-1)/2}.a^{(n-1)/2}.a & \text{n为奇数} \end{cases}$$

但这种方法隐含的时间常数比较大（不是很懂）,很少会有软件采用这种算法，另外这种算法实现复杂，有多个递归基，不适合面试。


实现上面的方法时，需要定义一个2×2的矩阵，并且定义好矩阵的乘法以及乘方运算，比较麻烦，可以将递归公式转换一下形式：


原理：观察：f(n)=f(n-1)+f(n-2)=2f(n-2)+f(n-3)=3f(n-3)+2f(n-4)=5f(n-4)+3f(n-5)=...=f(k).f(n-k+1)+f(k-1).f(n-k)

若令n=2k,则有f(2k)=f(k).f(k+1)+f(k-1).f(k)=f(k).(f(k)+f(k-1))+f(k-1).f(k)=f(k)^2+2.f(k).f(k-1)

若令n=2*k-1,则有f(2k-1)=f(k) * f(k) + f(k - 1) * f(k - 1) = f(k) ^ 2 + f(k - 1) ^ 2

**这种方法一般不会出现在笔试中, 但是利用乘方的性质将O(n)的计算降为O(log n)这种思想比较重要**

### 拓展1 青蛙跳台阶

[牛客网链接](https://www.nowcoder.com/practice/8c82a5b80378478f9484d87d1c5f12a4?tpId=13&tqId=11161&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking&tPage=1)

题目描述： 一个台阶总共有n级，如果一次可以跳1级，也可以跳2级。求总共有多少总跳法，并分析算法的时间复杂度。

通过题目的描述，可以很清晰地看到，这就是一个Fibonacci数列。

注意与`010-斐波那契数列`不同, `010-斐波那契数列`中f(0)为0, 这道题f(0)=1; 斐波那契数列的标准公式是f(0)=0

**c++代码**

```
class Solution {
public:
    int jumpFloor(int number) {
        int f1=1,f2=1;
        int res;
        if(number==0) return f1;
        if(number==1) return f2;
        for(int i=2;i<=number;i++){
            res=f1+f2;
            f1=f2;
            f2=res;
        }
        return res;
    }
};
```

### 拓展2 变态跳台阶

[牛客网链接](https://www.nowcoder.com/practice/22243d016f6b47f2a6928b4313c85387?tpId=13&tqId=11162&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking&tPage=1)

 **题目描述**

一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。

#### 思路1

> [参考](https://www.nowcoder.com/questionTerminal/22243d016f6b47f2a6928b4313c85387)

  f(1) = 1

  f(2) = f(2-1) + f(2-2)         //f(2-2) 表示2阶一次跳2阶的次数。 

  f(3) = f(3-1) + f(3-2) + f(3-3)  

  ... 

  f(n) = f(n-1) + f(n-2) + f(n-3) + ... + f(n-(n-1)) + f(n-n)  

​    

  说明：  

  1）这里的f(n) 代表的是n个台阶有一次1,2,...n阶的 跳法数。 

  2）n = 1时，只有1种跳法，f(1) = 1 

  3) n = 2时，会有两个跳得方式，一次1阶或者2阶，这回归到了问题（1） ，f(2) = f(2-1) + f(2-2)  

  4) n = 3时，会有三种跳得方式，1阶、2阶、3阶， 

​        那么就是第一次跳出1阶后面剩下：f(3-1);第一次跳出2阶，剩下f(3-2)；第一次3阶，那么剩下f(3-3) 

​       因此结论是f(3) = f(3-1)+f(3-2)+f(3-3) 

  5) n = n时，会有n中跳的方式，1阶、2阶...n阶，得出结论： 

​       f(n) = f(n-1)+f(n-2)+...+f(n-(n-1)) + f(n-n) =>   f(0) + f(1) + f(2) + f(3) + ... + f(n-1) 

​        

  6) 由以上已经是一种结论，但是为了简单，我们可以继续简化： 

​       f(n-1) = f(0) + f(1)+f(2)+f(3) + ... + f((n-1)-1) =   f(0) + f(1) + f(2) + f(3) + ... + f(n-2) 

​       f(n) = f(0) + f(1) + f(2) + f(3) + ... + f(n-2) +   f(n-1) = f(n-1) + f(n-1) 

​       可以得出： 

​       f(n) = 2*f(n-1) 

​        

  7) 得出最终结论,在n阶台阶，一次有1、2、...n阶的跳的方式时，总得跳法为：

$$f(n)=\begin{cases} 1 &\text{n=0}\\1 & \text{n=1}\\
2*f(n-1) & \text{n>2}\end{cases}$$

**c++代码**

```
class Solution {
public:
    int jumpFloorII(int number) {
        int f1=1;
        if(number==1||number==0)
            return 1;
        for(int i=2;i<=number;i++)
            f1=2*f1;
        
        return f1;
    }
};
```

#### 思路2

> [参考](https://www.nowcoder.com/questionTerminal/22243d016f6b47f2a6928b4313c85387)

 每个台阶可以看作一块木板，让青蛙跳上去，n个台阶就有n块木板，最后一块木板是青蛙到达的位子， 必须存在，其他 (n-1) 块木板可以任意选择是否存在，则每个木板有存在和不存在两种选择，(n-1) 块木板 就有 [2^(n-1)] 种跳法，可以直接得到结果。

其实我们所要求的序列为：0,1,2,4,8,16,……
所以除了第一位外，其他位的数都是前一位的数去乘以2所得到的积

**c++代码**

```
class Solution {
public:
    int jumpFloorII(int number) {
        return  1<<--number;
    }
};
```



### 拓展3 铺瓷砖问题

[牛客网链接](https://www.nowcoder.com/practice/72a5a919508a4251859fb2cfb987a0e6?tpId=13&tqId=11163&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking&tPage=1)

我们可以用2x1的小矩形横着或者竖着取覆盖更大的矩阵，请问用8个2x1的小矩形取无重叠地覆盖一个2x8的大矩形，总共有多少种方法？

![斐波那契数列拓展2][1]
<center><small> 斐波那契数列拓展2</small></center>
记2x8的覆盖方法记为f(8)，用第一个1x2的小矩形取覆大矩形的的最左边时有两个选择，竖着放或者横着放，竖着放的时候，覆盖方法为f(7)，横着放的时候，比如在左上角，则左下角也只能在横着放一个小矩形，因此，横着放的时候覆盖方法为f(6)，因此f(8)=f(7)+f(6)，可以看出这仍然是斐波那契数列。

**c++代码**

**注意**

```
class Solution {
public:
    int rectCover(int number) {
        if(number<=0)
            return number;
        if(number==1) return 1;
        if(number==2) return 2;
        int f1=1,f2=2;
        int res;
        for(int i=3;i<=number;i++){
            res=f1+f2;
            f1=f2;
            f2=res;
        }
        return res;
    }
};
```




[1]:./img/斐波那契数列拓展2.png