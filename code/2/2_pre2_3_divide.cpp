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

namespace Seg {
  struct Node { int zero, one, ans; };
  int sz;
  vector<Node> d;

  void i(int n) {
    for(sz = 1; sz <= n; sz *= 2);
    d = vector<Node>(2 * sz);
  }

  Node mrg(const Node &l, const Node &r) {
    return {
      l.zero + r.zero,
      l.one + r.one,
      max(l.zero + r.ans, l.ans + r.one)
    };
  }

  void u(int x, int v) {
    d[x += sz] = {!v, v, 1};
    for(x /= 2; x; x /= 2) d[x] = mrg(d[2 * x], d[2 * x + 1]);
  }
}

void solve() {
  int n;
  cin >> n;

  Seg::i(n);
  vector<vpii> mines(n + 1);
  for(int i = 0; i < n; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    mines[x].emplace_back(y, z);
    Seg::u(y, !z);
  }

  int ans = Seg::d[1].ans;
  for(int i = 1; i <= n; i++) {
    for(pii &p : mines[i]) Seg::u(p.x, p.y);
    ans = max(ans, Seg::d[1].ans);
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