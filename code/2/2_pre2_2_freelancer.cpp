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

  vint a(n + 1), b(n + 1);
  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 1; i <= n; i++) cin >> b[i];

  vint d(n + 1);
  d[1] = max(a[1], b[1]);
  for(int i = 2; i <= n; i++) {
    d[i] = d[i - 1] + a[i];
    d[i] = max(d[i], d[i - 2] + b[i]);
  }
  cout << d[n] << '\n';
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