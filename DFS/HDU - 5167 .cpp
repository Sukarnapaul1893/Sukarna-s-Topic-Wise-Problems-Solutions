#pragma warning(disable:4786)
#pragma warning(disable:4996)
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include<ext/pb_ds/detail/standard_policies.hpp>
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define pii pair<int,int>
#define pll pair<long long ,long long>
#define pli pair<long long , int>
#define pil pair<int ,long long>
#define pi acos(-1)
#define pb push_back
#define mkp make_pair
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define MAX 300005
#define INF 0x3f3f3f3f
#define mset(a,b) memset(a,b,sizeof(a))
template <class T> inline T bigmod(T p,T e,T M){ll ret = 1LL;for(; e > 0LL; e >>= 1LL){if(e & 1LL) ret = (ret * p) % M;p = (p * p) % M;}return (T)ret;}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}   // M is prime}
using namespace std;
using namespace __gnu_pbds;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

vector<ll>fib;

void gen_fib(){
    ll a=1;
    ll b=1;


    while(b<=1000000007){
        fib.pb(a+b);
        ll temp=a+b;
        a=b;
        b=temp;
    }
}
bool bl=false;
void dfs(ll s , int lim){
    if(bl==true)return;
    if(s==1){
        bl=true;
        return;
    }
    for(int i=lim;i>=0;i--){
        if(s<fib[i])continue;
        else if(s%fib[i]==0 && bl==false){
            dfs(s/fib[i],i);
        }
    }
}

int main(){
	IOS
	//freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    gen_fib();

    for(int tt=0;tt<t;tt++){
        int n;
        cin>>n;
        int lim=fib.size()-1;
        dfs(n,lim);
        if(bl==true || n<=1){
            cout<<"Yes\n";
        }
        else{
            cout<<"No\n";
        }
        bl=false;
    }
}
