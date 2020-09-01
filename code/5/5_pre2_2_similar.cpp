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

  vint a(n), b(n);
  for(int &x : a) cin >> x;
  for(int &x : b) cin >> x;

  int bas = 0;
  for(int i = 0; i < n; i++) if(a[i] == b[i]) bas++;

  int ans = 0;
  for(int i = 0; i < n; i++) {
    int cur = 0;
    for(int s = i - 1, e = i + 1; 0 <= s && e < n; s--, e++) {
      cur += (a[s] == b[e]) + (a[e] == b[s]) - (a[s] == b[s]) - (a[e] == b[e]);
      ans = max(ans, cur);
    }
    cur = 0;
    for(int s = i, e = i + 1; 0 <= s && e < n; s--, e++) {
      cur += (a[s] == b[e]) + (a[e] == b[s]) - (a[s] == b[s]) - (a[e] == b[e]);
      ans = max(ans, cur);
    }
  }

  cout << (bas + ans) << '\n';
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