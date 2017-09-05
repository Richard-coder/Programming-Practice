# 数组 二维数组中的查找

tags： 查找

---

## 题目原文
在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

## 解题思路
从数组中选取数字，和目标数字的关系有三种情况：=，<或>。

对于数组中的任何一个元素, 比它小的元素都在它的左方或者上方, 比它大的元素都在它的右边或者下方

如果随意选择数组中的一个数字进行查找，会出现查找区域重叠的情况

![重叠区域示意图][1]
<center><small> 重叠区域示意图</small></center>

为了不重复的处理重叠的数据, 我们可以找几个特殊的起点，经过简单分析可以得到，可以从左下角或者右上角开始

比如我们从右上角的数据开始出发

 + 比他小的数必定在它的左侧，就往左找
 + 比他大的数必定在它的下侧，就往下找

## 代码
### [c++代码](./src/cpp/二维数组中的查找.cpp)

```c++
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        bool find=false;
        for(int row=0,col=array[row].size()-1;row < array.size()&&col>=0;){
                if (target==array[row][col])
                    return find=true;
                else if(array[row][col]>target)
                    col--;
                else
                    row++;
        }
        return find;
    }
};
```

### [python代码](./src/python/二维数组中的查找.py)
```python

```

[1]:./img/重叠区域示意图.png