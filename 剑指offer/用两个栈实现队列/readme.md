# 栈和队列 用两个栈实现队列

tags： 栈 队列

---

## 题目原文
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。

## 解题思路

这道题的思想是用两个“先进后出”的栈模拟一个“先进先出”的队列

解题思路就是栈1负责压入，栈2负责弹出。弹出时，若栈2非空，则直接从栈2的栈顶弹出元素即可；否则，将栈1的元素弹出后压入栈2，然后再弹出栈2的栈顶元素即可。

下图是一个模拟的过程。

 + 1 a,b,c先依次压入栈1。a位于栈底，c位于栈顶，栈2为空。
 + 2 弹出a。先将c,b从栈1弹出后压入栈2，然后从栈1中弹出a即可。此时栈2中，b位于栈顶，c位于栈底。若此时按顺序弹出b,c,即为从队列中弹出b,c的顺序。
 + 3 弹出b。从栈2中弹出b即可
 + 4 压入d。把d压入栈1即可
 + 5 弹出c。把c从栈2中弹出即可

![用两个栈模拟一个队列的操作][1]
<center><small> 用两个栈模拟一个队列的操作</small></center>

### 拓展 两个队列模拟一个栈

用两个队列实现栈,进栈出栈后，一定有一个队列空的，进栈直接压入非空队列，出栈是将除最后一个元素都压入空队列，然后弹出原非空栈的最后一个元素即可

![用两个队列模拟一个栈的操作][2]
<center><small> 用两个队列模拟一个栈的操作</small></center>
## 代码
### [c++代码](./src/cpp/用两个栈实现队列.cpp)

```c++
//两个栈实现队列，一个负责push，一个负责pop就好了
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        int node;
        if (stack1.empty()&&stack2.empty())
            return -1;
        else{
            if (stack2.empty()){
                while(!stack1.empty()){
                    stack2.push(stack1.top());
                    stack1.pop();
                }
            }
            
            node=stack2.top();
            stack2.pop();
            return node;
        }
    }
private:
    stack<int> stack1;
    stack<int> stack2;
};

//用两个队列实现栈,进栈出栈后，一定有一个队列空的，进栈直接压入非空队列，出栈是将除最后一个元素都压入空队列，然后弹出原非空栈的最后一个元素即可
class Solution
{
public:
    void push(int node) {
        if （!queue1.empty()）{
            queue1.push(node);
        }else{
            queue2.push(node);
        }
    }

    int pop() {
        if (queue1.empty()&&queue1.empty())
            return -1;
        else{
            if （!queue1.empty()）{
                while （!queue1.empty()）{
                    if (queue1.size()==1)
                         return queue1.top();
                    queue2.push(queue1.top());
                    queue1.pop();
                }else{
                    while （!queue2.empty()）{
                        if (queue2.size()==1)
                            return queue2.top();
                        queue1.push(queue2.top());
                        queue2.pop();
                    }
                }
            }
        }
    }
private:
    queue<int> queue1;
    queue<int> queue2;
};
```

### [python代码](./src/python/用两个栈实现队列.py)


```python
# -*- coding:utf-8 -*-
#list方法如果只用append()和pop()就相当于栈了
class Solution:
    def __init__(self):
        self.stack1=[]
        self.stack2=[]
    def push(self, node):
        # write code here
        self.stack1.append(node)
    def pop(self):
        # return xx
        if len(self.stack1)==0 and len(self.stack2)==0:
            return
        elif len(self.stack2)==0:
            while len(self.stack1)!=0:
                self.stack2.append(self.stack1.pop())
        return self.stack2.pop()

#拓展，用两个队列实现栈

# -*- coding:utf-8 -*-
#list方法如果只用append()和pop(0)就相当于队列了
# -*- coding:utf-8 -*-
class Solution:
    def __init__(self):
        self.queue1=[]
        self.queue2=[]
    def push(self, node):
        # write code here
        if self.queue1!=[]:
            self.queue2.append(node)
        else:
            self.queue1.append(node)
    def pop(self):
        # return xx
        if len(self.queue1)==0 and len(self.queue2)==0:
            return
        elif self.queue1!=[]:
            length =len(self.queue1)
            for i in range(length-1):
                self.queue2.append(self.queue1.pop(0))
            return self.queue1.pop()
        else:
            length =len(self.queue2)
            for i in range(length-1):
                self.queue1.append(self.queue2.pop(0))
            return self.queue2.pop()
```

[1]:./img/用两个栈模拟一个队列的操作.png
[2]:./img/用两个队列模拟一个栈的操作.png