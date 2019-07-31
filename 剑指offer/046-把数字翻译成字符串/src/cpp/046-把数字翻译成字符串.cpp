class Solution {
public:
    int getTranslationCount(string s) {
        int n = s.size();
        if(!n) return 0;
        if(n==1) return 1;

        vector<int> dp(n+1, 1);
        dp[n-1] = 1;
        for(int i=n-2;i>=0;i--){
            dp[i] = dp[i+1];
            if(s[i]=='1' || (s[i]=='2' && s[i+1]<'6')){
                dp[i] += dp[i+2];
            }
        }
        return dp[0];
    }
};