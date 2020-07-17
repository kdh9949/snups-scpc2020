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

using dijk = pair<pii, int>;

void solve() {
  int n, m, k;
  cin >> n >> m >> k;

  vector<vpii> e(n + 1);
  for(int i = 0; i < m; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    e[x].emplace_back(y, z);
    e[y].emplace_back(x, z);
  }

  vint v(k);
  for(int &x : v) cin >> x;

  priority_queue<dijk, vector<dijk>, greater<dijk>> pq;
  vpii d(n + 1, pii(int(2e9), 0));
  for(int &x : v) {
    d[x] = pii(0, x);
    pq.emplace(d[x], x);
  }

  while(!pq.empty()) {
    dijk c = pq.top();
    pq.pop();
    if(c.x != d[c.y]) continue;

    for(pii &i : e[c.y]) {
      pii nd = pii(c.x.x + i.y, c.x.y);
      if(d[i.x] > nd) {
        d[i.x] = nd;
        pq.emplace(nd, i.x);
      }
    }
  }

  ll vsum = 0, dsum = 0;
  for(int i = 1; i <= n; i++) {
    dsum += d[i].x;
    vsum += d[i].y;
  }
  cout << dsum << '\n' << vsum << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;
  for(int i = 1; i <= tc; i++) {
    cout << "Case #" << i << "\n";
    solve();
  }

  return 0;
}