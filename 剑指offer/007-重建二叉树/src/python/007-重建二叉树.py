# -*- coding:utf-8 -*-
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    # 返回构造的TreeNode根节点
    def reConstructBinaryTree(self, pre, tin):
        # write code here
        #判断两个输入序列是否为空
        if not pre and not tin:
            return None
        #将list转为set，判断两个输入序列的元素是否相同
        if set(pre)!=set(tin):
            return None
        root =TreeNode(pre[0])
        #index()方法返回查找对象的索引位置，如果没有找到对象则抛出异常。
        index = tin.index(pre[0])
        root.left=self.reConstructBinaryTree(pre[1:index+1],tin[0:index])
        root.right=self.reConstructBinaryTree(pre[index+1:],tin[index+1:])
        return root