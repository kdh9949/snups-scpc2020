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

  vpii a(n);
  for(pii &p : a) cin >> p.x >> p.x >> p.y;
  sort(all(a));
  a.insert(a.begin(), pii(0, 0));

  vector<vint> d(2, vint(n + 2));
  const static int INF = int(1.05e9);
  d[0][0] = -INF;
  d[0][1] = INF;
  for(int i = 1; i <= n; i++) {
    vint &cd = d[i & 1], &pd = d[~i & 1];
    cd[0] = -INF;
    for(int j = 1; j <= i; j++) {
      cd[j] = min(
        pd[j] + a[i].y,
        (pd[j - 1] <= a[i].x ? max(a[i].x, pd[j - 1] + a[i].y) : INF)
      );
    }
    cd[i + 1] = INF;
  }

  int r = 0;
  for(r = 0; d[n & 1][r + 1] < INF; r++);
  cout << n - r << '\n';
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