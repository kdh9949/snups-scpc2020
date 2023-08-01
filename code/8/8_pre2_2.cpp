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

  struct Fen {
    vint v;
    int n;
    void i(int n) { this->n = n; v = vint(n + 1); }
    void u(int x) { for(; x <= n; x += x & -x) v[x]++; }
    int g(int x) { int r = 0; for(; x; x &= x - 1) r += v[x]; return r; }
    int g(int s, int e) { return g(e) - g(s - 1); }
  } F;

  auto solve = [&]() {
    ints(n);
    vint a(n);
    for(int &x : a) cin >> x;
    vector<vint> p(n + 1);
    for(int i = 1; i <= n; i++) p[a[i - 1]].push_back(i);

    ll ans = 0;
    vint pv(n + 1);
    vpii qv(n + 1);
    for(int i = 1; i <= n; i++) {
      for(int j = 0, k = int(p[i].size()) - 1; j < k; j++, k--) {
        ans += p[i][k] - p[i][j];
        pv[p[i][k]] = p[i][j];
        qv[p[i][k]] = pii(p[i][j], p[i][k]);
      }
    }
    F.i(n);
    for(int i = n; i >= 1; i--) {
      if(qv[i].x) ans -= F.g(qv[i].x, qv[i].y);
      if(pv[i]) F.u(pv[i]);
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