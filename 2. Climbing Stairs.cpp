#include<iostream>
#include<cstring>
using namespace std;

int dp[46];

int func(int n){
    if(n <= 1)  return 1;
    if(dp[n] != -1) return dp[n];
    //you can reach here from one step back
    int step1 = func(n-1);
    //you can reach here from two steps back
    int step2 = func(n-2);
    return dp[n] = step1 + step2;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    cout<<func(7)<<endl;

    //space optimized way
    //you can reach in your current stair from one-step back or two-steps back
    int step1_back = 1;
    int step2_back = 1;
    int ways = 0;
    for(int i=2; i<=7; ++i){
        ways = step1_back + step2_back;
        step1_back = step2_back;
        step2_back = ways;
    }
    cout<<ways<<endl;
    return 0;
}
