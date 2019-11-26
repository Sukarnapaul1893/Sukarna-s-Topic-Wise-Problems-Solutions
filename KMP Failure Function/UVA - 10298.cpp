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
#define MAX 1000005
#define INF 0x3f3f3f3f
#define mset(a,b) memset(a,b,sizeof(a))
template <class T> inline T bigmod(T p,T e,T M){ll ret = 1LL;for(; e > 0LL; e >>= 1LL){if(e & 1LL) ret = (ret * p) % M;p = (p * p) % M;}return (T)ret;}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}   // M is prime}
using namespace std;
using namespace __gnu_pbds;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

int failure[MAX];

void build_failure_function(string pattern, int m) {
  failure[0] = 0;
  failure[1] = 0; //base case

  for(int i = 2; i <= m; i++) {  //i is length of the prefix we are dealing with
    // j is the index of the largest next partial match
    // (the largest suffix/prefix) of the string under index i - 1
    int j = failure[i - 1];
    while(true) {
      // check if the last character of prefix of length i "expands" the current "candidate"
      if(pattern[j] == pattern[i - 1]) {
        failure[i] = j + 1;
        break;
      }
      // if we cannot "expand" even the empty string
      if(j == 0) {
          failure[i] = 0;
          break;
      }
      // else go to the next best "candidate" partial match
      j = failure[j];
    }
  }
}

int main(){
	IOS
	//freopen("output.txt","w",stdout);
    string s;

    while(cin>>s){

        if(s==".")break;
        build_failure_function(s, s.length());
        //for(int i=1;i<=s.length();i++)cout<<failure[i]<<"\n";

        set<int>st;
        int ans = 0;

        ans = failure[s.length()];
        //cout<<ans<<"\n";
        bool bl=true;
        if(failure[s.length()]==0){
            cout<<1<<"\n";
            continue;
        }
        for(int i=s.length();i>=1;i--){
            if(failure[i]!=ans){
                if(ans==0){
                    if(s.length()%i==0){
                        cout<<s.length()/i<<"\n";
                        bl=false;
                        break;
                    }
                }

            }
            else if(ans==0){
                if(s.length()%i==0){
                    bl=false;
                    cout<<s.length()/i<<"\n";
                    break;
                }
            }
            ans--;
        }
        if(bl){
            cout<<1<<"\n";
        }
    }
}
