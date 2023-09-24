#include<iostream>
#include<cstring>
using namespace std;

int dp[100];

int fibonacci(int n){
    if(n <= 1)  return n;
    if(dp[n] != -1) return dp[n];
    return dp[n] = fibonacci(n-1)+fibonacci(n-2);
}

int fibo(int n){
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2; i<=n; ++i){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int fib(int n){
    if(n <= 1)  return n;
    int prev1 = 0, prev2 = 1;
    int res = 0;
    for(int i=2; i<=n; ++i){
        res = prev1 + prev2;
        prev1 = prev2;
        prev2 = res;
    }
    return res;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    //memoization (top-down)
    cout<<fibonacci(7)<<endl;

    memset(dp, -1, sizeof(dp));
    //tabulation (bottom-up)
    cout<<fibo(7)<<endl;

    memset(dp, -1, sizeof(dp));
    //space-optimized
    cout<<fib(7)<<endl;

    return 0;
}
