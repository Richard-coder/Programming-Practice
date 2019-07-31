class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.empty()||popV.empty()||pushV.size()!=popV.size())
            return false;
        stack<int> data;
        bool res=false;
        int idx1=0,idx2=0;
        int length=popV.size();
        while(idx2<length){//这里不需要判断idx1, 如果非要写, 应该是idx1<=length
            while((data.empty()||data.top()!=popV[idx2])&&idx1<length){
                data.push(pushV[idx1]);
                idx1++;
            }
            if(data.top()==popV[idx2]){//这里不需要判断idx1, 如果非要写, 应该是idx1<=length
                data.pop();
                idx2++;
            }else
                break;
            
        }
        if(idx1==length&&idx2==length&&data.empty())
            return true;
        return false;
    }
};