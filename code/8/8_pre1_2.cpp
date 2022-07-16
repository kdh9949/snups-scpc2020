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

const int N = 500005;
const ll M = ll(1e9) + 7;
ll fa[N], ifa[N];  

ll inv(ll x) {
  ll r = 1;
  for(ll k = M - 2; k; k /= 2, x = x * x % M)
    if(k & 1) r = r * x % M;
  return r;
};

ll bino(int n, int r) {
  if(n < 0 || r < 0 || r > n) return 0LL;
  return fa[n] * ifa[r] % M * ifa[n - r] % M;
};

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);

  fa[0] = 1;
  for(int i = 1; i < N; i++) fa[i] = fa[i - 1] * i % M;
  for(int i = 0; i < N; i++) ifa[i] = inv(fa[i]);

  auto solve = [&]() {
    ints(n, k);
    vll a(n + 1), s(n + 1);
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
      s[i] = s[i - 1] + a[i];
    }
    if(s[n] % k) { cout << "0\n"; return; }
    ll m = s[n] / k;
    if(m == 0) {
      int cnt = 0;
      for(int i = 1; i < n; i++) if(s[i] == 0) cnt++;
      cout << bino(cnt, k - 1) << '\n';
      return;
    }
    vll d(k + 1);
    d[0] = 1;
    for(int i = 1; i <= n; i++) {
      if(s[i] % m) continue;
      int idx = s[i] / m;
      if(1 <= idx && idx <= k) {
        if(i == n) { cout << d[idx - 1] << '\n'; }
        d[idx] += d[idx - 1];
        d[idx] %= M;
      }
    }
  };

  ints(tc);
  for(int i = 1; i <= tc; i++) {
    cout << "Case #" << i << '\n';
    solve();
  }

  return 0;
}