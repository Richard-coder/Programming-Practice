# 网易 合唱团

tags： 动态规划

---

## 题目原文
题目描述
有 n 个学生站成一排，每个学生有一个能力值，牛牛想从这 n 个学生中按照顺序选取 k 名学生，要求相邻两个学生的位置编号的差不超过 d，使得这 k 个学生的能力值的乘积最大，你能返回最大的乘积吗？

输入描述:

每个输入包含 1 个测试用例。每个测试数据的第一行包含一个整数 n (1 <= n <= 50)，表示学生的个数，接下来的一行，包含 n 个整数，按顺序表示每个学生的能力值 ai（-50 <= ai <= 50）。接下来的一行包含两个整数，k 和 d (1 <= k <= 10, 1 <= d <= 50)。

输出描述:

输出一行表示最大的乘积。

示例1

输入

    3

    7 4 7

    2 50

输出

    49
## 题目大意
有 n 个学生站成一排，每个学生有一个能力值，牛牛想从这 n 个学生中按照顺序选取 k 名学生，要求相邻两个学生的位置编号的差不超过 d，使得这 k 个学生的能力值的乘积最大，你能返回最大的乘积吗？


## 解题思路
### 题目分析
题目要求n各学生中选择k个，使这k个学生的能力值乘积最大。这是一个最优化的问题。另外，在优化过程中，提出了相邻两个学生的位置编号差不超过d的约束。

如果不用递归或者动态规划，问题很难手，并且，限制条件d也需要对每一个进行束，编程十分复杂

所以，解决的方法是采用动态规划（理由：1.求解的是最优化问题；2.可以分解为最优子结构）

### 问题分解
1.对该问题的分解是关键。

	从n个学生中，选择k个，可以看成是：先从n个学生里选择最后1个，然后在剩下的里选择k-1个，并且让这1个和前k-1个满足约束条件
2.数学描述

	为了能够编程实现，需要归纳出其递推公式，而在写递推公式之前，首先又需要对其进行数学描述

记第k个人的位置为one,则可以用f[one][k]表示从n个人中选择k个的方案。然后，它的子问题，需要从one前面的left个人里面，选择k-1个，这里left表示k-1个人中最后一个（即第k-1个）人的位置，因此，子问题可以表示成f[left][k-1].

这里需要注意的是一定要对fm和fn的值进行初始化为0，否则每次第一次进入到第三个循环时，fm[k][i]的值都是随机的，得不到正确答案。


## 代码
### [c++代码](./src/cpp/合唱团.cpp)

```c++
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <climits>
using namespace std;

int main(){
    int n,temp;
    cin>>n;
    vector<int> arr;
    arr.resize(n);
    
    for(int i=0;i<n;i++){
        cin>>temp;
        arr[i]=temp;
    }
    
    int K,D;
    cin>>K>>D;
    
    long long int res=LLONG_MIN;
    long long int fm[10][50]={0},fn[10][50]={0};
    
    for (int i=0;i<n;i++){
        fm[0][i]=arr[i];
        fn[0][i]=arr[i];
    }
    
    
    for (int i=0;i<n;i++){
        for(int k=1;k<K;k++){
            for(int j=i-1;j>=0 && i-j<=D;--j){
                fm[k][i]=max(fm[k][i],max(fm[k-1][j]*arr[i],fn[k-1][j]*arr[i]));
                fn[k][i]=min(fn[k][i],min(fm[k-1][j]*arr[i],fn[k-1][j]*arr[i]));
            }
        }
        res=max(res,fm[K-1][i]);
    }
    cout<<res;
    return 0;
}
```

### [python代码](./src/python/合唱团.py)
```python
#-*- coding:utf-8 -*-
n = int(raw_input())
arr = map(int,raw_input().split())
K,D = map(int,raw_input().split())
 
fm = [ ([0]*n) for i in range(K) ] # k*d
fn = [ ([0]*n) for i in range(K) ] # k*d
res=0
#fm,fn表示 能力值的最大值和最小值，因为有正有负
#fm[k][i]表示从n个人中选取k+1个人时最大的能力值，i表示第k个人的位置
for i in range(n):
    fm[0][i]=arr[i]
    fn[0][i]=arr[i]
    
for i in range(n):
    for k in range(1,K):
        for j in range(i-1,max(0,i-D)-1,-1):
            #之所以要max(fm[k][i],是要取本组循环中最大/小的值
                fm[k][i] = max(fm[k][i],max(fm[k-1][j]*arr[i], fn[k-1][j]*arr[i]))
                fn[k][i] = min(fn[k][i],min(fm[k-1][j]*arr[i], fn[k-1][j]*arr[i]))
    res=max(res,fm[K-1][i])
print res
```
