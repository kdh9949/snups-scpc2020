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

void solve() {
  int n;
  cin >> n;

  vector<pair<pii, pii>> v(n);
  for(auto &p : v) {
    cin >> p.x.x >> p.x.y >> p.y.x >> p.y.y;
    p.x.x *= 2; p.x.y *= 2; p.y.x *= 2; p.y.y *= 2;
    if(p.x > p.y) swap(p.x, p.y);
  }

  auto f = [&](ll x) {
    vint xs, ys;
    vector<pair<pii, pii>> rect;
    auto makerect = [&](pii a, pii b) {
      rect.emplace_back(a, b);
      xs.push_back(a.x);
      xs.push_back(b.x);
      ys.push_back(a.y);
      ys.push_back(b.y);
    };
    for(auto &p : v){
      if(abs(p.x.x - p.y.x) + abs(p.x.y - p.y.y) <= 2 * x) {
        makerect(pii(p.x.x - x, p.x.y - x), pii(p.y.x + x, p.y.y + x));
      } else {
        makerect(pii(p.x.x - x, p.x.y - x), pii(p.x.x + x, p.x.y + x));
        makerect(pii(p.y.x - x, p.y.y - x), pii(p.y.x + x, p.y.y + x));
      }
    }
    sort(all(xs));
    sort(all(ys));

    vector<vint> d(xs.size() + 1, vint(ys.size() + 1, 0));
    auto cp = [](vint &v, ll x) {
      return int(lower_bound(all(v), x) - v.begin());
    };
    for(auto &r : rect) {
      int xl = cp(xs, r.x.x), xr = cp(xs, r.y.x);
      int yl = cp(ys, r.x.y), yr = cp(ys, r.y.y);
      d[xl][yl]++;
      d[xl][yr + 1]--;
      d[xr + 1][yl]--;
      d[xr + 1][yr + 1]++;
    }

    for(int i = 0; i < xs.size(); i++) for(int j = 1; j < ys.size(); j++)
      d[i][j] += d[i][j - 1];
    for(int j = 0; j < ys.size(); j++) for(int i = 1; i < xs.size(); i++)
      d[i][j] += d[i - 1][j];
    for(vint &v : d) if(*max_element(all(v)) == n) return 1;
    return 0;
  };

  ll l = 0, r = int(2.1e8);
  while(l < r) {
    ll m = (l + r) / 2;
    if(f(m)) r = m;
    else l = m + 1;
  }
  if(l % 2 == 0) cout << l / 2 << '\n';
  else cout << l / 2 << ".5\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;
  for(int i = 1; i <= tc; i++) {
    cout << "Case #" << i << "\n";
    solve();
  }

  return 0;
}
