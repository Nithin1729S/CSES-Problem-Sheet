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
 
void solve()
{
    long long n,x;
    cin>>n>>x;
    vector<ll>arr;
    for(int i=0;i<n;i++)
    {
        ll ele;
        cin>>ele;
        arr.push_back(ele);
    }
    vector<vector<ll>>dp(n,vector<ll>(x+1,0));
    // cout<<f(n-1,x,arr,dp)<<endl;
    for (int i = 0; i < n; i++) {
        dp[i][0] = 1;
    }

    if (arr[0] <= x) {
        dp[0][arr[0]] = 1;
    }

    for (int i = 1; i < n; i++) {
        for (int sum = 0; sum <= x; sum++) {
            ll notTake = dp[i - 1][sum]; // Exclude the current element
            ll take = 0;
            if (sum >= arr[i]) {
                take = dp[i - 1][sum - arr[i]]; // Include the current element
            }
            dp[i][sum] = take + notTake;
        }
    }

    cout << dp[n - 1][x] << endl;
 
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
