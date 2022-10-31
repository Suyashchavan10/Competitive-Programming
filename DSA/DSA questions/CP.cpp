#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int mod = 1e9+7;

int recur(int vertex, int n){
    if(n == 0){
        return vertex == 3;
    }
    int count = 0;
    for(int v=0; v<4; v++){
        if(v != vertex){
            count += recur(v, n-1);
        }
        count %= mod;
    }
    return count;
}

int dpmem(int vertex, int n, vector<vector<int>> &dp){
    if(n == 0){
        return dp[n][vertex] = (vertex == 3);
    }
    if(dp[n][vertex] != -1){
        return dp[n][vertex];
    }
    int count = 0;
    for(int v=0; v<4; v++){
        if(v != vertex){
            count += dpmem(v, n-1, dp);
        }
        count %= mod;
    }
    return dp[n][vertex] = count;
}

int dptab(int vertex, int n){
    vector<vector<int>> dp(n+1, vector<int>(4, 0));
    dp[0][3] = 1;
    for(int i=1; i<=n; i++){
        int count = 0;
        for(int v=0; v<4; v++){
            if(v != vertex){
                count += dp[i-1][v];
            }
            count %= mod;
        }
        
    }
}

int main()
{
    int n;
    cin>>n;
    //vector<vector<int>> dp(n+1, vector<int>(4, -1));
    //cout<<dpmem(3, n, dp);
    return 0;
}
/*
long long n;
        cin>>n;
        long long ans = 0;
        long long even = n/2;
        long long odd = n-even;
        ans += 2*odd;
        ans %= mod;

        long long six = n/6;
        ans += 3*(even-six);
        ans %= mod;

        long long sixeven = six/2;
        long long sixodd = six-sixeven;
        ans += 4*(sixodd);
        ans %= mod;

        cout<<ans<<endl;
*/