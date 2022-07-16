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
    map<int, int> xc, yc;
    for(pii &p : a) {
      cin >> p.x >> p.y;
      xc[p.x] ^= 1;
      yc[p.y] ^= 1;
    }
    for(int i = 0; i < n; i++) if(xc[a[i].x] && yc[a[i].y]) {
      --n;
      a.erase(a.begin() + i);
      break;    
    }
    ll ans = 0;
    sort(all(a));
    for(int i = 0; i < n; i += 2) ans += a[i + 1].y - a[i].y;
    for(pii &p : a) swap(p.x, p.y);
    sort(all(a));
    for(int i = 0; i < n; i += 2) ans += a[i + 1].y - a[i].y;
    cout << ans << '\n';
  };

  ints(tc);
  for(int i = 1; i <= tc; i++) {
    cout << "Case #" << i << '\n';
    solve();
  }

  return 0;
}