# 012-矩阵中的路径

tags： 回溯法 深度优先遍历DFS

---

## 题目原文

[牛客网链接](https://www.nowcoder.com/questionTerminal/c61c6999eecb4b8f88a98f66b273a3cc)

请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。如果一条路径经过了矩阵中的某一个格子，则之后不能再次进入这个格子。 例如 a b c e s f c s a d e e 这样的3 X 4 矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。

```
a b c e 
s f c s 
a d e e
```

## 解题思路

> [参考](https://www.cnblogs.com/tianzeng/p/10134445.html)

这是一个能够用回朔法解决的典型题。首先，在矩阵中任选一个格子作为路径的起点。假设矩阵中某个格子的字符为ch，那么这个格子不可能处在路径上的第i个位置。假设路径上的第i个字符不是ch。那么这个格子不可能处在路径上的第i个位置。假设路径上的第i个字符正好是ch。那么往相邻的格子寻找路径上的第i+1个字符。除在矩阵边界上的格子之外，其它格子都有4个相邻的格子。反复这个过程知道路径上的全部字符都在矩阵中找到相应的位置。


因为回朔法的递归特性，路径能够被看成一个栈。当在矩阵中定位了路径中前n个字符的位置之后。在与第n个字符相应的格子的周围都没有找到第n+1个字符。这个时候仅仅要在路径上回到第n-1个字符。又一次定位第n个字符。

因为路径不能反复进入矩阵的格子。还须要定义和字符矩阵大小一样的布尔值矩阵，用来标识路径是否已经进入每个格子。 
当矩阵中坐标为（row,col）的格子和路径字符串中下标为pathLength的字符一样时。从4个相邻的格子(row,col-1),(row-1,col),(row,col+1)以及(row+1,col)中去定位路径字符串中下标为pathLength+1的字符。 

假设4个相邻的格子都没有匹配字符串中下标为pathLength+1的字符，表明当前路径字符串中下标为pathLength的字符在矩阵中的定位不对，我们须要回到前一个字符(pathLength-1)，然后又一次定位。


一直反复这个过程，直到路径字符串上全部字符都在矩阵中找到合适的位置

## 代码

### [c++代码](./src/cpp/012-矩阵中的路径.cpp)

**注意:** hasPathCore()中的参数pathLength不是引用也可以, 但 visited一定要在迭代中保持状态同步.

```c++
class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if(matrix==nullptr||rows<1||cols<1||str==nullptr)
            return false;
        int pathLength=0;
        bool *visited =new bool[rows*cols];
        memset(visited,0,rows*cols);//把visited中元素初始化为false, 容易忘记
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(hasPathCore(matrix,rows,cols,i,j,str,pathLength,visited))
                    return true;
            }
        }
        delete[] visited;
        return false;
    
    }

    bool hasPathCore(char* matrix,int rows,int cols, int row, int col, const char* str, int& pathLength, bool* visited){
        if(str[pathLength]=='\0')
            return true;
        bool hasPath=false;
        if(row>=0&&col>=0&&row<rows&&col<cols&&matrix[row*cols+col]==str[pathLength]&&!visited[row*cols+col]){
            visited[row*cols+col]=true;
            pathLength++;
            hasPath=hasPathCore(matrix,rows,cols,row,col-1,str,pathLength,visited)||
                    hasPathCore(matrix,rows,cols,row,col+1,str,pathLength,visited)||
                    hasPathCore(matrix,rows,cols,row-1,col,str,pathLength,visited)||
                    hasPathCore(matrix,rows,cols,row+1,col,str,pathLength,visited);
            if(!hasPath){
                pathLength--;
                visited[row*cols+col]=false;
            }
        }
        return hasPath;
    }

};
```

### [python代码](./src/python/012-矩阵中的路径.py)

```python

```

### 非递归版本

这个题还可以用栈而不用递归来实现, 不过暂时没时间写代码了

但一般解题的话, **能用递归的就不用栈，否则就是自找麻烦**