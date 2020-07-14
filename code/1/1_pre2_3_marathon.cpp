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

const int N = 105, K = 15;
int a[N][N], b[N][N], d[N][N][K];

void solve() {
  int n, m, k;
  cin >> m >> n >> k;
  for(int i = 0; i <= n; i++) for(int j = 0; j <= m; j++) {
    cin >> a[i][j];
    b[i][j] = (a[i][j] < 0);
    a[i][j] = abs(a[i][j]);
  }

  auto upd = [&](int &x, int v) { x = min(x, v); };
  memset(d, 0x3f, sizeof(d));
  d[0][0][0] = 0;
  for(int i = 0; i <= n; i++) {
    for(int j = 0; j <= m; j++) {
      for(int t = 0; t <= k; t++) {
        if(i < n) upd(d[i + 1][j][min(k, t + b[i + 1][j])],
                      d[i][j][t] + abs(a[i][j] - a[i + 1][j]));
        if(j < m) upd(d[i][j + 1][min(k, t + b[i][j + 1])],
                      d[i][j][t] + abs(a[i][j] - a[i][j + 1]));
      }
    }
  }
  cout << d[n][m][k] << '\n';
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
