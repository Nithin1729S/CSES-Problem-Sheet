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


int f(int num, int count, vector<vector<int>>& dp) {
    if (num < 0) {
        return 1e9;
    }
    if (num == 0) {
        return count;
    }
    if (dp[num][count] != -1) return dp[num][count];

    set<int> nums;
    int num_copy = num;
    while (num_copy > 0) {
        nums.insert(num_copy % 10);
        num_copy = num_copy / 10;
    }

    int mini = 1e9;
    for (auto& it : nums) {
        if (it == 0) continue;
        if (num - it >= 0)
            mini = min(mini, f(num - it, count + 1, dp));
    }

    return dp[num][count] = mini;
}

void solve()
{
    int n;
    cin>>n;
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    cout<<f(n,0,dp)<<endl;

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

