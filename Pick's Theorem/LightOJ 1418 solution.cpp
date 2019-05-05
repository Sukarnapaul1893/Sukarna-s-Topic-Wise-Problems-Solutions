#pragma warning(disable:4786)
#pragma warning(disable:4996)
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#define pii pair<int,int>
#define pll pair<long long ,long long>
#define pli pair<long long , int>
#define pil pair<int ,long long>
#define pi acos(-1)
#define pb push_back
#define mkp make_pair
#define all(a) a.begin(), a.end()
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define MAX 300005
#define INF 0x3f3f3f3f
template <class T> inline T bigmod(T p,T e,T M){ll ret = 1LL;for(; e > 0LL; e >>= 1LL){if(e & 1LL) ret = (ret * p) % M;p = (p * p) % M;}return (T)ret;}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}   // M is prime}

using namespace std;
using namespace __gnu_pbds;

typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update>pref_trie;


ll polygonArea(ll X[], ll Y[], int n)
{
    // Initialze area
    ll area = 0LL;

    // Calculate value of shoelace formula

    for (int i = 0; i < n; i++)
    {
        area += (X[i] * Y[i+1]) - (Y[i] * X[i+1]);

    }

    // Return absolute value
    return abs(area / 2.0);
}
ll boundary(ll X[], ll Y[], int n)
{
    ll ats = n;
    for(int i=0; i<n; i++)
    {
        ll dx = (X[i] - X[(i+1)%n]);
        ll dy = (Y[i] - Y[(i+1)%n]);
        ats+=abs(__gcd(dx,dy)) - 1;
    }
    return ats;
}
int main(){
    IOS
    //freopen("output.txt","w",stdout);
    int t;
    cin>>t;

    for(int tt=0;tt<t;tt++){
        int n;
        cin>>n;
        ll x[n+1],y[n+1];
        for(int i=1;i<=n;i++){
            cin>>x[i]>>y[i];
        }
        x[0] = x[n];
        y[0] = y[n];
        ll area = polygonArea(x,y,n);
        ll b = boundary(x,y,n);
        cout<<"Case "<<tt+1<<": "<<area-b/2+1<<"\n";
    }
}
