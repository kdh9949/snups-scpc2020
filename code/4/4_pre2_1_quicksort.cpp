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
  
  vint a(n + 1);
  for(int i = 1; i <= n; i++) cin >> a[i];

  vint p(n + 1), s(n + 2);
  for(int i = 1; i <= n; i++) p[i] = max(p[i - 1], a[i]);
  s[n + 1] = int(2e9);
  for(int i = n; i >= 1; i--) s[i] = min(s[i + 1], a[i]);
  
  int r = 0;
  for(int i = 1; i <= n; i++) r += (p[i - 1] < a[i] && a[i] < s[i + 1]);
  cout << r << '\n';
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