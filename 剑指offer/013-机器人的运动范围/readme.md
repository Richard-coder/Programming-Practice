# 013-机器人的运动范围

tags： 回溯法 DFS

---

## 题目原文

[牛客网链接](https://www.nowcoder.com/practice/6e5207314b5241fb83f2329e89fdecc8?tpId=13&tqId=11219&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking&tPage=4)

地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于k的格子。 例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？

## 解题思路

核心思路：
1.从(0,0)开始走，每成功走一步标记当前位置为true,然后从当前位置往四个方向探索，
返回1 + 4 个方向的探索值之和。
2.探索时，判断当前节点是否可达的标准为：
1）当前节点在矩阵内；
2）当前节点未被访问过；
3）当前节点满足limit限制。



**与面试题12矩阵中的路径不同的是**, 在面试题12中，如果探索完一条路径之后，在探索下一条路径时之前做的标记都应该删除，不能相互影响。而这个题中，如果一个点已经走过了，那么其可以达到的点都应该走过，所以一个点仅仅需要走一次就可以了，也就是说多次探索之间公用一个标记矩阵，相互之间是需要信息共享的。

## 代码

### [c++代码](./src/cpp/013-机器人的运动范围.cpp)

```c++
class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        if(threshold<=0||rows<=0||cols<=0)
            return 0;
        bool* visited= new bool[rows*cols];
        memset(visited,0,rows*cols);
        
        int count=movingCountCore(threshold,rows,cols,0,0,visited);
        delete[] visited;
        
        return count;
    }
    
    int movingCountCore(int threshold, int rows, int cols, int row, int col , bool* visited){
        int count=0;
        if(check(threshold,rows,cols,row,col,visited)){
            visited[row*cols+col]=true;
            count=1+movingCountCore(threshold,rows,cols,row+1,col,visited)+
                    movingCountCore(threshold,rows,cols,row-1,col,visited)+
                    movingCountCore(threshold,rows,cols,row,col+1,visited)+
                    movingCountCore(threshold,rows,cols,row,col-1,visited);
        }
        return count;
    }
    
    bool check(int threshold, int rows, int cols, int row, int col , bool* visited){
        if(col>=0&&row>=0&&col<cols&&row<rows&&!visited[row*cols+col]&&(getDigitSum(row)+getDigitSum(col)<=threshold))
            return true;;
        return false;
    }
    
        
    int getDigitSum(int num){
        int sum=0;
        while(num>0){
            sum=sum+num%10;
            num=num/10;
        }
        return sum;
    }
};
```

### [python代码](./src/python/013-机器人的运动范围.py)

```python

```

