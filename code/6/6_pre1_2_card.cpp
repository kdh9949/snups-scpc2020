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

const int N = 3005;
int d[N][N], rs[N][N], cs[N][N];

void solve() {
  int n, k;
  cin >> n >> k;

  for(int i = 0; i <= n; i++) {
    fill(d[i], d[i] + n + 1, 0);
    fill(rs[i], rs[i] + n + 1, 0);
    fill(cs[i], cs[i] + n + 1, 0);
  }

  vint a(n + 1), b(n + 1);
  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 1; i <= n; i++) cin >> b[i];

  vint al(n + 1), bl(n + 1);
  for(int i = 1; i <= n; i++) {
    al[i] = bl[i] = i;
    int s = 0;
    for(int s = 0; al[i] >= 0 && s <= k; s += a[al[i]--]);
    for(int s = 0; bl[i] >= 0 && s <= k; s += b[bl[i]--]);
  }

  int awin = 0, bwin = 0;
  for(int i = 0; i <= n; i++) for(int j = 0; j <= n; j++) {
    if(i && cs[i - 1][j] - (al[i] < 0 ? 0 : cs[al[i]][j]) < i - 1 - al[i]) d[i][j] = 1;
    if(j && rs[i][j - 1] - (bl[j] < 0 ? 0 : rs[i][bl[j]]) < j - 1 - bl[j]) d[i][j] = 1;
    if(i + j == 0) d[i][j] = 1;
    (d[i][j] ? awin : bwin)++;
    rs[i][j] = (j ? rs[i][j - 1] : 0) + d[i][j];
    cs[i][j] = (i ? cs[i - 1][j] : 0) + d[i][j];
  }

  cout << awin << ' ' << bwin << '\n';
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