#pragma warning(disable:4786)
#pragma warning(disable:4996)
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include<ext/pb_ds/detail/standard_policies.hpp>
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
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;


vector<int>adj[300005];

bool vis[300005];

int x,y;

vector<int>vec[2];


void dfs(int source,int p){
    vis[source]=true;

    for(int i=0;i<adj[source].size();i++){
        if(adj[source][i]==y && p==0)continue;
        else if(adj[source][i]==x && p==1)continue;
        else if(vis[adj[source][i]]==false){
            vis[adj[source][i]]=true;
            vec[p].pb(adj[source][i]);
            dfs(adj[source][i],p);
        }
        else{
            continue;
        }
    }
}

int main(){
    IOS
    //freopen("output.txt","w",stdout);
    ll n;
    cin>>n;

    cin>>x>>y;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;

        adj[u].pb(v);
        adj[v].pb(u);
    }
    memset(vis,false,sizeof vis);
    vec[0].pb(x);
    dfs(x,0);

    memset(vis,false,sizeof vis);
    vec[1].pb(y);
    dfs(y,1);

    ll ans=0;
    ll len1 = vec[0].size();
    ans = len1*(len1-1LL);
    ll len2 = vec[1].size();

    ordered_set st;
    for(int i=0;i<vec[1].size();i++){
        st.insert(vec[1][i]);
    }

    for(int i=0;i<vec[0].size();i++){

        st.erase(vec[0][i]);
    }
    ll common = len2-st.size();

    ll sz  = st.size();

    cout<<ans+sz*len1+sz*(sz-1LL)+common*sz;
}
