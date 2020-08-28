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
  int n;
  cin >> n;

  vector<vpii> e(n + 1);
  for(int i = 0; i < n - 1; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    e[x].emplace_back(y, z);
    e[y].emplace_back(x, z);
  }

  int k;
  cin >> k;

  auto f = [&](ll x) {
    queue<int> q;
    vll d(n + 1);
    vint deg(n + 1), vis(n + 1);
    for(int i = 1; i <= n; i++) {
      deg[i] = e[i].size();
      if(deg[i] == 1) q.push(i);
    }

    int cnt = n;
    while(!q.empty()) {
      int c = q.front();
      q.pop();
      for(pii &p : e[c]) {
        if(vis[p.x]) continue;
        if(d[c] + p.y > x) break;
        d[p.x] = max(d[p.x], d[c] + p.y);
        cnt--;
        vis[c] = 1;
        if(--deg[p.x] == 1) q.push(p.x);
      }
    }
    return (cnt <= k);
  };

  ll l = 0, r = ll(1e18);
  while(l < r) {
    ll m = (l + r) / 2;
    if(f(m)) r = m;
    else l = m + 1;
  }
  cout << l << '\n';
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