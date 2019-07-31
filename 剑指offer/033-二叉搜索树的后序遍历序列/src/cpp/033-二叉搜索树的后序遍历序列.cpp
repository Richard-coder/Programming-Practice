class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        return VerifySquenceOfBST_Core(sequence,0,sequence.size()-1);
    }
    bool VerifySquenceOfBST_Core(vector<int> sequence,int start,int end){
        if(sequence.empty()||start>end)
            return false;
        int i=start;
        for(;i<=end-1;i++){
            if(sequence[i]>sequence[end])
                break;
        }
        int j=i;
        for(;j<=end-1;j++){
            if(sequence[j]<sequence[end])
                return false;
        }
        bool left=true;
        if(i>start)
            left=VerifySquenceOfBST_Core(sequence,start,i-1);
        bool right=true;
        if(i<end-1)
            right=VerifySquenceOfBST_Core(sequence,i,end-1);
        return left&&right;
    }
};