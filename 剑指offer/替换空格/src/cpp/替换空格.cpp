class Solution {
public:
	void replaceSpace(char *str,int length) {
        //这道题里的str，默认在替换空格后足够大，length是str的原长度，不包括最后的'0'
        if (str==NULL&&length<=0)
            return;
        int num=0;
        for (int i=0;i<length;i++){
            if (str[i]==' ')
                num++;
        }
        int len=length+num*2;
        for (int i=length-1,j=len-1;i>=0&&j>=0;i--){
            if (str[i]==' '){
                str[j--]='0';
                str[j--]='2';
                str[j--]='%';
            }else
                str[j--]=str[i];
        }
        str[len]='0';
	}
};