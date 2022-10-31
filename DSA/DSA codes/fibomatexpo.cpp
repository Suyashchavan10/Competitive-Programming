#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > multiply(vector<vector<int> > &x, vector<vector<int> > &y)
{
    int n = x.size();
    vector<vector<int> > ans(n, vector<int>(n, 0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                ans[i][j] = (ans[i][j] + (x[i][k] * y[k][j])%10)%10;
            }
        }
    }
    return ans;
}

vector<vector<int> > matrixExponentiate(vector<vector<int> > &a, string n)
{
    string str1 = (n.size(), "0");
    string str2 = (n.size() - 1, "0");
    str2 = str2 + "1";
    if(n == str1)
    {
        int sz = a.size();
        vector<vector<int> > idn(sz, vector<int>(sz, 0));
        for(int i=0;i<sz;i++)
            idn[i][i] = 1;
        return idn;
    }
    if(n == str2)
        return a;
    string halfstr = n.substr(1, n.size()-1);
    if(n.at(0) == '1')
        halfstr = "1" + halfstr;
    else
        halfstr = "0" + halfstr;

    vector<vector<int> > temp = matrixExponentiate(a, halfstr);
    vector<vector<int> > ans = multiply(temp, temp);
    if(n.at(n.size()-1) == '1')
    {
        ans = multiply(ans, a);
    }
    return ans;
}

int main()
{
    //f(n) = (f(n-1)+f(n-2)) % m, m = 10, f(0) = 0, f(1) = 1;
    string p;
    cin>>p;
    vector<vector<int> > a = {{1,1}, {1,0}};
    vector<vector<int> > ans = matrixExponentiate(a,p); 
    cout<<ans[1][0]<<endl;
    return 0;
}