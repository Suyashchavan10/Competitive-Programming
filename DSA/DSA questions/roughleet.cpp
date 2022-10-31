#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    int diff = INT_MAX;
    for(int i=0; i<n; i++){
        int cur = v[i];
        int f ;
        if(cur == 1){
            f = 1;
        }
        for(int j=31; j>=0; j--){
            if(cur&(2<<j)){
                f = j;
                break;
            }
        }
        cout<<f<<endl;
        if(f >= n){
            bool ans = true;
            for(int j=f+1; j>=0;j--){
                if(cur&(2<<j)){
                    ans = false;
                }
            }
            if(ans == false){
                cout<<-1<<endl;
            }
        }
        
        else{
            int l;
            for(int j=0; j<=31; j++){
                if(cur&(2<<j)){
                    l = j;
                    break;
                }
            }
            cout<<l<<endl;
            diff = min(diff, n-l);
        }
    }
    cout<<diff<<endl;
    int a = sqrt(2*diff);
    if(a<=n){
        cout<<a<<endl;
    }
    else{
        cout<<-1<<endl;
    }

    return ;
}
int main(){
    int t;
    cin>>t;
    //t = 1;
    while(t--){
        solve();
    }
}
/*
int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    bool even = true;
    for(int i=0; i<n; i++){
        if(v[i]%2==1){
            even = false;
            break;
        }
    }
    if(even){
        cout<<-1<<endl;
    }
    else{
        
    }
*/
/*
string s, blank;
    //getline(cin, blank); 
    //getline(cin, blank);
    while (getline(cin, s) && !s.empty()) {
    vector<vector<char>> v(8, vector<char>(8));
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            v[i][j] = s[j];
        }
    }
    char ans = 'a';
    for(int i=0; i<8; i++){
        bool tp = true;
        for(int j=0; j<7; j++){
            if(v[i][j]!=v[i][j+1]){
                tp = false;
                break;
            }
        }
        if(tp){
            ans = v[i][0];
        }
    }
    for(int i=0; i<8; i++){
        bool tp = true;
        for(int j=0; j<7; j++){
            if(v[i][j]!=v[i+1][j]){
                tp = false;
                break;
            }
        }
        if(tp){
            ans = v[0][i];
        }
    }
    cout<<ans<<endl;
    }
*/

/*
int n;
cin>>n;
vector<int> vect(n);
for(int i=0; i<n; i++){
    cin>>vect[i];
}
*/

/*
#define ll long long
vector<ll> seg;
vector<ll> v;
int n;
void build(ll l,ll r,ll c=1)
{
    if(l==r)
    {
        seg[c]=v[l];
        return;
    }
    ll mid=(l+r)/2;
    build(l,mid,2*c); build(mid+1,r,2*c+1);
    seg[c]=seg[2*c]+seg[2*c+1];
    return;
}
ll query(ll l,ll r,ll a,ll b,ll c=1)
{
    if(l>b||r<a)
        return 0;
    if(l>=a&&r<=b)
        return seg[c];
    ll mid=(l+r)/2;
    return query(l,mid,a,b,2*c)+query(mid+1,r,a,b,2*c+1);
}
void update(ll l,ll r,ll ind,ll c=1)
{   
    if(ind<l||ind>r)
        return;
    if(l==r&&l==ind)
    {
        seg[c]=1;
        return;
    }
    ll mid=(l+r)/2;
    update(l,mid,ind,2*c);  update(mid+1,r,ind,2*c+1);
    seg[c]=seg[2*c]+seg[2*c+1];
}

void good(vector<int>& nums1, vector<int>& nums2, vector<int> &ans)
    {
    int n=nums1.size();
    
    v.resize(n+1,0);
    //ll ans=0;
    map<ll,ll> m;
    for(ll i=1;i<=n;i++)
    {
        m[nums2[i-1]+1]=i;
    }
    seg.clear();
    seg.resize(4*n+10,0);
    build(1,n);
    update(1,n,m[nums1[0]+1]);
    ans[nums1[0]] = m[nums1[0]+1]-1;
    for(ll i=2;i<=n;i++)
    {
        ll r=m[nums1[i-1]+1];
        ll q=query(1,n,1,r);
        ans[nums1[i-1]] = i+r-q-2;
        // cout<<q<<"\n";
        //ll d=i-q-1;
        //ll loc=(n-r)-d;
        //ans+=loc*q;
        update(1,n,r);
    }
    //return ans;
}
*/

/*
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
*/