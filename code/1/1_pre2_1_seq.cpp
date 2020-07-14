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

  vll v(n);
  for(ll &x : v) cin >> x;

  if(v[0] == v[n - 1]) {
    cout << "1\n";
    return;
  }

  ll g = 0;
  for(int i = 1; i < n; i++) {
    if(v[i] == v[i - 1]) { g = -1; break; }
    g = gcd(g, v[i] - v[i - 1]);
  }

  int ans = 0;
  for(ll i = 1; i * i <= g; i++) {
    if(g % i == 0) ans += 1 + (i * i != g);
  }
  cout << ans << '\n';
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
