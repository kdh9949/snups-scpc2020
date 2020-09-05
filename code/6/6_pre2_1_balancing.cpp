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

  vll a(n), b(n);
  for(ll &x : a) cin >> x;
  for(ll &x : b) cin >> x;
  sort(all(a));
  sort(all(b));
  a.insert(a.begin(), 0LL);
  b.insert(b.begin(), 0LL);

  if(n == 1) { cout << "0\n"; return; }

  vector<vll> d(4, vll(n + 1));
  d[0][1] = abs(a[1] - b[1]);
  d[1][1] = d[2][1] = d[3][1] = ll(1e18);
  for(int i = 2; i <= n; i++) {
    d[0][i] = d[0][i - 1] + abs(a[i] - b[i]);
    d[1][i] = min(d[1][i - 1], d[0][i - 2]) + abs(a[i] - b[i - 1]);
    d[2][i] = min(d[2][i - 1], d[0][i - 2]) + abs(a[i - 1] - b[i]);
    d[3][i] = min({d[0][i - 2], d[1][i - 1], d[2][i - 1], d[3][i - 1]}) + abs(a[i] - b[i]);
  }

  cout << min({d[0][n - 1], d[1][n], d[2][n], d[3][n]}) << '\n';
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