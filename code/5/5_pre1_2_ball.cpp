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
  int s, e, n;
  ld r;
  cin >> r >> s >> e >> n;

  ld ans = e - s;
  const static ld PI = 3.14159265358979323846264;
  for(int i = 0; i < n; i++) {
    ld x, y, h;
    cin >> x >> y >> h;
    if(h < r) {
      ans += 2 * acos(1 - h / r) * r - 2 * sqrt(2 * r * h - h * h);
    }
    else {
      ans += 2 * (h - r) + r * PI - 2 * r;
    }
  }
  cout << ans << '\n';
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