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