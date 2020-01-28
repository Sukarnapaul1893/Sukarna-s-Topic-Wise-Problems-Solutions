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




int main(){
    IOS
    //freopen("output.txt","w",stdout);
    int t;
    cin>>t;

    while(t--){
        ll A,B,C,m;
        cin>>A>>B>>C>>m;
        if(m==1){

            string s;
            ll a,b,c;
            cin>>s>>a>>b>>c;
            if(a==A && b==B && c==C){
                cout<<"POSSIBLE\n";
            }
            else{
                cout<<"IMPOSSIBLE\n";
            }
            continue;
        }
        vector<pair<pair<ll,ll>,ll> >vec1,vec2;
        for(int i=0;i<m/2;i++){
            string s;
            ll a,b,c;
            cin>>s>>a>>b>>c;
            vec1.pb({{a,b},c});
        }
        for(int i=m/2;i<m;i++){
            string s;
            ll a,b,c;
            cin>>s>>a>>b>>c;
            vec2.pb({{a,b},c});
        }

        vector<pair<pair<ll,ll>,ll> >sum1,sum2;
        sum1.pb({{0,0},0});
        sum2.pb({{0,0},0});
        for(int i=0;i<vec1.size();i++){

            int sz = sum1.size();
            for(int j=0;j<sz;j++){
                sum1.pb({{sum1[j].first.first+vec1[i].first.first,sum1[j].first.second+vec1[i].first.second},sum1[j].second+vec1[i].second});
            }

        }
        for(int i=0;i<vec2.size();i++){

            int sz= sum2.size();
            for(int j=0;j<sz;j++){
                sum2.pb({{sum2[j].first.first+vec2[i].first.first,sum2[j].first.second+vec2[i].first.second},sum2[j].second+vec2[i].second});
            }

        }

        bool bl=false;
        map<pair<pair<ll,ll>,ll>,int >mp;
        for(int i=0;i<sum2.size();i++){
            mp[{{sum2[i].first.first,sum2[i].first.second},sum2[i].second}]++;
        }

        for(int i=0;i<sum1.size();i++){

            ll a1= sum1[i].first.first;

            ll b1= sum1[i].first.second;

            ll c1= sum1[i].second;

            if(mp[{{A-a1,B-b1},C-c1}]==1){
                bl=true;
                break;
            }

        }

        if(bl==true){
            cout<<"POSSIBLE\n";
        }
        else{
            cout<<"IMPOSSIBLE\n";
        }
    }
}
