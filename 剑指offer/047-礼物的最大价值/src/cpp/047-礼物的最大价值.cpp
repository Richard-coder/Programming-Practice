class Solution {
public:
    int getMaxValue(vector<vector<int>>& grid) {
        if(grid.empty()||grid[0].empty())
            return 0;
        int rows=grid.size();
        int cols=grid[0].size();
        
        vector<int> res(cols);
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                int left=0,up=0;
                if(i>0)
                    up=res[j];
                if(j>0)
                    left=res[j-1];
                res[j]=max(up,left)+grid[i][j];
            }
        }
        return res[cols-1];
    }
};