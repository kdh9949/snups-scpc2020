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
  vint d;
  
  void i(int n, int iv) {
    for(sz = 1; sz <= n; sz *= 2);
    d = vint(2 * sz, iv);
  }

  void u(int x, int v) {
    d[x += sz] = v;
    for(x /= 2; x; x /= 2) d[x] = min(d[2 * x], d[2 * x + 1]);
  }

  int g(int s, int e) {
    int r = d[0];
    for(s += sz, e += sz; s <= e; s /= 2, e /= 2) {
      if(s & 1) r = min(r, d[s++]);
      if(~e & 1) r = min(r, d[e--]);
    }
    return r;
  }
}

void solve() {
  int l, n;
  cin >> l >> n;

  struct Pos { pii p; int i, ans; };
  vector<Pos> a(n);
  vint xs(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i].p.x >> a[i].p.y;
    xs[i] = a[i].p.x - a[i].p.y;
  }
  sort(all(xs));
  for(int i = 0; i < n; i++) {
    a[i].i = int(lower_bound(all(xs), a[i].p.x - a[i].p.y) - xs.begin()) + 1;
  }

  sort(all(a), [&](Pos &a, Pos &b){
    return a.p.x == b.p.x ? a.p.y < b.p.y : a.p.x > b.p.x;
  });
  Seg::i(n, l);
  for(Pos &x : a) {
    x.ans = Seg::g(1, x.i) - x.p.y;
    Seg::u(x.i, x.p.y);
  }

  sort(all(a), [&](Pos &a, Pos &b){
    return a.p.y == b.p.y ? a.p.x < b.p.x : a.p.y > b.p.y;
  });
  Seg::i(n, l);
  for(Pos &x : a) {
    x.ans = min(x.ans, Seg::g(x.i, n) - x.p.x);
    Seg::u(x.i, x.p.x);
  }

  ll tot = 0;
  for(Pos &x : a) tot += x.ans;
  cout << tot << '\n';
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