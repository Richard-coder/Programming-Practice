88. Merge Sorted Array

tags： Array

---

## 题目原文

[原文地址](https://leetcode.com/problems/merge-sorted-array/description/)

Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:

You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.
## 题目大意
nums1和nums2是两个排序好的数组，把两个数组合并放入nums1并排好序。

## 解题思路

A和B都已经是排好序的数组， 我们只需要从后往前比较就可以了。

因为A有足够的空间容纳A + B， 我们使用游标i指向m + n - 1， 也就是最大数值存放的地方， 从后往前遍历A， B， 谁大就放到i这里， 同时递减i。

## 注意事项

要注意num1或num2在移动过程中, 变为空数组后的情况

注意判断的逻辑顺序, 先判断两个数组是否为空,在不为空的条件下,再进行比较大小, 这样逻辑容易一些

单元测试, 特殊情况: 

```
[1]
1
[]
0
```

## 代码

### [c++代码](./src/cpp/MergeSortedArray.cpp)
```c++
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx1=m-1;
        int idx2=n-1;
        //int idx=m+n-1;
        for (int idx=m+n-1;idx>=0;idx--){
            if(idx1>=0&&idx2>=0){
                if (nums1[idx1]>=nums2[idx2])
                    nums1[idx]=nums1[idx1--];
                else
                    nums1[idx]=nums2[idx2--];
            }else{
                if (idx1>=0)
                    nums1[idx]=nums1[idx1--];
                    
                else
                    nums1[idx]=nums2[idx2--];
            }
        }
    }
};
```

### [python代码](./src/python/MergeSortedArray.py)
```python
class Solution:
        # @param A a list of integers
        # @param m an integer, length of A
        # @param B a list of integers
        # @param n an integer, length of B
        # @return nothing
        def merge(self, A, m, B, n):
                last, i, j = m + n - 1, m - 1, n - 1
                
                while i >= 0 and j >= 0:
                        if A[i] > B[j]:
                                A[last] = A[i]
                                last, i = last - 1, i - 1
                        else:
                                A[last] = B[j]
                                last, j = last - 1, j - 1
                
                while j >= 0:
                                A[last] = B[j]
                                last, j = last - 1, j - 1

if __name__ == "__main__":
        A = [1, 3, 5, 0, 0, 0, 0]
        B = [2, 4, 6, 7]
        Solution().merge(A, 3, B, 4)
        print A


```
