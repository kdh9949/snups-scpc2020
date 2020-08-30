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

  struct Edge { int x, y; ll c; };
  vector<Edge> edges(m);
  vector<vpil> e(n + 1);
  for(Edge &u : edges) {
    cin >> u.x >> u.y >> u.c;
    e[u.x].emplace_back(u.y, u.c);
    e[u.y].emplace_back(u.x, u.c);
  }

  const static ll INF = ll(1e18);
  vector<vpil> te(n + 1);
  vll d(n + 1, INF);
  {
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    d[1] = 0;
    pq.emplace(0LL, 1);
    while(!pq.empty()) {
      pli c = pq.top();
      pq.pop();
      if(c.x != d[c.y]) continue;
      for(pil &p : e[c.y]) {
        if(d[p.x] > c.x + p.y) {
          d[p.x] = c.x + p.y;
          pq.emplace(d[p.x], p.x);
        }
      }
    }
  }
  for(int i = 1; i <= n; i++) {
    for(pil &p : e[i]) {
      if(d[p.x] == d[i] + p.y) {
        te[i].push_back(p);
        te[p.x].emplace_back(i, p.y);
      }
    }
  }

  vint subn(n + 1);
  {
    function<void(int, int, int)> f = [&](int x, int y, int c) {
      subn[x] = c;
      for(pil &p : te[x]) if(p.x != y) f(p.x, x, c);
    };
    for(pil &p : te[1]) f(p.x, 1, p.x);
  }

  vll cnt(n + 1), depsum(n + 1);
  {
    function<void(int, int)> f = [&](int x, int y) {
      depsum[x] = d[x];
      cnt[x] = 1;
      for(pil &p : te[x]) if(p.x != y) {
        f(p.x, x);
        depsum[x] += depsum[p.x];
        cnt[x] += cnt[p.x];
      }
    };
    f(1, 0);
  }

  vint nearest(n + 1);
  vll nearsum(n + 1), distsum(n + 1);
  {
    vint stk;
    vll wprefix, wingsum(n + 1);
    function<void(int, int)> f = [&](int x, int y) {
      stk.push_back(x);
      {
        int l = 0, r = int(stk.size()) - 1;
        while(l < r) {
          int m = (l + r) / 2;
          if(d[stk[m]] < d[x] - d[stk[m]]) l = m + 1;
          else r = m;
        }
        nearest[x] = stk[l];
        nearsum[x] = distsum[x] - wprefix[l]
          - (cnt[subn[x]] - cnt[nearest[x]]) * d[x];
      }
      for(pil &p : te[x]) if(p.x != y) {
        distsum[p.x] = distsum[x] + (cnt[subn[x]] - 2 * cnt[p.x]) * p.y;
        wingsum[x] = depsum[x] - depsum[p.x] - 2 * (cnt[x] - cnt[p.x]) * d[x];
        wprefix.push_back(wprefix.back() + wingsum[x]);
        f(p.x, x);
        wprefix.pop_back();
      }
      
      stk.pop_back();
    };

    wprefix.push_back(0LL);
    for(pil &p : te[1]) {
      distsum[p.x] = nearsum[p.x] = depsum[p.x] - cnt[p.x] * d[p.x];  
      f(p.x, 1);
    }
  }

  ll ans = -INF;
  for(Edge &u : edges) {
    if(!subn[u.x] || !subn[u.y] || subn[u.x] == subn[u.y]) continue;
    int xnear = nearest[u.x], ynear = nearest[u.y];
    int xsub = subn[u.x], ysub = subn[u.y];
    ll bef =
      depsum[xnear] * (n - cnt[xsub])
      + (depsum[1] - depsum[xsub]) * cnt[xnear]
      + depsum[ynear] * (n - cnt[ysub])
      + (depsum[1] - depsum[ysub]) * cnt[ynear];
    ll aft =
      nearsum[u.x] * (n - cnt[xsub])
      + u.c * cnt[xnear] * (n - cnt[xsub])
      + distsum[u.y] * cnt[xnear]
      + d[u.y] * (n - cnt[ysub] - cnt[xsub]) * cnt[xnear]
      + (depsum[1] - depsum[ysub] - depsum[xsub]) * cnt[xnear]
      + nearsum[u.y] * (n - cnt[ysub])
      + u.c * cnt[ynear] * (n - cnt[ysub])
      + distsum[u.x] * cnt[ynear]
      + d[u.x] * (n - cnt[xsub] - cnt[ysub]) * cnt[ynear]
      + (depsum[1] - depsum[xsub] - depsum[ysub]) * cnt[ynear];
    ans = max(ans, bef - aft);
  }
  cout << ans << '\n';
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