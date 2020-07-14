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

  vpii v(n);
  for(auto &p : v) {
    cin >> p.x >> p.y;
    p.x *= -1;
  }
  sort(all(v));

  vint d(n + 1, int(1e9));
  d[0] = -int(1e9);
  for(auto &p : v) {
    *upper_bound(all(d), p.y) = p.y;
  }

  cout << int(lower_bound(all(d), int(1e9)) - d.begin() - 1) << '\n';
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
