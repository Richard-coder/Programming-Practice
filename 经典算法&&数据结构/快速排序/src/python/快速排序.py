# -*- coding:utf-8 -*-
#下面是Python的list conprehension实现快速排序的例子，短短几行代码，不仅展示出了快速排序的精髓，而且非常pythonic，看了不禁叹服。
def pythonic_quick_sort(a):
    if len(a) <= 1:
        return a
    pivot = a[-1]
    pivots = [i for i in a if i == pivot]
    left = pythonic_quick_sort([i for i in a if i < pivot])
    right = pythonic_quick_sort([i for i in a if i > pivot])
    return left + pivots + right
