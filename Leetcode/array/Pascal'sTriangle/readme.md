118. Pascal's Triangle

tags： Array

---

## 题目原文
GGiven numRows, generate the first numRows of Pascal's triangle.
For example, given numRows = 5,
Return

    [
         [1],
        [1,1],
       [1,2,1],
      [1,3,3,1],
     [1,4,6,4,1]
    ]


## 题目大意
输入一个数字，输出相应阶数的帕斯卡三角。



## 解题思路
要得到一个帕斯卡三角， 我们只需要找到规律即可。

第k层有k个元素
每层第一个以及最后一个元素值为1
对于第k（ k > 2） 层, 第n（ n > 1 && n < k） 个元素A[k][n]， A[k][n] = A[k-1][n-1] + A[k-1][n]


## 代码
### [c++代码](./src/cpp/Pascal'sTriangle.cpp)
```c++
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > pas;
        pas.resize(numRows);
        for(int i=0;i<numRows;i++){
            pas[i].resize(i+1);
            pas[i][0]=1;
            pas[i][pas[i].size()-1]=1;
            for(int j=1;j<pas[i].size()-1;j++){
                pas[i][j]=pas[i-1][j-1]+pas[i-1][j];
            }
        }
        return pas;
    }
};
```

### [python代码](./src/python/Pascal'sTriangle.py)
```python
class Solution(object):
    def generate(self, numRows):
        pas=[]
        for i in xrange(numRows):
            pas.append([])
            for j in xrange(0,i+1):
                if j in (0,i):
                    pas[i].append(1)
                else:
                    pas[i].append(pas[i-1][j-1]+pas[i-1][j])
        return pas
if __name__ =="__main__":
    print Solution().generate(5)
```
