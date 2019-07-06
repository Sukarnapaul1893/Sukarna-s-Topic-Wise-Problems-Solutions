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
typedef tree<pair<ll,int>,null_type,less<pair<ll,int> >,rb_tree_tag,tree_order_statistics_node_update>ordered_set;


int main(){
	IOS
	//freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    vector<pair<pair<ll,ll> ,int> >vec;
    ll l[n],r[n];
    for(int i=0;i<n;i++){

        cin>>l[i]>>r[i];
        vec.pb({{--l[i],--r[i]},i});
    }

    sort(vec.begin(),vec.end());


    ordered_set st;
    for(int i=0;i<n;i++){
        st.insert({vec[i].first.second,vec[i].second});
    }


    int cur=1;
    ll ans[n];
    memset(ans,-1,sizeof ans );
    map<ll,int>mp;
    for(int i=0;i<n;i++){
        if(ans[vec[i].second]!=-1)continue;
        cur=l[vec[i].second];
        int idx = vec[i].second;
        int x = st.order_of_key({vec[i].first.second,vec[i].second});
        if(x==0){
            ans[idx] = cur;
            while(mp[ans[idx]]>0){
                ans[idx]++;
            }
            mp[ans[idx]]++;
            st.erase({vec[i].first.second,vec[i].second});
        }
        else{
            auto it = st.begin();
            int idx = (*it).second;
            ans[idx] = l[idx];
            while(mp[ans[idx]]>0){
                ans[idx]++;
            }
            mp[ans[idx]]++;
            st.erase({r[idx],idx});
            i--;
        }
    }

    for(int i=0;i<n;i++){
        cout<<ans[i]+1;
        if(i!=n-1){
            cout<<" ";
        }
    }
}
