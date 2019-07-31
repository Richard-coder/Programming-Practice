# 030-包含min函数的栈

tags： 栈

---

## 题目原文

[牛客网链接](https://www.nowcoder.com/practice/4c776177d2c04c2494f2555c9fcc1e49?tpId=13&tqId=11173&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的min函数。在该栈中，调用min、push及pop的时间复杂度都是O(*1*)。

## 解题思路

[参考](https://blog.csdn.net/u013132035/article/details/80603691)

要使时间复杂度是O（1），需要每次压入一个新元素进栈时，将栈里的所有元素排序，让最小的元素位于栈顶。但是这种想法不能保证最后压入栈的元素能够最先出栈，因为这个数据结构已经不是栈了。

于是借助于一个辅助的成员变量来存放最小的元素。每次压入一个新元素进栈的时候，如果该元素比当前最小的元素还要小，则更新最小元素，但是如果当前做小的元素被弹出栈了，怎么得到下一个最小元素是一个问题。分析到这里我们发现仅仅添加一个成员变量存放最小元素是不够的，也就是说当最小元素被弹出栈的时候，我们希望能够得到次小的元素。因此在压入最小元素之前，我们要把次小元素保存起来。故可以借助一个辅助栈把每次的最小元素都保存起来。

例子佐证：

![img](img/readme.assets/20180607090555318)

## 代码

### [c++代码](./src/cpp/030-包含min函数的栈.cpp)

```c++
class Solution {
public:
    void push(int value) {
        m_data.push(value);
        if(m_min.empty()||value<m_min.top())
            m_min.push(value);
        else
            m_min.push(m_min.top());
    }
    void pop() {
        //assert(m_data.size()!=0&&m_min.size()!=0);
        m_data.pop();
        m_min.pop();
    }
    int top() {
        //assert(m_data.size()!=0&&m_min.size()!=0);
        return m_data.top();
    }
    int min() {
        //assert(m_data.size()!=0&&m_min.size()!=0);
        return m_min.top();
    }
    stack<int> m_data;
    stack<int> m_min;
    
};
```

### [python代码](./src/python/030-包含min函数的栈.py)

```python

```
