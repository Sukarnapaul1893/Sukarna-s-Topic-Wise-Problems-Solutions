#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ll, ll> pll;

const ll MAXN = ll(5e5) + 10;
const ll INF = ll(1e17);
const ll MOD = ll(1e9) + 7;
const ld PI = 3.141;

ll n, m, s, a[MAXN], l, r;
pair<pll, ll>q[MAXN];
ll pl, pr, pans;
ll cnt[ll(1e6) + 2];
ll ans[MAXN];

void Move(ll l, ll r){
    if(pl < l){
        for(ll i = pl; i < l; ++i){
            if(cnt[a[i]]==1){
                pans--;
            }
            cnt[a[i]]--;

        }
    }
    if(l < pl){
        for(ll i = l; i < pl; ++i){
            if(cnt[a[i]]==0){
                pans++;
            }

            cnt[a[i]]++;

        }
    }
    if(r < pr){
        for(ll i = r + 1; i <= pr; ++i){
            if(cnt[a[i]]==1){
                pans--;
            }
            cnt[a[i]]--;
        }
    }
    if(r > pr){
        for(ll i = pr + 1; i <= r; ++i){
            if(cnt[a[i]]==0){
                pans++;
            }
            cnt[a[i]]++;

        }
    }
    pl = l, pr = r;
}

bool Comp(pair<pll, ll>a, pair<pll, ll>b){
    if(a.first.first / s != b.first.first / s){
        return (a.first.first / s < b.first.first / s);
    }
    return a.first.second > b.first.second;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    s = (ll)sqrt(1.0*n);
    for(ll i = 1; i <= n; ++i){
        cin>>a[i];
    }
    cin>>m;
    for(ll i = 1; i <= m; ++i){
        cin>>l>>r;
        q[i].first.first = l;
        q[i].first.second = r;
        q[i].second = i;
    }
    sort(q + 1, q + 1 + m, Comp);
    pl = 0, pr = 0;
    for(ll i = 1; i <= m; ++i){
        Move(q[i].first.first, q[i].first.second);
        ans[q[i].second] = pans;
    }
    for(ll i = 1; i <= m; ++i){
        cout<<ans[i]<<"\n";
    }
    return 0;
}
