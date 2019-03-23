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


vector <int> prime;
bitset <20000010> bs;

void sieve (int n){
	bs.set ();
    //prime.pb(2);
	for (int i = 2; i <= n; i++){
		if (bs[i])prime.pb(i);

		for (int j = 0; j<prime.size() && i*prime[j]<=n; j++){
		    bs[i*prime[j]] = 0;
		    if(i%prime[j]==0)break;
		}
	}
}

int main(){
    //IOS
    //freopen("output.txt","w",stdout);
    sieve(20000000);
    vector<pair<int,int> >vec;
    for(int i=0;i<prime.size()-1;i++){
        if(prime[i+1]-prime[i]==2){
            vec.pb({prime[i],prime[i+1]});
        }
    }
    int n;
    while(cin>>n){
        cout<<"("<<vec[n-1].first<<", "<<vec[n-1].second<<")"<<"\n";
    }
}
