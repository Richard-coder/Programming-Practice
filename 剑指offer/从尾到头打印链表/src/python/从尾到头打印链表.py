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