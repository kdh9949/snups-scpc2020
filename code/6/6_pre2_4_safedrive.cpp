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
  int sz;
  vll l, d;

  void i(int n) {
    for(sz = 1; sz <= n; sz *= 2);
    l = vll(2 * sz);
    d = vll(2 * sz);
  }

  void spr(int x) {
    l[2 * x] += l[x];
    d[2 * x] += l[x];
    l[2 * x + 1] += l[x];
    d[2 * x + 1] += l[x];
    l[x] = 0;
  }

  void u(int s, int e, ll v, int x, int p, int q) {
    if(e < p || q < s) return;
    if(s <= p && q <= e) {
      l[x] += v;
      d[x] += v;
      return;
    }
    spr(x);
    u(s, e, v, 2 * x, p, (p + q) / 2);
    u(s, e, v, 2 * x + 1, (p + q) / 2 + 1, q);
    d[x] = max(d[2 * x], d[2 * x + 1]);
  }
  void u(int s, int e, ll v) { u(s, e, v, 1, 0, sz - 1); }

  ll g(int s, int e, int x, int p, int q) {
    if(e < p || q < s) return 0;
    if(s <= p && q <= e) return d[x];
    spr(x);
    return max(
      g(s, e, 2 * x, p, (p + q) / 2),
      g(s, e, 2 * x + 1, (p + q) / 2 + 1, q)
    );
  }
  ll g(int s, int e) { return g(s, e, 1, 0, sz - 1); }
}

void solve() {
  int a, b, c;
  cin >> a >> b >> c;

  vll ax(a), ay(a + 1), bx(b), by(b + 1), cx(c), cy(c + 1), y(1);
  auto input = [](int n, vll &x, vll &y, vll &ty) {
    for(int i = 0; i < n; i++) {
      cin >> x[i] >> y[i + 1];
      if(i) x[i] += x[i - 1];
      y[i + 1] += y[i];
      ty.push_back(y[i + 1]);
    }
  };
  input(a, ax, ay, y);
  input(b, bx, by, y);
  input(c, cx, cy, y);
  sort(all(y));
  y.erase(unique(all(y)), y.end());

  int n = int(y.size()) - 1;
  vll s(n), e(n), x(n), tx;
  for(int i = 0, ap = 0, bp = 0, cp = 0; i < n; i++) {
    if(ap < a - 1 && ay[ap + 1] <= y[i]) ap++;
    if(bp < b - 1 && by[bp + 1] <= y[i]) bp++;
    if(cp < c - 1 && cy[cp + 1] <= y[i]) cp++;
    s[i] = ax[ap];
    e[i] = bx[bp];
    x[i] = cx[cp];
    tx.push_back((s[i] + x[i]) / 2);
    tx.push_back((e[i] + x[i]) / 2); 
  }
  sort(all(tx));
  tx.erase(unique(all(tx)), tx.end());

  ll cur = 0;
  for(int i = 0; i < n; i++) if(s[i] <= x[i] && x[i] <= e[i]) cur += (y[i + 1] - y[i]);
  ll ans = cur;
  Seg::i(tx.size());
  for(int i = n - 1; i >= 0; i--) {
    if(s[i] <= x[i] && x[i] <= e[i]) cur -= (y[i + 1] - y[i]);
    int ts = int(lower_bound(all(tx), (s[i] + x[i]) / 2) - tx.begin());
    int te = int(lower_bound(all(tx), (e[i] + x[i]) / 2) - tx.begin());
    Seg::u(ts, te, y[i + 1] - y[i]);
    if(i && x[i] != x[i - 1]) {
      ts = int(lower_bound(all(tx), min(x[i], x[i - 1])) - tx.begin());
      te = int(upper_bound(all(tx), max(x[i], x[i - 1])) - tx.begin()) - 1;
      ans = max(ans, Seg::g(ts, te) + cur);
    }
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