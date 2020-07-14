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

  vector<string> b(n);
  for(string &s : b) cin >> s;

  const static int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
  const static int ndir[3][4] = {
    {0, 1, 2, 3},
    {3, 2, 1, 0},
    {1, 0, 3, 2}
  };

  vector<vint> vis(n, vint(n, 0));
  for(
    int x = 0, y = 0, d = 1;
    0 <= x && x < n && 0 <= y && y < n;
    x += dx[d], y += dy[d]
  ) {
    vis[x][y] = 1;
    d = ndir[b[x][y] - '0'][d];
  }

  int ans = 0;
  for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) {
    if(b[i][j] != '0') ans += vis[i][j];
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
