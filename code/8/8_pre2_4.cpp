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
#define all(v) (v).begin(),(v).end()
#define ints(args...) int args; readln(args);
#define lls(args...) ll args; readln(args);
#define strs(args...) string args; readln(args);

template<typename... Args>
void readln(Args&... args) { ((cin >> args), ...); }
template<typename... Args>
void writeln(Args... args) { ((cout << args << " "), ...); cout << '\n'; }

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);

  using Dat = pair<pii, int>;
  struct Seg {
    vector<Dat> d;
    vpii l;
    int sz;
    Dat mrg(Dat a, Dat b) {
      if(a.x == b.x) a.y += b.y;
      return a.x <= b.x ? a : b;
    }
    void add(pii &p, pii v) {
      p.x += v.x;
      p.y += v.y;
    }
    void i(int n) {
      for(sz = 1; sz <= n; sz *= 2);
      d = vector<Dat>(2 * sz, Dat(pii(0, 0), 1));
      for(int i = sz + n; i < 2 * sz; i++) { d[i].x.x = 4; d[i].y = 0; }
      for(int i = sz - 1; i; i--) d[i] = mrg(d[2 * i], d[2 * i + 1]);
      l = vpii(2 * sz);
    }
    void u(int s, int e, pii v, int x, int p, int q) {
      if(e < p || q < s) return;
      if(s <= p && q <= e) {
        add(d[x].x, v);
        add(l[x], v);
        return;
      }
      add(d[2 * x].x, l[x]);
      add(d[2 * x + 1].x, l[x]);
      add(l[2 * x], l[x]);
      add(l[2 * x + 1], l[x]);
      l[x] = pii(0, 0);
      u(s, e, v, 2 * x, p, (p + q) / 2);
      u(s, e, v, 2 * x + 1, (p + q) / 2 + 1, q);
      d[x] = mrg(d[2 * x], d[2 * x + 1]);
    }
    void u(int s, int e, pii v) { u(s, e, v, 1, 1, sz); }
    int g() { return d[1].y; }
  } S;

  auto solve = [&]() {
    ints(n);
    vector<vint> a(n + 2, vint(n + 2));
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) cin >> a[i][j];

    vector<vector<pair<pii, pii>>> ev(n * n + 2);
    auto add_rect = [&](int x, int y, int z, int w, pii p) {
      if(x > y || z > w) return;
      ev[x].emplace_back(pii(z, w), p);
      ev[y + 1].emplace_back(pii(z, w), pii(-p.x, -p.y));
    };

    for(int i = 0; i <= n; i++) {
      for(int j = 0; j <= n; j++) {
        vint v = {0, a[i][j], a[i][j + 1], a[i + 1][j], a[i + 1][j + 1], n * n + 1};
        sort(all(v));
        for(int i = 1; i <= 4; i++) add_rect(v[i - 1] + 1, v[i], v[i], v[i + 1] - 1, pii(1, 0));
        for(int i = 1; i <= 2; i++) add_rect(v[i - 1] + 1, v[i], v[i + 2], v[i + 3] - 1, pii(0, 1));
      }
    }

    S.i(n * n);    
    ll ans = 0;
    for(int i = 1; i <= n * n; i++) {
      for(auto &[p, q] : ev[i]) S.u(p.x, p.y, q);
      ans += S.g();
      S.u(i, i, pii(5, 0));
    }
    cout << ans << '\n';
  };

  ints(tc);
  for(int i = 1; i <= tc; i++) {
    cout << "Case #" << i << '\n';
    solve();
  }

  return 0;
}