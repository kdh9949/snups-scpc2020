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
    vpii a(n);
    for(int i = 0; i < n; ++i) cin >> a[i].y;
    for(int i = 0; i < n; ++i) cin >> a[i].x;
    auto b = a;
    sort(all(b));

    ll ans = 0;
    for(int i = 0; i < n; i++) ans += abs(b[i].y - a[i].y);
    cout << ans << '\n';
  };

  ints(tc);
  for(int i = 1; i <= tc; i++) {
    cout << "Case #" << i << '\n';
    solve();
  }

  return 0;
}