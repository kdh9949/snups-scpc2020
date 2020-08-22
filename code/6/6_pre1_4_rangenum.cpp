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
  const int N = 524288;
  int sz;
  int d[2 * N], l[2 * N];

  void init(int n) {
    sz = 1;
    while(sz <= n) sz *= 2;
    fill(d, d + 2 * sz, 0);
    fill(l, l + 2 * sz, 0);
  }

  void z(int x) {
    l[2 * x] += l[x];
    d[2 * x] += l[x];
    l[2 * x + 1] += l[x];
    d[2 * x + 1] += l[x];
    l[x] = 0;
  }

  void u(int x, int p, int q, int s, int e, int v) {
    if(q < s || e < p) return;
    if(s <= p && q <= e) {
      l[x] += v;
      d[x] += v;
      return;
    }
    z(x);
    u(2 * x, p, (p + q) / 2, s, e, v);
    u(2 * x + 1, (p + q) / 2 + 1, q, s, e, v);
    d[x] = max(d[2 * x], d[2 * x + 1]);
  }

  void u(int s, int e, int v) { u(1, 0, sz - 1, s, e, v); }

  int g() { return d[1]; }
};

void solve() {
  int n, k, m;
  string s;
  cin >> n >> k >> m >> s;

  auto num = [&](int i) {
    int r = 0;
    for(int j = k - 1, t = 1; j >= 0; j--, t *= 10) {
      r += t * (s[i + j] - '0');
    }
    return r;
  };

  vint v;
  for(int i = 0; i <= n - k; i++) v.push_back(num(i));

  vector<vint> ov(n), iv(n);
  vint tot = v;
  for(int i = 0; i < n; i++) {
    if(s[i] == '1') continue;
    for(int j = 0; j < k && i - j >= 0; j++)
      if(i - j <= n - k) ov[i].push_back(v[i - j]);
    char os = s[i];
    s[i] = '1';
    for(int j = 0; j < k && i - j >= 0; j++)
      if(i - j <= n - k) iv[i].push_back(num(i - j));
    s[i] = os;
    for(int x : iv[i]) tot.push_back(x);
  }

  sort(all(tot));
  tot.erase(unique(all(tot)), tot.end());

  auto upd = [&](int x, int v) {
    int s = int(lower_bound(all(tot), x) - tot.begin());
    int e = int(upper_bound(all(tot), x + m) - tot.begin()) - 1;
    Seg::u(s, e, v);
  };

  Seg::init(tot.size());
  for(int x : v) upd(x, 1);

  int ans = Seg::g();
  for(int i = 0; i < n; i++) {
    for(int x : ov[i]) upd(x, -1);
    for(int x : iv[i]) upd(x, 1);
    ans = max(ans, Seg::g());
    for(int x : ov[i]) upd(x, 1);
    for(int x : iv[i]) upd(x, -1);
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