# 004-二维数组中的查找

tags： 查找

---

## 题目原文

[牛客网链接](https://github.com/gatieme/CodingInterviews)

在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

## 解题思路

从数组中选取数字，和目标数字的关系有三种情况：=，<或>。

对于数组中的任何一个元素, 比它小的元素都在它的左方或者上方, 比它大的元素都在它的右边或者下方

这道题我最开始的想法是当作一个二维版本的二分查找来做的,每次都与矩阵中间的数字作比较, 根据比较结果剔除一些候选区域. 但发现使用这种方式进行查找, 会有重叠的查找区域, 比如下图的深色阴影部分. 

![重叠区域示意图][1]
<center><small> 重叠区域示意图</small></center>
所以可以考虑选取特殊位置的点进行比较, 比如右上角和左下角的点. 这两个位置的点的特点是, 所在行的最大值, 同时也是所在列的最小值(以右上角的点为例), 所以每次可以根据比较结果删除查找范围的一列或者一行, 而左上角和右下角的点则不可以, 因为这两个位置的点, 即是所在列的最小值, 又是所在行的最小值(以左上角的点为例), 不能根据比较结果删除查找范围的某一行或者某一列.

为了不重复的处理重叠的数据, 我们可以找几个特殊的起点，经过简单分析可以得到，可以从左下角或者右上角开始

比如我们从右上角的数据开始出发

 + 比他小的数必定在它的左侧，就往左找
 + 比他大的数必定在它的下侧，就往下找

## 注意

书里给的代码中输入array是二维数组, 而在牛客网上是vector<vector<int> >, 所以矩阵每行每列的长度不一定相等, 因此在判断边界条件时, 一定要用对应的行或列的长度

## 代码

### [c++代码](./src/cpp/004-二维数组中的查找.cpp)

```c++
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if(array.empty()) return false;
        for(int i=0,j=array[i].size()-1;i<array.size()&&j>=0;){
            if(array[i][j]==target)
                return true;
            else if(array[i][j]>target)
                j--;
            else
                i++;
        }
        return false;
    }
};
```

### [python代码](./src/python/004-二维数组中的查找.py)

```python
# -*- coding:utf-8 -*-
class Solution:
    # array 二维列表
    def Find(self, target, array):
        # write code here
        isFind='false';
        row=0
        col=len(array[0])-1
        while (row<len(array))and(col>=0):
            if target==array[row][col]:
                isfind='true'
                return isfind
            elif array[row][col]>target:
                col=col-1
            else :
                row=row+1
        return isFind

while True:
    try:
        number=input()
        a=number[0]
        b=number[1]
        f=Solution()
        print f.Find(a,b)
    except:
        break
```

[1]:./img/重叠区域示意图.png

