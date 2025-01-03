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
    int n;
    cin>>n;
    vector<pair<int,int>>nums;
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        nums.push_back({ele,i});
    }
    sort(nums.begin(),nums.end(),[](pair<int,int>&a,pair<int,int>&b){
        return a.first<b.first;
    });


    int rounds = 1; 
    for (int i = 1; i < n; i++) {
        if (nums[i].second < nums[i - 1].second) {
            rounds++;
        }
    }
    cout<<rounds<<endl;

    
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
