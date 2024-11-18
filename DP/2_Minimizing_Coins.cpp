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


int f(int idx,int sum,vector<int>&coins,vector<vector<int>>&dp){
    if(idx==0){
        if(sum%coins[idx]==0) return sum/coins[idx];
        else return 1e9;
    }
    if(dp[idx][sum]!=-1) return dp[idx][sum];
    int take=1e9;
    if(sum>=coins[idx]) take=1+f(idx,sum-coins[idx],coins,dp);
    int nottake=f(idx-1,sum,coins,dp);
    return dp[idx][sum]=min(take,nottake);
}

void solve()
{
    int n;
    cin>>n;
    int x;
    cin>>x;
    vector<int>coins;
    for(int i=0;i<n;i++)
    {
        int ele;
        cin>>ele;
        coins.push_back(ele);
    }
    vector<vector<int>>dp(n,vector<int>(x+1,0));

    for(int i=0;i<=x;i++){
        if(i%coins[0]==0) dp[0][i]=i/coins[0];
        else dp[0][i]=1e9;
    }

    for(int idx=1;idx<n;idx++){
        for(int sum=0;sum<=x;sum++){
            int take=1e9;
            if( sum>=coins[idx]) take=1+dp[idx][sum-coins[idx]];
            int nottake=dp[idx-1][sum];
            dp[idx][sum]=min(take,nottake);
        }
    }
    int res=dp[n-1][x];
    if(res==1e9){
        cout<<-1<<endl;
    }else{
        cout<<res<<endl;
    }


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

