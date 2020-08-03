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

const int N = 2505;

namespace MCMF {
  struct Edge { int x, cap; ll cost; int rev; };
  int n;
  vector<Edge> e[N];

  void init(int n_) {
    n = n_;
  }
  void clear() {
    for(int i = 1; i <= n; i++) e[i].clear();
  }
  void add(int x, int y, int cap, ll cost) {
    e[x].push_back({y, cap, cost, e[y].size()});
    e[y].push_back({x, 0, -cost, int(e[x].size()) - 1});
  }

  ll d[N];
  int prv[N], pi[N], inq[N];
  const ll INF = ll(1e18);

  int spfa(int s, int t) {
    fill(d + 1, d + n + 1, INF);
    queue<int> q;
    
    d[s] = 0;
    q.push(s);
    inq[s] = 1;
    
    while(!q.empty()) {
      int x = q.front();
      q.pop();
      inq[x] = 0;
      for(int j = 0; j < e[x].size(); j++) {
        auto &i = e[x][j];
        if(!i.cap) continue;
        if(d[i.x] > d[x] + i.cost) {
          d[i.x] = d[x] + i.cost;
          prv[i.x] = x;
          pi[i.x] = j;
          if(!inq[i.x]) {
            q.push(i.x);
            inq[i.x] = 1;
          }
        }
      }
    }

    return (d[t] != INF);
  }

  ll flow(int s, int t) {
    int inc = int(1e9);
    for(int x = t; x != s; x = prv[x]) {
      inc = min(inc, e[prv[x]][pi[x]].cap);
    }

    ll ret = 0;
    for(int x = t; x != s; x = prv[x]) {
      auto &ce = e[prv[x]][pi[x]];
      ce.cap -= inc;
      e[x][ce.rev].cap += inc;
      ret += inc * ce.cost;
    }

    return ret;
  }

  ll get(int s, int t) {
    ll ans = 0;
    while(spfa(s, t)) ans += flow(s, t);
    return ans;
  }
}

void solve() {
  int n, m;
  cin >> n >> m;

  vector<vpil> e(m + 1);
  for(int i = 0; i < m - 1; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    e[x].emplace_back(y, z);
    e[y].emplace_back(x, z);
  }

  ll ans = 0;
  for(int r = 1; r <= n + 1; r += n) {
    MCMF::init(m + n + 2);

    function<void(int, int)> f = [&](int x, int y){
      for(pil &i : e[x]) {
        if(i.x == y) continue;
        MCMF::add(i.x, x, 1, -i.y);
        f(i.x, x);
      }
    };
    f(r, 0);
    
    for(int i = 2; i <= n; i++) {
      MCMF::add(m + n + 1, m + i, 1, 0);
      MCMF::add(m + i, i, 1, 0);
      MCMF::add(m + i, n + i, 1, 0);
    }
    for(int i = 1; i <= m; i++) {
      MCMF::add(i, m + n + 2, n, 0);
    }

    ans = max(ans, -MCMF::get(m + n + 1, m + n + 2));
    MCMF::clear();
  }
  cout << ans << '\n';
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