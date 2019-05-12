#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int MAXN = 1e5 + 7;
const int maxl = 21;

int tin[MAXN], tout[MAXN], depth[MAXN], up[MAXN][maxl];
int timer = 1;
vector<int> v[MAXN], adj[MAXN];

void dfs(int u, int p) {
  tin[u] = timer++;
  depth[u] = depth[p] + 1;
  v[depth[u]].pb(tin[u]);
  up[u][0] = p;
  for (int i = 1; i < maxl; i++) {
    up[u][i] = up[up[u][i-1]][i-1];
  }
  for (int v : adj[u]) {
    if (v != p) {
      dfs(v, u);
    }
  }
  tout[u] = timer++;
}

int get(int u, int p) {
  int curr = u;
  for (int i = maxl - 1; i >= 0; i--) {
    if ((1 << i) <= p) {
      p -= (1 << i);
      u = up[u][i];
    }
  }
  return u;
}

int query(int u, int pth) {
  int low = lower_bound(v[depth[u]].begin(), v[depth[u]].end(), tin[pth]) - v[depth[u]].begin();
  int up = upper_bound(v[depth[u]].begin(), v[depth[u]].end(), tout[pth]) - v[depth[u]].begin();
  return up - low - 1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin>>x;
    if (x != 0) {
      adj[x].pb(i);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (tin[i] == 0) {
      dfs(i, 0);
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int u, p;
    cin>>u>>p;
    if (depth[u] <= p) {
      cout << "0 ";
    }
    else {
      int pth = get(u, p);
      cout << query(u, pth) << ' ';
    }
  }
  return 0;
}
