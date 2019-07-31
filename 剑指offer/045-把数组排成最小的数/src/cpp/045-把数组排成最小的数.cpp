class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        string res="";
        int length=numbers.size();
        if(length<=0)
            return res;
        vector<string> temp(length);
        for(int i=0;i<length;i++)
            temp[i]=to_string(numbers[i]);
        
        sort(temp.begin(),temp.end(),compare);
        
        for(int i=0;i<length;i++)
            res=res+temp[i];
        
        return res;
       
    }
    
    static bool compare(const string& str1,const string& str2){
        string s1=str1+str2;
        string s2=str2+str1;
        return s1<s2;
    }
};