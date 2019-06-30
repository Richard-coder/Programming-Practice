# 链表 从尾到头打印链表

tags： 链表

---

## 题目原文
[牛客网链接](https://www.nowcoder.com/practice/d0267f7f55b3412ba93bd35cfa8e8035?tpId=13&tqId=11156&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking&tPage=1)

输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。

## 解题思路
从头到尾遍历链表，将链表的值依次放入栈中，遍历完成后再依次从栈顶输出每个节点

因为递归的本质在于栈就够，因此也可以用递归完成本题。访问一个节点时，先递归输出其子节点，再输出其自身. 但是递归的方法在链表比较长的时候, 函数的调用层级会很深, 从而有可能导致函数调用栈溢出.显然用栈基于循环的方法鲁棒性高一些.

## 代码

### [c++代码](./src/cpp/006-从尾到头打印链表.cpp)

```c++
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    //使用栈结构的方法
    vector<int> printListFromTailToHead(ListNode* head) {
        stack<ListNode*> nodes;//由于链表结构简单，用一个辅助变量即可，可以不用栈
        
        ListNode *pNode=head;
        while(pNode!=NULL){
            nodes.push(pNode);
            pNode=pNode->next;
        }
        //为了效率使用静态vector，使用静态vector后不能使用push_back
        vector<int> res(nodes.size());
        int i=0;
        while(!nodes.empty()){
            pNode=nodes.top();
            res[i++]=pNode->val;
            nodes.pop();
        }
        return res;
    }
    //使用递归的方法
    vector<int> res;
    vector<int> printListFromTailToHead2(ListNode* head){
        if(head!=NULL){
            printListFromTailToHead2(head->next);
            res.push_back(head->val);
        }
        return res;
    }
};
```

### [python代码](./src/python/006-从尾到头打印链表.py)

```python
# -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # 返回从尾部到头部的列表值序列，例如[1,2,3]
    def printListFromTailToHead2(self, listNode):
        # write code here
        if not listNode:
            return []
        res=[]
        head=listNode
        while head:
            res.insert(0,head.val)
            head=head.next
        return res
    def printListFromTailToHead(self, listNode,res=None):
        if res==None:
            res=[]
        if not listNode:
            return []
        else:
            self.printListFromTailToHead(listNode.next,res)
            res.append(listNode.val)
        return res
```

## c++ 知识点

### C++标准库之stack（各函数及其使用全）

> [参考](https://www.cnblogs.com/shrimp-can/p/5283207.html)

使用栈，要先包含头文件 ： #include<stack>

定义栈，以如下形式实现： stack<Type> s; 其中Type为数据类型（如 int，float,char等）。

栈的主要操作：

```
s.push(item);		//将item压入栈顶
s.pop();			//删除栈顶的元素，但不会返回
s.top();			//返回栈顶的元素，但不会删除
s.size();			//返回栈中元素的个数
s.empty();			//检查栈是否为空，如果为空返回true，否则返回false
```

栈是后入先出的。成员函数有：

1.**栈的声明**

```
std::deque<int> mydeque (3,100);          // deque with 3 elements
std::vector<int> myvector (2,200);        // vector with 2 elements
std::stack<int> first;                    // empty stackstd::stack<int> second (mydeque);         // stack initialized to copy of deque
std::stack<int,std::vector<int> > third;  // empty stack using vector
std::stack<int,std::vector<int> > fourth (myvector);
std::cout << "size of first: " << first.size() << '\n';
std::cout << "size of second: " << second.size() << '\n';
std::cout << "size of third: " << third.size() << '\n';
std::cout << "size of fourth: " << fourth.size() << '\n';结果为：0  3  0  2
```

2.bool **empty()** const

判断栈是否为空

stack<int> c; c.empty()

3.size_type **size()** const

返回栈中元素数量

c.size();

4.value_type& **top()**;

   const value_type &top() const;

返回栈顶元素

c.top();

5.void **push(**const value_type& val)

在栈顶插入一个元素

c.push(value)；

6.void **emplace**(args&& args);

在栈顶增加一个元素

c.emplace(value)

7.void **pop()**

出栈，即删除栈顶元素

c.pop();

8.void **swap** (stack& x);

交换两个栈中的内容

c.swap(d);

9.与vector一样，重载了运算符：==   !=   <   <=   >   >=

1. (1)==用于比较两个栈是否相等，首先判断大小是否相等，然后再通过operator ==判断元素之间是否相等，将会在第一个不相等的地方停止
2. (2)!= 和==是相反的。只要大小不同或者有一个元素不一样就是不相等的 
3. (3),< ,从第一元素开始比较当发现大于或者等于时停止，如果一个栈是另一个栈的前缀，那么长的栈大。下同

**易混淆知识点**

**push() 和 emplace() (C++11)**

> push()函数和emplace()都是在栈这个容器的顶部插入一个新的元素。
> push()，实际上是调用的底层容器的push_back()函数，新元素的值是push函数参数的一个拷贝。
> emplace()，实际上是调用的底层容器的emplace_back()函数，新元素的值是在容器内部就地构造的，不需要移动或者拷贝。
> stack的emplace也可以用在普通的基本类型上。

```cpp

struct Node
{
    Node(int x)
        :x(x){}
    int x;
};
 
int main()
{
    stack<Node>s1;
    s1.emplace(1);
    s1.push(Node(2));
 
    stack<int>s2;
    s2.emplace(1);   //OK
    return 0;
}
```

**栈没有clear或者erase函数，如果想要清空一个栈，需要循环的调用出栈函数。**