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
  int n, k, m;
  cin >> n >> k >> m;

  int v = n + 4 * k;
  vint lst(n);
  iota(all(lst), 0);
  vector<vpii> e(v);

  for(int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    int xn = n + 4 * i, yn = n + 4 * i + 2;
    e[lst[x]].emplace_back(xn, 0);
    e[lst[y]].emplace_back(yn, 0);
    e[xn].emplace_back(xn + 1, 1);
    e[xn].emplace_back(yn + 1, 0);
    e[yn].emplace_back(xn + 1, 0);
    e[yn].emplace_back(yn + 1, 1);
    lst[x] = xn + 1;
    lst[y] = yn + 1;
  }

  vector<vint> qry(n);
  for(int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    qry[x - 1].push_back(y - 1);
  }

  vint d(v);
  deque<int> dq;
  int ans = 0;
  for(int i = 0; i < n; i++) {
    fill(all(d), v + 1);
    d[i] = 0;
    dq.push_back(i);

    while(!dq.empty()) {
      int x = dq.front();
      dq.pop_front();

      for(const pii &p : e[x]) {
        if(d[p.x] <= d[x] + p.y) continue;
        d[p.x] = d[x] + p.y;
        if(p.y) dq.push_back(p.x);
        else dq.push_front(p.x);
      }
    }

    for(int j : qry[i]) ans += (d[lst[j]] > v ? -1 : d[lst[j]]);
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