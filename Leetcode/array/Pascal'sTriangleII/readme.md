119. Pascal's Triangle II

tags： Array

---

## 题目原文
Given an index k, return the kth row of the Pascal's triangle.
For example, given k = 3,
Return [1,3,3,1].

Note:

Could you optimize your algorithm to use only O(k) extra space?
## 题目大意
给出帕斯卡三角形第k层，注意这里的K从0开始计数


## 解题思路
要求空间复杂度为O(K)，因此不能使用二维数据，应用一维数组滚动计算。

采用从后往前计算的策略

帕斯卡三角的计算公式是这样的， A[k][n] = A[k-1][n-1] + A[k-1][n]。

假设现在数组存放的第3层的数据， [1, 3, 3, 1]， 如果我们需要计算第4层的数据， 如果我们从前往后计算，

譬如A[4][2]= A[3][1] + A[3][2]， 也就是4， 但是因为只有一个数组， 所以需要将4这个值覆盖到2这个位置，

那么我们计算A[4][3]的时候就会出现问题了， 因为这时候A[3][2]不是3， 而是4了。

为了解决这个问题， 我们只能从后往前计算， 仍然是上面那个例子， 我们实现计算A[4][3] = A[3][2] + A[3]
[3]， 也就是6， 我们将6直接覆盖到3这个位置， 但不会影响我们计算A[4][2]， 因为A[4][2] = A[3][1] + A[3]
[2]， 已经不会涉及到3这个位置了。 



## 代码
### [c++代码](./src/cpp/Pascal'sTriangleII.cpp)
```c++
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> pas;
        for(int i=0;i<rowIndex+1;i++){
            pas.resize(i+1,1);
            for(int j=i-1;j>0;j--){
                pas[j]=pas[j]+pas[j-1];
            }
        }
        return pas;
    }
};
```

### [python代码](./src/python/Pascal'sTriangleII.py)
```python
class Solution:
        # @return a list of integers
        def getRow(self, rowIndex):
                result = [0] * (rowIndex + 1)
                for i in xrange(rowIndex + 1):
                        old = result[0] = 1
                        for j in xrange(1, i + 1):
                                old, result[j] = result[j], old + result[j]
                return result


# Time: O(n^2)
# Space: O(n)
class Solution2:
        # @return a list of integers
        def getRow(self, rowIndex):
                result = [1]
                for i in range(1, rowIndex + 1):
                        result = [1] + [result[j - 1] + result[j] for j in xrange(1, i)] + [1]
                return result


if __name__ == "__main__":
        print Solution().getRow(3)

```
