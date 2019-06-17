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




int main(){
    //IOS
    //freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    string s[n][2];
    for(int i=0;i<n;i++){
        cin>>s[i][0]>>s[i][1];

    }
    for(int i=0;i<n;i++){
        if(s[i][0].length()<50){
            for(int j=0;j<50-s[i][0].length();j++){
                s[i][0]=s[i][0]+"0";
            }
        }

        if(s[i][1].length()<50){
            for(int j=0;j<50-s[i][1].length();j++){
                s[i][1]=s[i][1]+"0";
            }
        }

    }
    int order[n];
    bool bl = true;
    string prev;
    for(int i=0;i<n;i++){
        cin>>order[i];
        if(bl==false)continue;
        order[i]--;
        if(i==0){
            if(s[order[i]][0]>=s[order[i]][1]){
                prev = s[order[i]][1];
            }
            else{
                prev = s[order[i]][0];
            }

        }
        if(i>0){
            if(s[order[i]][0]>=prev){
                if(s[order[i]][1]>=prev){
                    if(s[order[i]][0]>=s[order[i]][1]){
                        prev = s[order[i]][1];
                    }
                    else{
                        prev = s[order[i]][0];
                    }
                    continue;
                }
                else{
                    prev = s[order[i]][0];
                    continue;
                }

            }
            if(s[order[i]][1]>=prev){
                prev = s[order[i]][1];
                continue;
            }

            bl=false;
        }
    }
    if(bl==false){
        cout<<"NO";
    }
    else{
        cout<<"YES";
    }
}
