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

using po = pair<pll, ld>;

namespace Seg {
  const int N = 262144;
  int sz;
  ld d[2 * N];

  void init(int n) {
    sz = 1;
    while(sz <= n) sz *= 2;
    fill(d, d + 2 * sz, 0);
  }

  void u(int x, ld v) {
    d[x += sz] = v;
    for(x /= 2; x; x /= 2) d[x] = d[2 * x] * d[2 * x + 1];
  }

  ld g(int s, int e) {
    ld r = 1;
    for(s += sz, e += sz; s <= e; s /= 2, e /= 2) {
      if(s & 1) r *= d[s++];
      if(~e & 1) r *= d[e--];
    }
    return r;
  }
};

void solve() {
  int n;
  cin >> n;

  vector<po> v(n);
  for(po &p : v) cin >> p.x.x;
  for(po &p : v) cin >> p.x.y;
  for(po &p : v) cin >> p.y;

  pll ori;
  cin >> ori.x >> ori.y;
  for(po &p : v) { p.x.x -= ori.x; p.x.y -= ori.y; }

  auto ccw = [](const pll &p, const pll &q) {
    ll t = p.x * q.y - q.x * p.y;
    return (t > 0) - (t < 0);
  };
  const static pll O(0LL, 0LL);
  sort(all(v), [&](const po &p, const po &q){
    if((p.x < O) == (q.x < O)) return ccw(p.x, q.x) > 0;
    return p.x < q.x;
  });
  for(int i = 0; i < n; i++) v.push_back(v[i]);

  Seg::init(2 * n);
  for(int i = 0; i < 2 * n; i++) Seg::u(i, 1 - v[i].y);

  ld ans = Seg::g(0, n - 1);
  for(int i = n, j = 1; i < 2 * n; i++) {
    while(ccw(v[i].x, v[j].x) > 0) j++;
    ans += v[i].y * Seg::g(j, i - 1);
  }

  cout << (1 - ans) << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(12);

  int tc;
  cin >> tc;
  for(int i = 1; i <= tc; i++) {
    cout << "Case #" << i << '\n';
    solve();
  }

  return 0;
}