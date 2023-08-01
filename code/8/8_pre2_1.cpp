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

  auto solve = [&]() {
    ints(n);
    lls(k);
    vll a(n);
    for(ll &x : a) cin >> x;
    vpll b(n);
    for(int i = 0; i < n; i++) b[i] = pll(a[i], i);
    sort(all(b));
    cout << max(0LL, k - b[0].x) << ' ';
    ll l = n, r = 0, ans = 0;
    for(int i = 0, j; i < n; i = j) {
      for(j = i + 1; j < n && b[i].x == b[j].x; j++);
      if(i) ans += (r - l + 1) * (min(b[i].x, k) - b[i - 1].x);
      if(b[i].x >= k) break;
      for(int k = i; k < j; k++) {
        l = min(l, b[k].y);
        r = max(r, b[k].y);
      }
    }
    ans += n * max(0LL, k - b.back().x);
    cout << ans << '\n';
  };

  ints(tc);
  for(int i = 1; i <= tc; i++) {
    cout << "Case #" << i << '\n';
    solve();
  }

  return 0;
}