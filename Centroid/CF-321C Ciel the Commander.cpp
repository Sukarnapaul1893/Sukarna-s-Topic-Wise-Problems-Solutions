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

vector<int>adj[100005];
vector<int>cenadj[100005];
int ans[100005];
bool markcentroid[100005];
int subtreenodes[100005], centroidpar[100005];

int cntnodes(int s, int par){
    subtreenodes[s]=1;
    for(int i=0;i<adj[s].size();i++){
        int u = adj[s][i];
        if(markcentroid[u]==0 && u!=par)subtreenodes[s]+=cntnodes(u,s);
    }
    return subtreenodes[s];
}

int dfs(int s, int par, int totalnodes){
    for(int i=0;i<adj[s].size();i++){
        int u = adj[s][i];
        if(subtreenodes[u]>totalnodes/2 && u!=par && markcentroid[u]==0)return dfs(u,s,totalnodes);
    }
    return s;
}

int buildCentroidTree(int root, int par){

    int totalnodes = cntnodes(root, par);
    int centroid = dfs(root,par,totalnodes);

    markcentroid[centroid]=1;
    //ans[centroid]=(char)lvl;

    for(int i=0;i<adj[centroid].size();i++){
        int u = adj[centroid][i];
        if(markcentroid[u]==1)continue;
        int a = buildCentroidTree(u,centroid);
        cenadj[centroid].pb(a);
        //cenadj[a].pb(centroid);

        centroidpar[a]=centroid;
    }
    return centroid;
}
bool vis[100005];
void bfs(int s){
    //vis[s]=true;

    queue<int>q;
    q.push(s);
    int level=0;
    while(!q.empty()){

        int sz = q.size();
        while(sz--){
            int u = q.front();
            ans[u] = level;
            //vis[u]=true;
            q.pop();
            for(int i=0;i<cenadj[u].size();i++){
                //if(vis[cenadj[u][i]]==true)continue;
                q.push(cenadj[u][i]);

           }
        }
        level++;
    }
}


int main(){
    IOS
    //freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    memset(vis,false,sizeof vis);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;

        adj[u].pb(v);
        adj[v].pb(u);
    }

    int centroid = buildCentroidTree(1,0);

    bfs(centroid);

    for(int i=1;i<=n;i++)cout<<(char)(ans[i]+'A')<<" ";
}
