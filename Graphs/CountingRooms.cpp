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


bool isValid(int i,int j,int n,int m ){
    if (i<0 || i>=n || j<0 || j>=m){
        return false;
    }return true;
}

void dfs(int i,int j,int n,int  m,vector<string>&grid,vector<vector<int>>&vis){
    if(!isValid(i,j,n,m) || vis[i][j] == 1 || grid[i][j] != '.' ) return;
    vis[i][j]=1;
    if(isValid(i+1,j,n,m) && vis[i+1][j]==0) dfs(i+1,j,n,m,grid,vis);
    if(isValid(i,j+1,n,m) && vis[i][j+1]==0 ) dfs(i,j+1,n,m,grid,vis);
    if(isValid(i-1,j,n,m) && vis[i-1][j]==0  ) dfs(i-1,j,n,m,grid,vis);
    if(isValid(i,j-1,n,m) && vis[i][j-1]==0  )dfs(i,j-1,n,m,grid,vis);
}

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<string>grid;
    for(int i=0;i<n;i++)
    {
        string temp;
        cin>>temp;
        grid.push_back(temp);
    }
    vector<vector<int>>vis(n,vector<int>(m,0));
    int count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]=='.' && vis[i][j]==0){
                count++;
                dfs(i,j,n,m,grid,vis);

            }
        }
    }
    cout<<count<<endl;

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

