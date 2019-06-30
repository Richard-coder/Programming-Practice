# -*- coding:utf-8 -*-
class Solution:
    # s 源字符串
    def replaceSpace(self, s):
        # write code here
        if not isinstance(s,str) or len(s) <=0 or s==None:
            return ""
        num=0
        for i in s:
            if i==' ':
                num+=1
        newLen=len(s)+num*2
        newStr=[None for i in range(newLen)]
        oIdx,nIdx=len(s)-1,newLen-1
        while oIdx>=0 and nIdx>=0:
            if s[oIdx]==' ':
                newStr[nIdx-2:nIdx+1]=['%','2','0']
                oIdx-=1
                nIdx-=3
            else:
                newStr[nIdx]=s[oIdx]
                oIdx-=1
                nIdx-=1
        return "".join(newStr)
        