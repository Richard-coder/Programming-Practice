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