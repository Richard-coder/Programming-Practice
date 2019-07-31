class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
    int ones = 0;
     //m表示当前分析的是哪一个数位
    for (long long m = 1; m <= n; m *= 10) {
        int a = n/m, b = n%m;
        ones += (a + 8) / 10 * m + (a % 10 == 1) * (b + 1);
    }
    return ones;
    }

};