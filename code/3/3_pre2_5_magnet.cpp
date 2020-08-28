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

const ll INF = ll(1e18);

namespace Seg {
  int sz;
  vll d;
  
  void i(int n) {
    for(sz = 1; sz <= n; sz *= 2);
    d = vll(2 * sz, INF);
  }

  void u(int x, ll v) {
    d[x += sz] = v;
    for(x /= 2; x; x /= 2) d[x] = min(d[2 * x], d[2 * x + 1]);
  }

  ll g(int s, int e) {
    ll r = INF;
    for(s += sz, e += sz; s <= e; s /= 2, e /= 2) {
      if(s & 1) r = min(r, d[s++]);
      if(~e & 1) r = min(r, d[e--]);
    }
    return r;
  }
}

void solve() {
  int n;
  cin >> n;

  struct Bar { int s, e, c; };
  vector<Bar> v(n);
  for(Bar &b : v) cin >> b.s >> b.e >> b.c;
  sort(all(v), [](const Bar &a, const Bar &b) {
    return pii(a.s, -a.e) > pii(b.s, -b.e);
  });

  vint sp, ep;
  for(Bar &b : v) {
    if(!ep.empty() && ep.back() <= b.e) continue;
    sp.push_back(b.s);
    ep.push_back(b.e);
  }
  reverse(all(sp));
  reverse(all(ep));
 
  int m = sp.size(); 
  vector<vpii> w(m + 1);
  for(Bar &b : v) {
    int s = int(lower_bound(all(ep), b.s) - ep.begin()) + 1;
    int e = int(upper_bound(all(sp), b.e) - sp.begin());
    w[e].emplace_back(s, b.c);
  }

  vll d(m + 1);
  Seg::i(m);
  Seg::u(0, 0);
  for(int i = 1; i <= m; i++) {
    d[i] = INF;
    for(pii &p : w[i]) d[i] = min(d[i], Seg::g(p.x - 1, i - 1) + p.y);
    Seg::u(i, d[i]);
  }
  cout << d[m] << '\n';
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