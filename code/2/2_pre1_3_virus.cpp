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
  int k, l, n, m;
  cin >> k >> l >> n >> m;

  vector<set<int>> e(n + 1);
  for(int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    e[x].insert(y);
    e[y].insert(x);
  }

  int sz = n, ans = 0;
  vector<int> chk(n + 1, 0);
  while(true) {
    int x = 0;
    for(int i = 1; i <= n; i++) {
      if(chk[i]) continue;
      int deg = e[i].size();
      if(deg < k || deg >= sz - l) { x = i; break; }
    }
    if(!x) break;
    ans += x;
    chk[x] = 1;
    sz--;
    for(int y : e[x]) e[y].erase(x);
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