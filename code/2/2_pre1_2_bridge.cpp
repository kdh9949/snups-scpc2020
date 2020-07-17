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

const int N = 50005, K = 105, M = int(1e9) + 9;
vector<vint> d(N, vint(K));
vint s(N);

void solve() {
  int n, k, m;
  cin >> n >> k >> m;

  vint v(n + 1, 0);
  for(int i = 0; i < m; i++) {
    int x;
    cin >> x;
    v[x] = 1;
  }

  d[0][0] = s[0] = 1;
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    s[i] = 0;
    for(int j = 1; j <= i && j <= k; j++) {
      if(v[i]) d[i][j] = 0;
      else d[i][j] = (s[i - j] - d[i - j][j] + M) % M;
      s[i] = (s[i] + d[i][j]) % M;
      if(i == n) ans = (ans + d[i][j]) % M;
    }
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