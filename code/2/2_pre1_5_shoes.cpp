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

const int T = 100, N = 305;

namespace Flow {
  struct Edge { int x, cap, rev; };
  vector<vector<Edge>> e(N);
  vint v(N);
  int n, snk;

  void init(int n_) {
    n = n_;
    for(int i = 0; i < n; i++) e[i].clear();
  }

  void add(int x, int y, int c) { 
    e[x].push_back({y, c, e[y].size()});
    e[y].push_back({x, 0, int(e[x].size()) - 1});
  }

  int dfs(int x, int c) {
    v[x] = 1;
    if(x == snk) return c;
    for(Edge &i : e[x]) {
      if(v[i.x] || !i.cap) continue;
      int cur = dfs(i.x, min(i.cap, c));
      if(cur > 0) {
        i.cap -= cur;
        e[i.x][i.rev].cap += cur;
        return cur;
      }
    }
    return 0;
  }

  int get(int s, int t) {
    snk = t;
    int ans = 0;
    while(true) {
      fill(all(v), 0);
      int cur = dfs(s, int(1e9));
      if(!cur) break;
      ans += cur;
    }
    return ans;
  }
}

void solve() {
  int n, k;
  cin >> n >> k;
  Flow::init(T + n + 2);

  int psum = 0;
  for(int i = 0; i < n; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    psum += z;
    Flow::add(T + n, T + i, z);
    for(; x < y; x++) Flow::add(T + i, x, 1);
  }

  vint m(T, 0);
  for(int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    for(; x < y; x++) m[x]++;
  }
  for(int i = 0; i < T; i++) Flow::add(i, T + n + 1, m[i]);

  cout << (Flow::get(T + n, T + n + 1) == psum) << '\n';
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