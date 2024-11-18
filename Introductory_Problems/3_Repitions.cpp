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
#define take(a,n) vi a(n); f0(i,n) cin >> a[i];
#define give(a,n) f0(i,n){cout << a[i] << ' ';}cout << endl;

void solve()
{
    string dna;
    cin>>dna;
    int r=0;
    int l=0;
    int n=dna.size();
    unordered_map<char,int>mp;
    int maxLen=0;
    while(r<n){
        mp[dna[r]]++;
        if(mp.size()>1){
            mp[dna[l]]--;
            if(mp[dna[l]]==0){
                mp.erase(dna[l]);
            }
            l++;
        }
        if(mp.size()==1){
            maxLen=max(maxLen,r-l+1);
        }
        r++;
    }
    cout<<maxLen<<endl;

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

