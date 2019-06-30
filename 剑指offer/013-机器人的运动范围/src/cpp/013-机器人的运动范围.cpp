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