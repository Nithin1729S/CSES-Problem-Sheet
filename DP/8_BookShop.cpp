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


int f(int idx,int cost,int &maxCost,vector<int>&prices,vector<int>&pages,vector<vector<int>>&dp){
    if(idx>=prices.size()) return 0;
    if(dp[idx][cost]!=-1) return dp[idx][cost];
    int pick=-1e9;
    int notpick=-1e9;
    if(cost+prices[idx]<=maxCost) pick=pages[idx]+f(idx+1,cost+prices[idx],maxCost,prices,pages,dp);
    notpick=0+f(idx+1,cost,maxCost,prices,pages,dp);
    return dp[idx][cost]=max(pick,notpick);
}

void solve()
{
    int n,x;
    cin>>n>>x;
    vector<int>h;
    vector<int>s;
    //vector<vector<int>>dp(n,vector<int>(x+1,-1));
    for(int i=0;i<n;i++)
    {
        int ele;
        cin>>ele;
        h.push_back(ele);
    }

    for(int i=0;i<n;i++)
    {
        int ele;
        cin>>ele;
        s.push_back(ele);
    }
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= x; j++) {
            // Not picking the current book
            dp[i][j] = dp[i - 1][j];
            
            // Picking the current book if possible
            if (j >= h[i - 1]) 
                dp[i][j] = max(dp[i][j], dp[i - 1][j - h[i - 1]] + s[i - 1]);
        }
    }

    cout << dp[n][x] << endl;
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

