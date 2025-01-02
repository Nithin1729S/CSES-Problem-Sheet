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
    int n,m;
    cin>>n>>m;
    vector<int>maxP;
    multiset<int,greater<int>>tickets;

    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        tickets.insert(ele);
    }

    for(int i=0;i<m;i++){
        int ele;
        cin>>ele;
        maxP.pb(ele);
    }


    vector<int>res;
    for(auto&it:maxP){
        auto ele=tickets.lower_bound(it);
        if(ele==tickets.end()){
            cout<<-1<<endl;
        }else{
            cout<<*ele<<endl;
            tickets.erase(ele);
        }

    }
    return ;



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

