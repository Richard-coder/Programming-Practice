# 046-把数字翻译成字符串

tags： 递归

---

## 题目原文

[acwing](https://www.acwing.com/problem/content/55/)

给定一个数字，我们按照如下规则把它翻译为字符串：

0翻译成”a”，1翻译成”b”，……，11翻译成”l”，……，25翻译成”z”。

一个数字可能有多个翻译。例如12258有5种不同的翻译，它们分别是”bccfi”、”bwfi”、”bczi”、”mcfi”和”mzi”。

请编程实现一个函数用来计算一个数字有多少种不同的翻译方法。

## 解题思路

[参考](https://www.jianshu.com/p/80e1841909b7)

下面我们从自上而下和自下而上两种角度分析这道题目，以12258为例：

自上而下，从最大的问题开始，递归 ：
12258
/       \
b+2258       m+258
/   \         /   \
bc+258 bw+58  mc+58  mz+8
/  \      \        \     \
bcc+58 bcz+8   bwf+8   mcf+8  mzi
/        \       \     \
bccf+8        bczi    bwfi   mcfi
/
bccfi
有很多子问题被多次计算，比如258被翻译成几种这个子问题就被计算了两次。
自下而上，动态规划，从最小的问题开始 ：
f(r)表示以r为开始（r最小取n-2）到最右端所组成的数字能够翻译成字符串的种数。对于长度为n的数字，f(n)=0,f(n-1)=1,求f(0)。
递推公式为 f(r) = f(r+1)+g(r,r+11)*f(r+2)；
其中，如果r，r+1能够翻译成字符，则g(r,r+11)，否则为0。

```c++
class Solution {
public:
    int getTranslationCount(string s) {
        int n = s.size();
        if(!n) return 0;
        if(n==1) return 1;

        vector<int> dp(n+1, 1);
        dp[n-1] = 1;
        for(int i=n-2;i>=0;i--){
            dp[i] = dp[i+1];
            if(s[i]=='1' || (s[i]=='2' && s[i+1]<'6')){
                dp[i] += dp[i+2];
            }
        }
        return dp[0];
    }
};
```

优化到O(1)空间复杂度

```c++
class Solution {
public:
    int getTranslationCount(string s) {
        int n=s.size();
        if(n<=0)
            return 0;
       int res=1,f1=1,f2=1;
        for(int i=n-2;i>=0;i--){
            res = f1;
            if(s[i]=='1' || (s[i]=='2' && s[i+1]<'6')){
                 res+=f2;
            }
            
            f2=f1;
            f1=res;
        
        }
        return res;
    }
};


```



## 代码

### [c++代码](./src/cpp/046-把数字翻译成字符串.cpp)

```c++
class Solution {
public:
    int getTranslationCount(string s) {
        int n = s.size();
        if(!n) return 0;
        if(n==1) return 1;

        vector<int> dp(n+1, 1);
        dp[n-1] = 1;
        for(int i=n-2;i>=0;i--){
            dp[i] = dp[i+1];
            if(s[i]=='1' || (s[i]=='2' && s[i+1]<'6')){
                dp[i] += dp[i+2];
            }
        }
        return dp[0];
    }
};
```

### [python代码](./src/python/046-把数字翻译成字符串.py)

```python

```
