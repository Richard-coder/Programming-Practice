# 031-栈的压入弹出序列

tags： 栈

---

## 题目原文

[牛客网链接]()

> 输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。

假设压入栈的所有数字均不相等。

例如序列1,2,3,4,5是某栈的压入顺序，

序列4，5,3,2,1是该压栈序列对应的一个弹出序列，

但4,3,5,1,2就不可能是该压栈序列的弹出序列。

## 解题思路

[参考](https://blog.csdn.net/u013132035/article/details/80604096)

首先借助一个辅助栈，把输入的第一个序列中的数字依次压入该辅助栈，并按照第二个序列的顺序依次从该栈中弹出数字。

以4、 5、 3、 2 、1为例分析：

![img](img/readme.assets/20180607092412743)

再以4、 5、 3、 2 、1为例分析：

![img](img/readme.assets/20180607092727969)

从上面的两个例子可以找到判断一个序列是不是栈的弹出序列的规律：如果下一个弹出的数字刚好是栈顶数字，那么直接弹出。如果下一个弹出的数字不在栈顶，我们把压栈序列中还没有入栈的数字压入辅助栈，直到把下一个需要弹出的数字压入栈顶为止。如果所有的数字都压入栈了仍然没有找到下一个弹出的数字，那么该序列就不可能是一个弹出序列。

## 代码

### [c++代码](./src/cpp/031-栈的压入弹出序列.cpp)

```c++
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.empty()||popV.empty()||pushV.size()!=popV.size())
            return false;
        stack<int> data;
        bool res=false;
        int idx1=0,idx2=0;
        int length=popV.size();
        while(idx2<length){//这里不需要判断idx1, 如果非要写, 应该是idx1<=length
            while((data.empty()||data.top()!=popV[idx2])&&idx1<length){
                data.push(pushV[idx1]);
                idx1++;
            }
            if(data.top()==popV[idx2]){//这里不需要判断idx1, 如果非要写, 应该是idx1<=length
                data.pop();
                idx2++;
            }else
                break;
            
        }
        if(idx1==length&&idx2==length&&data.empty())
            return true;
        return false;
    }
};
```

### [python代码](./src/python/031-栈的压入弹出序列.py)

```python

```
