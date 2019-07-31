# 029-顺时针打印矩阵

tags： 边界条件

---

## 题目原文

[牛客网链接](https://www.nowcoder.com/practice/9b4c81a02cd34f76be2659fa0d54342a?tpId=13&tqId=11172&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，如果输入如下矩阵：

![åæOfferï¼åä¹ï¼ï¼é¡ºæ¶éæå°ç©éµ](img/readme.assets/basis_19_1.jpg)

则依次打印出数组：1，2，3，4，8，12，16，15，14，13，9，5，6，7，11，10。

## 解题思路

[参考](https://www.cnblogs.com/wanglei5205/p/8617424.html)

 把矩阵看成由若干个顺时针方向的圈组成，循环打印矩阵中的每个圈，每次循环打印一个圈。打印一圈通常分为四步，第一步从左到右打印一行；第二步从上到下打印一列；第三步从右到左打印一行；第四步从下到上打印一列。设置四个变量left，right，top，btm，用于表示圈的方位，每一步根据起始坐标和终止坐标循环打印。

**注意**：最后一圈有可能不需要四步，有可能只有一行，只有一列，只有一个数字，因此我们要仔细分析打印每一步的前提条件：

- 打印第一步，第一步总是需要的

  ![image_thumb[19]](img/readme.assets/1307402-20180321153823289-522341390.png)

- 打印第二步的前提条件是(top<btm)

![image_thumb[20]](img/readme.assets/1307402-20180321153824388-2135481654.png)

- 打印第三步的前提条件是(top<btm && left<right)

![image_thumb[21]](img/readme.assets/1307402-20180321153825500-1956530299.png)

- 打印第四步的前提条件是(top+1<btm&&left<right)

![image_thumb[22]](img/readme.assets/1307402-20180321153826627-1772650522.png)

终止条件

接下来分析循环结束的条件。假设这个矩阵的行数是rows，列数是columns。打印第一个圈是左上角元素的坐标是（0，0），第二圈的左上角的坐标是（1，1），以此类推。我们注意到，左上角的坐标中行标和列标总是相同的，于是可以在矩阵中选取左上角为（start，start）的一圈为我们分析的目标。 

对一个5*5的矩阵而言，最后一圈只有一个数字，对应的坐标为（2，2）。我们发现5>2*2.对于一个6*6的矩阵而言，最后一圈有4个数字，其左上角的坐标仍然为（2，2）。我们发现6>2*2依然成立。于是我们可以得出继续循环的条件是columns>startX*2并且rows>startY*2.



## 代码

### [c++代码](./src/cpp/029-顺时针打印矩阵.cpp)

```c++
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> res;
        if(matrix.empty()||matrix[0].empty())
            return res;
        int rowLength=matrix.size(), colLength=matrix[0].size();
        int startRow=0, startCol=0;
        int endRow=rowLength-startRow-1,endCol=colLength-startCol-1;
        while(rowLength>startRow*2&&colLength>startCol*2){
            for(int i=startCol;i<=endCol;i++){
                res.push_back(matrix[startRow][i]);
            }
            if(endRow>startRow){
                for(int i=startRow+1;i<=endRow;i++)
                    res.push_back(matrix[i][endCol]);
            }
            if(endRow>startRow&&endCol>startCol){
                for(int i=endCol-1;i>=startCol;i--)
                    res.push_back(matrix[endRow][i]);
            }
            
            if(endRow-startRow>=2&&endCol>startCol){
                for(int i=endRow-1;i>=startRow+1;i--)
                    res.push_back(matrix[i][startCol]);
            }
            startRow++;
            startCol++;
            endRow--;
            endCol--;
        }
        return res;
    }
};
```

### [python代码](./src/python/029-顺时针打印矩阵.py)

```python

```

## 用一个循环

[参考]([https://github.com/gatieme/CodingInterviews/tree/master/020-%E9%A1%BA%E6%97%B6%E9%92%88%E6%89%93%E5%8D%B0%E7%9F%A9%E9%98%B5](https://github.com/gatieme/CodingInterviews/tree/master/020-顺时针打印矩阵))

上面的解法用了两个循环嵌套, 也可以利用一层循环来实现 当然由于也是需要转向，那么我们可以用一个数组来

```
const int D[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; 表示转向操作
```

这样我们的代码成为

```
class Solution
{
    int n, m;
    vector<vector<bool> > v;
    bool judge(int i, int j)
    {
        return 0 <= i && i < n && 0 <= j && j < m && !v[i][j];
    }

public:
     vector<int> printMatrix(vector<vector<int> > a)
     {
        vector<int> r;
        if((n = a.size()) == 0 || (m = a[0].size()) == 0)
            return r;

        v = vector<vector<bool> >(n, vector<bool>(m, false));
        const int D[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        int i = 0, j = 0, d = 0, count = m * n;
        while(count--)
        {
            r.push_back(a[i][j]);
            v[i][j] = true;
            if(!judge(i + D[d][0], j + D[d][1]))
            {
                (++d) %= 4; //转弯
            }
            i += D[d][0];
            j += D[d][1];//前进
        }
        return r;
    }
};
```

