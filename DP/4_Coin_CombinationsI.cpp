#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define INF INT_MAX
#define MOD 1000000007
#define pii pair<int,int>
#define endl '\n'
#define pb push_back
#define all(x) x.begin(),x.end()
#define clr(x) memset(x,0,sizeof(x))
#define sortUni(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define test int t;cin>>t;while(t--)
#define f0(i,n) for(int i = 0; i < n; i++)
#define take(a,n) vi a(n); f0(i,n) cin >> a[i];
#define give(a,n) f0(i,n){cout << a[i] << ' ';}cout << endl;


int f(int sum,vector<int>&coins,vector<int>&dp){
    if(sum==0){
        return 1;
    }
    if(sum<0){
        return 0;
    }
    int ways=0;
    if (dp[sum] != -1) return dp[sum];
    for(int coin:coins)
    {
        ways=(ways+f(sum-coin,coins,dp))%MOD;
    }
    return dp[sum]=ways;
}


void solve()
{
    int n,x;
    vector<int>coins;
    cin>>n>>x;
    for(int i=0;i<n;i++)
    {
        int ele;
        cin>>ele;
        coins.push_back(ele);
    }
    vector<int>dp(x+1,-1);
    cout<<f(x,coins,dp)<<endl;

}
int32_t main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    fast_io;
    //test
        solve();
    return 0;
}

