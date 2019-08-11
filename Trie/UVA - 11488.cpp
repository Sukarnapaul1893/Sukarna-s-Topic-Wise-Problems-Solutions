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

int TRIE[MAX][2];
int tot;
bool endnode[MAX];
unordered_map<int,int>mp;
unordered_map<int,int>len;
void insert(string s){
    int p=1;

    for(int i=0;i<s.length();i++){
        int temp = s[i]-'0';
        if(TRIE[p][temp]==0){
            TRIE[p][temp]=++tot;
        }
        mp[TRIE[p][temp]]++;
        len[TRIE[p][temp]]=i+1;
        p = TRIE[p][temp];
    }
}


int main(){
	IOS
	//freopen("output.txt","w",stdout);
    int t;
    cin>>t;

    for(int tt=0;tt<t;tt++){
        int n;
        cin>>n;
        mp.clear();
        tot=1;
        memset(TRIE,0,sizeof TRIE);
        memset(endnode,0,sizeof endnode);
        string s;
        for(int i=0;i<n;i++){

            cin>>s;
            insert(s);
        }
        int ans=0;
        for(auto it=mp.begin();it!=mp.end();it++){
            ans = max(len[(*it).first]*(*it).second,ans);
        }
        cout<<ans<<"\n";
    }
}
