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
typedef tree<pair<int, int>,null_type,less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;

map<string,vector<string> >adj;

map<pair<string,string > ,int>dir;
map<string,int>vis;

vector<string>topsort;


void dfs(string s){
    vis[s]++;
    for(auto it=adj[s].begin();it!=adj[s].end();it++){
        if(vis[(*it)]==0){
            dfs((*it));
        }
    }
    topsort.pb(s);
}
int scc;
void dfs2(string s,int i){
    if(topsort.size()-1==i)return;
    string now = topsort[i];
    string nxt = topsort[i+1];

    if(dir[{now,nxt}]==0)scc++;
    dfs2(nxt,i+1);
}
int main(){
    //IOS
    //freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);

    for(int tt=0;tt<t;tt++){
        int m;
        scanf("%d",&m);
        string source;
        scc=0;
        for(int i=0;i<m;i++){

            string s1,s2;
            cin>>s1>>s2;
            adj[s1].pb(s2);

            dir[{s2,s1}]++;
            if(i==0)source=s1;
        }
        dfs(source);
        reverse(topsort.begin(),topsort.end());
        auto start = topsort.begin();
        dfs2(*start,0);

        if(scc==topsort.size()-1)printf("Case %d: Yes\n",tt+1);
        else printf("Case %d: No\n",tt+1);

        topsort.clear();
        vis.clear();

        adj.clear();
    }
}
