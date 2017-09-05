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