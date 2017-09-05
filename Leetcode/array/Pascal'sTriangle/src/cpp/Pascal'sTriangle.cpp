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