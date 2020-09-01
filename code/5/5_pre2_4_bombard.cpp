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
  int n, m;
  cin >> n >> m;

  vector<string> b(n + 2);
  b[0] = b[n + 1] = string("0", m + 2);
  for(int i = 1; i <= n; i++) {
    cin >> b[i];
    b[i] = "0" + b[i] + "0";
  }

  vpii ans;
  auto cnt = [&](int x, int y) {
    if(x <= 0 || y <= 0) return -1;
    int r = 0;
    for(int i = 0; i < 3; i++) for(int j = 0; j < 3; j++)
      if(b[x + i][y + j] == '1') r++;
    return r;
  };
  auto bomb = [&](int x, int y) {
    ans.emplace_back(x, y);
    for(int i = 0; i < 3; i++) for(int j = 0; j < 3; j++)
      b[x + i][y + j] = '0';
  };

  for(int i = 1; i <= n - 3; i++) {
    for(int j = 1; j <= m - 3; j++) {
      if(b[i][j] == '1') {
        int c[3] = {cnt(i, j - 2), cnt(i, j - 1), cnt(i, j)};
        int mx = max({c[0], c[1], c[2]});
        if(mx == c[0]) bomb(i, j - 2);
        else if(mx == c[1]) bomb(i, j - 1);
        else bomb(i, j);
      }
    }
  }
  for(int i = 1; i <= n - 3; i++) {
    if(b[i][m - 2] + b[i][m - 1] + b[i][m] > 3 * '0') bomb(i, m - 2);
  }
  for(int i = 1; i <= m - 3; i++) {
    if(b[n - 2][i] + b[n - 1][i] + b[n][i] > 3 * '0') bomb(n - 2, i);
  }
  if(cnt(n - 2, m - 2)) bomb(n - 2, m - 2);

  cout << ans.size() << '\n';
  for(pii &p : ans) cout << p.x << ' ' << p.y << '\n';
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