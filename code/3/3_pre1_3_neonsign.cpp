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

  int k = n * m;
  vint p(4 * k);
  iota(all(p), 0);
  auto idx = [&](int x, int y){ return x * m + y; };
  function<int(int)> f = [&](int x){ return p[x] = (x == p[x] ? x : f(p[x])); };
  auto u = [&](int x, int y){ p[f(y)] = f(x); };

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      int x, y, z;
      cin >> x >> y >> z;
      y = idx(i, y);
      z = idx(z, j) + k;
      if(x) {
        u(y, z);
        u(y + 2 * k, z + 2 * k);
      } else {
        u(y, z + 2 * k);
        u(y + 2 * k, z);
      }
    }
  }

  ostringstream sout;
  vint vis(4 * k, 0);
  for(int t = 0; t < 2; t++) {
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        int x = idx(i, j) + t * k;
        int nx = x + 2 * k;
        
        if(f(x) == f(nx)) {
          cout << "Impossible\n";
          return;
        }

        if(!vis[f(x)] && !vis[f(nx)]) vis[f(x)] = -1;
        if(!vis[f(x)]) vis[f(x)] = -vis[f(nx)];
        if(!vis[f(nx)]) vis[f(nx)] = -vis[f(x)];
        
        if(vis[f(x)] > 0) {
          if(t == 0) sout << 'R' << (i / 10) << (i % 10) << (j / 10) << (j % 10) << ' ';
          else sout << 'C' << (j / 10) << (j % 10) << (i / 10) << (i % 10) << ' ';
        }
      }
    }
  }
  cout << sout.str() << '\n';
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