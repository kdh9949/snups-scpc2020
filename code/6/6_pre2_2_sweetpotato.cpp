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
  ll m;
  cin >> n >> m;

  vll a(n + 1);
  for(int i = 1; i <= n; i++) cin >> a[i];

  ll cur = 0, ans = 0;
  set<ll> s;
  for(int i = 1; i <= n; i++) {
    s.insert(cur);
    cur += a[i];
    auto it = s.lower_bound(cur - m);
    if(it != s.end()) ans = max(ans, cur - *it);
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