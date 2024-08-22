#include<bits/stdc++.h>
using namespace std;
#define int long long 
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
#define f0(i,n)  for(int i=0;i<(int)n;i++)
#define f1(i,n)  for(int i=1;i<=(int)n;i++)
#define test int t;cin>>t;while(t--)
#define take(a,n) vi a(n); f0(i,n) cin >> a[i];
#define give(a,n) f0(i,n){cout << a[i] << ' ';}cout << endl;


int helper(int curr,int target,vector<int>&dp){
    if(curr==target) return 1;
    if(curr>target) return 0;
    if(dp[curr]!=-1) return dp[curr];
    int ways=0;
    for(int i=1;i<=6;i++){
        ways+=(helper(curr+i,target,dp)%MOD);
    }
    return dp[curr]=ways;
}
void solve()
{
    int n;
    cin>>n;
    vector<int>dp(n+1,-1);
    cout<<helper(0,n,dp)%MOD<<endl;
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

