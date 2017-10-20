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