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
    int n,x;
    cin>>n>>x;
    vector<pair<int,int>>arr;
    for(int i=0;i<n;i++)
    {
        int ele;
        cin>>ele;
        arr.push_back({ele,i+1});
    }
    sort(arr.begin(),arr.end());
    
    for(int i=0;i<n-2;i++)
    {
        for(int j=i+1;j<n-1;j++)
        {
            int k=j+1;
            int l=n-1;
            while(l>k){
                int sm=arr[i].first+arr[j].first+arr[k].first+arr[l].first;
                if(sm==x){
                    cout<<arr[i].second<<" "<<arr[j].second<<" "<<arr[k].second<<" "<<arr[l].second<<endl;
                    return;
                }else if(sm>x){
                    l--;
                }else{
                    k++;
                }
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
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

