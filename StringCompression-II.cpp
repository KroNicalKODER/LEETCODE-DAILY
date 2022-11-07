#include<bits/stdc++.h>
using namespace std;
int dp[101][27][101][101];
class Solution {
public:
    string str;
    int solve(int index, int prev, int consCount, int k ){
        if(k<0)return INT_MAX;
        if(index>=str.size())return 0;
        if(dp[index][prev][consCount][k] != -1)
        {
            return dp[index][prev][consCount][k];
        }
       int remAlpha = solve(index+1,prev, consCount,k-1);
        int keepAlpha=0;
        if(str[index]-'a'==prev){
             if(consCount==1||consCount==9||consCount==99)
             {
                 keepAlpha+=1;
             }
            keepAlpha = keepAlpha + solve(index+1,prev, consCount+1, k);
        }
        else {
            keepAlpha=1+solve(index+1, str[index]-'a', 1, k);
        }
        dp[index][prev][consCount][k] = min(remAlpha,keepAlpha);
        return dp[index][prev][consCount][k];
        return min(remAlpha,keepAlpha);
    }
    int getLengthOfOptimalCompression(string s, int k) {
        str=s;
        memset(dp,-1,sizeof(dp));
        return solve(0, 26, 0, k);
    }
};
