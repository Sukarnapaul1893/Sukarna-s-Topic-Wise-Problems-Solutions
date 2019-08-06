#pragma warning(disable:4786)
#pragma warning(disable:4996)
#include<bits/stdc++.h>
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
#define MAX 1000005
#define INF 0x3f3f3f3f
template <class T> inline T bigmod(T p,T e,T M){ll ret = 1LL;for(; e > 0LL; e >>= 1LL){if(e & 1LL) ret = (ret * p) % M;p = (p * p) % M;}return (T)ret;}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}   // M is prime}
using namespace std;

int TRIE[MAX][26];
int tot;
bool endnode[MAX];
map<int,int>mp;
void insert(string s){
    int p=1;

    for(int i=0;i<s.length();i++){
        int temp = s[i]-'a';
        if(TRIE[p][temp]==0){
            TRIE[p][temp]=++tot;
        }
        mp[TRIE[p][temp]]++;
        p = TRIE[p][temp];
    }
}
int check(string s){
    int p=1;

    for(int i=0;i<s.length();i++){
        int temp = s[i]-'a';
        if(TRIE[p][temp]==0){
            return 0;
        }
        else if(i==s.length()-1){
            return mp[TRIE[p][temp]];
        }
        p = TRIE[p][temp];
    }
}
bool cmp(string s1, string s2){
    return s1.length()<s2.length();
}

int main(){
    IOS
    //freopen("output.txt","w",stdout);

    tot=1;
    memset(TRIE,0,sizeof TRIE);
    memset(endnode,0,sizeof endnode);
    int n,q;
    cin>>n>>q;
    string s[n];
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    sort(s,s+n,cmp);


    for(int i=0;i<n;i++){
        insert(s[i]);

    }

    for(int i=0;i<q;i++){
        string st;
        cin>>st;
        cout<<check(st)<<"\n";
    }


}
