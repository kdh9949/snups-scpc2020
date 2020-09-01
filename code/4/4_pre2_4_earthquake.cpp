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
  int n, m, k;
  cin >> n >> m >> k;

  vint a(n), b(m);
  for(int &x : a) cin >> x;
  for(int &x : b) cin >> x;

  vint c(m);
  iota(all(c), 0);
  sort(all(c), [&](int x, int y){ return b[x] < b[y]; });

  int ans = 0;
  vint d(m + 1);
  const static int INF = int(1e9);
  for(int i = 0; i + m <= n; i++) {
    fill(all(d), INF);
    d[0] = -INF;
    for (int j = 0; j < m; j++)
      *lower_bound(all(d), a[i + c[j]]) = a[i + c[j]];
    if(d[m - k] < INF) ans++;
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