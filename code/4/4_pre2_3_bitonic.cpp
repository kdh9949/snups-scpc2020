#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

using vint = vector<int>;
using vll = vector<ll>;
using vld = vector<ld>;
using vpii = vector<pii>;
using vpil = vector<pil>;
using vpli = vector<pli>;
using vpll = vector<pll>;

#define x first
#define y second
#define all(v) v.begin(),v.end()

void solve() {
  int n, m;
  cin >> n >> m;

  const static int K = 200005;
  vector<vpii> edges(K);
  for(int i = 0; i < m; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    edges[z].emplace_back(x, y);
  }
  
  const static ll INF = ll(1e18);  
  vll ds(n + 1), de(n + 1);
  auto f = [&](vll &d, int st) {
    fill(all(d), INF);
    d[st] = 0;
    vector<vint> e(n + 1);
    vint c(n + 1);
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    for(int t = 1; t < K; t++) {
      for(pii &p : edges[t]) {
        e[p.x].push_back(p.y);
        e[p.y].push_back(p.x);
        if(!c[p.x]) { c[p.x] = 1; pq.emplace(d[p.x], p.x); }
        if(!c[p.y]) { c[p.y] = 1; pq.emplace(d[p.y], p.y); }
      }

      while(!pq.empty()) {
        pli c = pq.top();
        pq.pop();
        if(c.x != d[c.y]) continue;
        for(int i : e[c.y]) {
          if(d[i] > c.x + t) {
            d[i] = c.x + t;
            pq.emplace(d[i], i);
          }
        }
      }

      for(pii &p : edges[t]) {
        if(c[p.x]) { c[p.x] = 0; e[p.x].clear(); }
        if(c[p.y]) { c[p.y] = 0; e[p.y].clear(); }
      }
    }
  };
  f(ds, 1);
  f(de, n);

  ll r = INF;
  for(int i = 1; i <= n; i++) r = min(r, ds[i] + de[i]);
  if(r == INF) r = -1;
  cout << r << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;
  for(int i = 1; i <= tc; i++) {
    cout << "Case #" << i << '\n';
    solve();
  }

  return 0;
}