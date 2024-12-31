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


int f(int i,int j,vector<string>&matrix,vector<vector<int>>&dp){
    if(i<0 || j<0) return 0;
    if(matrix[i][j]=='*') return 0;
    if(i==0 && j==0) return 1;
    if(dp[i][j]!=-1) return dp[i][j]; 
    return dp[i][j]= (f(i-1,j,matrix,dp) + f(i,j-1,matrix,dp))%MOD;
}

void solve()
{
    int n;
    cin>>n;
    vector<string>matrix;
    for(int i=0;i<n;i++)
    {
        string row;
        cin>>row;
        matrix.push_back(row);
    }
    int m=matrix[0].size();
    vector<vector<int>>dp(n,vector<int>(m,-1));
    cout<<f(matrix.size()-1,matrix[0].size()-1,matrix,dp)<<endl;

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

