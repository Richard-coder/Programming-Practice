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